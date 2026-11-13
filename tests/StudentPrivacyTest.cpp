// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Crayon Munchers, ITC Club Hub contributors

// tests/StudentPrivacyTest.cpp
#include "clubhub/Student.h"

#include <gtest/gtest.h>

#include <stdexcept>

using clubhub::Student;

// Invented test data only: never real students.
TEST(StudentPrivacy, RedactedHidesPersonalData) {
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("012 345 678");
    const std::string r = s.redacted();
    EXPECT_EQ(r, "Student{id=e2******7}");
    EXPECT_EQ(r.find("Test"), std::string::npos);
    EXPECT_EQ(r.find("example.edu"), std::string::npos);
    EXPECT_EQ(r.find("345"), std::string::npos);
}

TEST(StudentPrivacy, OptionalConsentsStartOff) { 
    /* TODO */
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_FALSE(s.phone().has_value());
    EXPECT_FALSE(s.remindersByEmail());   
 }

TEST(StudentPrivacy, WithdrawingSmsConsentErasesPhone) { 
    /* TODO */
    Student s{"e20990417", "Test Student", "test@example.edu"};
    s.giveSmsConsent("012 345 678");
    EXPECT_TRUE(s.phone().has_value());
    s.withdrawSmsConsent();
    EXPECT_FALSE(s.phone().has_value());
 }

TEST(StudentPrivacy, RejectsEmailWithoutAt) {
    EXPECT_THROW((Student{"e20990417", "A", "no-at-sign"}),
                 std::invalid_argument);
}

TEST(StudentPrivacy, RejectsPhoneWithLetters) { 
    /* TODO */ 
    Student s{"e20990417", "Test Student", "test@example.edu"};
    EXPECT_THROW(s.giveSmsConsent("012 abc "), std::invalid_argument);
    EXPECT_FALSE(s.phone().has_value());

}
TEST(StudentPrivacy, MaskIdHidesShortIdsCompletely) { 
    /* TODO */
    EXPECT_EQ(clubhub::maskId("e20"),"***");
    EXPECT_EQ(clubhub::maskId("e20990417"), "e2******7");
 }