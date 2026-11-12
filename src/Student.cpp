// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Crayon Munchers, ITC Club Hub contributors

// src/Student.cpp
#include "clubhub/Student.h"
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <utility>

namespace clubhub {

std::string maskId(std::string_view id) {
    if (id.length() <= 3) return std::string(id.length(), '*');
    // e.g. "e20990417" -> "e2******7"
    return std::string(id.substr(0, 2)) +
           std::string(id.length() - 3, '*') +
           id.back();
}

Student::Student(std::string id, std::string name, std::string email)
    : id_(std::move(id)), name_(std::move(name)), email_(std::move(email)) {
    if (id_.empty()) {
        throw std::invalid_argument("Student ID cannot be empty");
    }
    if (name_.empty()) {
        throw std::invalid_argument("Student Name cannot be empty");
    }
    if (email_.find('@') == std::string::npos) {
        throw std::invalid_argument("Email must contain '@'");
    }
}

void Student::giveSmsConsent(std::string phone) {
    const bool ok = !phone.empty() &&
        std::all_of(phone.begin(), phone.end(), [](unsigned char c) {
            return std::isdigit(c) || c == '+' || c == ' ';
        });
    if (!ok) {
        throw std::invalid_argument("phone may only contain digits, + and spaces");
    }
    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept {
    phone_.reset();
}

std::string Student::redacted() const {
    return "Student{id=" + maskId(id_) + "}";
}

} // namespace clubhub
