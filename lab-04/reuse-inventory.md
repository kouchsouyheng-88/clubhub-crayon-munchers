# Reuse inventory · Team Crayon_Munchers· v1.0 

Repository licence (Lab-03): MIT

## Make-or-reuse table

| Need | Options considered | Decision | Reason | Licence | Pinned version | Last release |
|------|--------------------|----------|--------|---------|----------------|--------------|
| Unit testing | GoogleTest, Catch2 | Reuse | Standard C++ test framework, works with CTest and CI | BSD-3-Clause | v1.17.0 | 11 Aug 2026(v1.18.0) |
| CSV file storage | rapidcsv, write our own parser | Reuse | Lab-02 chose CSV; a ready reader saves time and avoids parsing bugs | BSD-3-Clause | v8.84 | 21 Aug 2026(v9.09) |
| Registration rules | none fits our rules | Build | Unique to Club Hub, graded, must be tested | MIT | - | - |
| Date and time (24-hour rule) | std::chrono, date library | Reuse | Already part of C++20, nothing to download | C++ standard library | C++20 | - |
| CLI input handling | CLI11, std::cin and std::getline | Build | Our menu is simple, a library is more than we need now | MIT | - | - |
| Reminders | own function, OS scheduler | Defer | Not a Must feature, decide after Sprint 1 | - | - | - |
| Monthly report | own code over CSV data, spreadsheet export | Defer | Needs attendance data first, planned for Sprint 2 | - | - | - |
| Logging | spdlog, std::clog | Defer | std::clog is enough at first, revisit later | - | - | - |



## Licence check

| Library | Licence | Compatible with our MIT repository? | Why |
|---------|---------|-------------------------------------|-----|
| GoogleTest | BSD-3-Clause | Yes | Permissive: we may use and redistribute it if we keep its copyright notice |
| rapidcsv | BSD-3-Clause | Yes |  Permissive: we may use and redistribute it if we keep its copyright notice |

A GPL library would require us to release our whole program under GPL as well if we include its code. That conflicts with our MIT licence, so we avoid GPL libraries unless the team decides to change the licence.

## Maintenance evidence

- GoogleTest: v1.18.0 (11 Aug 2026), issues are answered: TODO yes/no
- rapidcsv: v9.09 (21 Aug 2026), issues are answered: TODO yes/no

## Verification

- Compiler: TODO (output of `g++ --version`)
- CMake: TODO (output of `cmake --version`)

Command, run from a clean `build/` folder:

```
cmake -S . -B build && cmake --build build && ctest --test-dir build --output-on-failure
```

Output:

```
TODO paste your real CTest output here
```