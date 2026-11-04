#include "clubhub/event_csv.hpp"

#include <charconv>
#include <sstream>
#include <stdexcept>

namespace clubhub {

namespace {

// Split a line at ',' into fields. A line ending in a comma gets one more,
// empty field (std::getline alone would drop it).
std::vector<std::string> splitFields(const std::string& line) {
    std::vector<std::string> fields;
    std::istringstream in{line};
    std::string field;
    while (std::getline(in, field, ',')) {
        fields.push_back(field);
    }
    if (!line.empty() && line.back() == ',') {
        fields.emplace_back();
    }
    return fields;
}

// std::from_chars reports errors instead of throwing; we turn them into
// std::invalid_argument with a clear message.
int parseInt(const std::string& text) {
    int value{};
    const char* first = text.data();
    const char* last = text.data() + text.size();
    const auto [ptr, ec] = std::from_chars(first, last, value);
    if (text.empty() || ec != std::errc{} || ptr != last) {
        throw std::invalid_argument{"bad number '" + text + "'"};
    }
    return value;
}

} // namespace

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;
    std::getline(in, line); // skip the header
    while (std::getline(in, line)) {
        ++lineNo;
        // Files edited on Windows end lines with "\r\n".
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (line.empty()) {
            continue; // blank lines (for example at the end) are not errors
        }
        const auto fields = splitFields(line);
        if (fields.size() != 5) {
            result.errors.push_back(
                {lineNo, "expected 5 fields, found " + std::to_string(fields.size())});
            continue;
        }
        try {
            result.events.emplace_back(fields[0], fields[1],
                                       parseTimePoint(fields[2]), fields[3],
                                       parseInt(fields[4]));
        } catch (const std::invalid_argument& e) {
            result.errors.push_back({lineNo, e.what()});
        }
    }
    return result;
}

} // namespace clubhub