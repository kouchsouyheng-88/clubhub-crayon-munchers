# Lab-04 · Software Development Processes · Team Crayon Munchers

## Files of this lab
| File                             | Task | Description                                                                 |
|----------------------------------|------|-----------------------------------------------------------------------------|
| fundamental-activities.md        | 1    | The four activities (specification, design and implementation, validation, evolution) for Club Hub with leads, weeks, artifacts and ISO/IEC/IEEE 12207 processes |
| scores/*.md                      | 2    | Individual process scores, one file per member                              |
| process-comparison.md            | 2    | Team comparison of waterfall, incremental and Scrum-style with weights and weighted scores |
| process-decision.md, process.mmd | 3    | PDR-001 (Scrum-style iterative development) and the process diagram        |
| iteration-plan.md                | 4    | Gantt chart for weeks 5-14 and sprint goals                                 |
| reuse-inventory.md               | 5    | Make-or-reuse table, licence check, maintenance evidence and build verification |
| ../CMakeLists.txt                | 5    | FetchContent: googletest v1.17.0, rapidcsv v9.07                            |
| ../tests/csv_smoke_test.cpp, ../tests/data/events.csv | 5 | Smoke test that reads two events through rapidcsv |

## Inputs reused
| Input               | File                                | Version (commit) |
|---------------------|-------------------------------------|------------------|
| Team charter        | lab-01/team-charter.md              | e6a0ea5          |
| Problem statement   | lab-01/problem-statement.md         | fe103ce          |
| Application type    | lab-02/adr-001-application-type.md | 7b23abf          |
| Repository licence  | LICENSE                             | 3a810d4          |

## Dependencies added
| Library    | Version | Licence      | Used for                       | Fetched with                         |
|------------|---------|--------------|--------------------------------|--------------------------------------|
| GoogleTest | v1.17.0 | BSD-3-Clause | Unit tests and CTest discovery | FetchContent (release zip, pinned tag) |
| rapidcsv   | v9.07   | BSD-3-Clause | Reading the CSV event files    | FetchContent (git tag v9.07)         |

## Change log
| Date       | Change                                                                                                   | By               |
|------------|----------------------------------------------------------------------------------------------------------|------------------|
| 2026-11-17 | Lab-04 task 1: fundamental-activities.md finished    | Ung Phearakleap  |
| 2026-11-17 | Lab-04 task 2: process-comparison.md finished | Buntong Anupheap |
| 2026-11-17 | Lab-04 task 3: process-decision.md, process.mmd, and scores/UngPhearakleap.md completed | Ung Phearakleap |
| 2026-11-17 | Lab-04 task 3: scores/BungtongAnupheap.md completed | Buntong Anupheap |
| 2026-11-17 | Lab-04 task 3: scores/KouchSouyheng.md completed | Kouch Southeng |
| 2026-11-17 | Lab-04 task 3: scores/Ou-Pechly.md completed | Ou Pechly |
| 2026-11-17 | Lab-04 task 3: scores/YamSoksopheakna.md completed | Yam Soksopheakna |
| 2026-11-26 | Lab-04 task 4: interation-plan.md completed | Buntong Anupheap |
| 2026-11-26 | Lab-04 task 5: reuse-inventory.md completed | Kouch Souyheng |
| 2026-11-26 | Lab-04 task 5: CMakeLists modified, csv_smoke_test.cpp, events.csv, and README completed | Ung Phearakleap |

