// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Crayon Munchers, ITC Club Hub contributors

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "clubhub/event.hpp"
#include "clubhub/event_csv.hpp"

namespace {

int listEvents(const std::string& path) {
    std::ifstream file{path};
    if (!file) {
        std::cerr << "error: cannot open " << path << '\n';
        return 2;
    }
    auto [events, errors] = clubhub::loadEventsCsv(file);
    std::ranges::sort(events, {}, &clubhub::Event::start);


    std::size_t titleWidth = std::string{"TITLE"}.size();
    std::size_t locationWidth = std::string{"LOCATION"}.size();
    for (const auto& e : events) {
        titleWidth = std::max(titleWidth, e.title().size());
        locationWidth = std::max(locationWidth, e.location().size());
    }
    constexpr int startWidth = 16 + 2;
    const int tw = static_cast<int>(titleWidth) + 2;
    const int lw = static_cast<int>(locationWidth) + 2;

    std::cout << std::left << std::setw(startWidth) << "START"
              << std::setw(tw) << "TITLE" << std::setw(lw) << "LOCATION"
              << "CAPACITY\n";
    for (const auto& e : events) {
        std::cout << std::left << std::setw(startWidth)
                  << clubhub::formatTimePoint(e.start()) << std::setw(tw)
                  << e.title() << std::setw(lw) << e.location()
                  << e.capacity() << '\n';
    }
    std::cout << events.size() << " event(s)\n";
    for (const auto& err : errors) {
        std::cerr << path << ':' << err.line << ": skipped: " << err.message
                  << '\n';
    }
    return errors.empty() ? 0 : 1;
}

void printUsage() {
    std::cerr << "usage: clubhub list-events [events.csv]\n";
}

} // namespace

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 2;
    }
    const std::string command{argv[1]};
    if (command == "list-events") {
        return listEvents(argc > 2 ? argv[2] : "data/events.csv");
    }
    std::cerr << "unknown command: " << command << '\n';
    printUsage();
    return 2;
}