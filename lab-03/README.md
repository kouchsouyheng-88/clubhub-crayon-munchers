# Lab-03 · Record of what changed

| File | Task | Status |
|------|------|--------|
| lab-03/data-inventory.md | 1 | new |
| lab-03/privacy-notice.md | 2 | new |
| lab-03/consent-flow.mmd | 2 | new |
| lab-03/retention-rules.md | 2 | new |
| include/clubhub/Student.h | 2 | new |
| src/Student.cpp | 2 | new |
| tests/StudentPrivacyTest.cpp
| CMakeLists.txt | 2 | changed (added library src/Student.cpp, src/ConsoleTest.cpp, GoogleTest), tests |  | 2 | new |
| LICENSE | 3 | new |
| src/ConsoleOutputTest.cpp| 4 | new |
| ethics-cases.md | 5 | new |
| README.md | 5 | new |



## Inputs reused
| Input | File | Version / commit |
|-------|------|------------------|
| Team charter | lab01/team-charter.md | 1.0/ e6a0ea5 |
| Application type | lab02/adr-001-application-type.md | 1.0/ 7b23abf |

## Change log
| Date | Change | Author |
|------|--------|--------|
| 2026-11-10 | Lab-03: inventory, notice, Student, licence, a11y, ethics, AI proposal | team Crayon Munchers |

## Open questions for the client
- How long should the clubs office keep a student's information (ID, name, email) after graduation: 6 months, 1 year, or until the student asks us to delete it?
- Should club leaders ever see which students attended other clubs' events?
- Should a cancellation inside the 24-hour window be blocked, or allowed with a warning?
- Is the SMS reminder required in the first release, or optional?
- Is it acceptable to delete the phone number 6 months after graduation, or right away when the student withdraws consent?