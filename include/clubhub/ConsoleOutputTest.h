// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Crayon Munchers, ITC Club Hub contributors

// include/clubhub/ConsoleOutput.h
#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include <string>
#include <string_view>

namespace clubhub {

// Declare here only if your repository does not define it yet.
enum class RegistrationStatus { Registered, Cancelled, CheckedIn, Waitlisted };

// Upper-case word for a status: "REGISTERED", "CHECKED IN", ...
std::string_view statusLabel(RegistrationStatus s);

// false when the --no-color flag is set or NO_COLOR exists (no-color.org)
bool colourEnabled(bool noColorFlag);

// "[CANCELLED]", wrapped in ANSI colour codes only if colour is true
std::string formatStatus(RegistrationStatus s, bool colour);

// "Error: <what>: <why>.\nNext step: <next>"
std::string formatError(std::string_view what, std::string_view why,
                        std::string_view next);

}  // namespace clubhub

#endif