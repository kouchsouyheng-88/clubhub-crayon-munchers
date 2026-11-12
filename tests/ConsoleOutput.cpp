#include "clubhub/ConsoleOutput.h"

#include <gtest/gtest.h>

using namespace clubhub;

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    EXPECT_EQ(formatStatus(RegistrationStatus::Cancelled, false), "[CANCELLED]");
}

TEST(ConsoleOutput, ColourOnlyRepeatsTheWord) {
    const std::string s = formatStatus(RegistrationStatus::Cancelled, true);
    EXPECT_NE(s.find("CANCELLED"), std::string::npos);
    EXPECT_NE(s.find("\033["), std::string::npos);
}

TEST(ConsoleOutput, ErrorSaysWhatWhyAndNextStep) {
    const std::string e = formatError("cannot register for E-017","the event is full (40 of 40 seats)", "clubhub waitlist E-017");
    EXPECT_NE(e.find("Error:"), std::string::npos);
    EXPECT_NE(e.find("Next step:"), std::string::npos);
}