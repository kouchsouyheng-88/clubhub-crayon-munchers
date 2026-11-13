// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Crayon Munchers, ITC Club Hub contributors

#ifndef EVENT_CSV_HPP
#define EVENT_CSV_HPP

#include <istream>
#include <string>
#include <vector>

#include "clubhub/event.hpp"

namespace clubhub{
    struct CsvError{
        int line;
        std::string message;
    };

    struct EventLoadResult{
        std::vector<Event> events;
        std::vector<CsvError> errors;
    };

    EventLoadResult loadEventsCsv(std::istream& in);
}

#endif