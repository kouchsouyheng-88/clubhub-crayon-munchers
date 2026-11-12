// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Crayon Munchers, ITC Club Hub contributors

// src/main.cpp
#include <iostream>
using namespace std;

#include "clubhub/banner.hpp"

int main() {
    cout << clubhub::banner(clubhub::kTeamName);
    cout << "Commands arrive in a later lab. Bye!\n";
    return 0;
}