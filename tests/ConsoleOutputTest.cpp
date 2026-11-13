// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Crayon Munchers, ITC Club Hub contributors

#include "clubhub/ConsoleOutputTest.h"

#include <gtest/gtest.h>

using namespace clubhub;

TEST(ConsoleOutputTest, StatusIsReadableWithoutColour) {
    EXPECT_EQ(formatStatus(RegistrationStatus::Cancelled, false), "[CANCELLED]");
}

TEST(ConsoleOutputTest, ColourOnlyRepeatsTheWord) {
    const std::string s = formatStatus(RegistrationStatus::Cancelled, true);
    EXPECT_NE(s.find("CANCELLED"), std::string::npos);
    EXPECT_NE(s.find("\033["), std::string::npos);
}

TEST(ConsoleOutputTest, ErrorSaysWhatWhyAndNextStep) {
    const std::string e = formatError("cannot register for E-017","the event is full (40 of 40 seats)", "clubhub waitlist E-017");
    EXPECT_NE(e.find("Error:"), std::string::npos);
    EXPECT_NE(e.find("Next step:"), std::string::npos);
}