# Fundamental activities · Team Crayon Munchers · v1.0 (2026-11-13)

| Activity | What happens in Club Hub | Who leads (role, name) | Weeks | Artifact | Done when |
|----------|--------------------------|------------------------|-------|----------|-----------|
| Specification | Elicit stories for browsing approved clubs' events, registering and cancelling, write acceptance criteria for capacity, no duplicate registration and the 24-hour cancellation deadline. | Product Owner, Ung Phearakleap | 5–6, revisit 11 for recorded changes | `lab-01/problem-statement.md`, `lab-03/cli-output-rules.md` | The scope and business rules are written down, and each required behaviour has a testable acceptance criterion. |
| Design and implementation | Define the `RegistrationService` and `EventService` interfaces and their CSV repository boundaries, implement event browsing, registration and cancellation in the C++ core and CLI. | Scrum Master, Buntong Anupheap | 7–14 (Sprint 1 and Sprint 2) | `lab-02/architecture.mmd`, `include/clubhub/`, `src/` | The C++ project builds without warnings and the CLI demonstrates the agreed Must stories. |
| Validation | Review requirements with the TA and inspect the week-8 checkpoint, add GoogleTest cases for capacity, duplicate registration, the 24-hour deadline and seat release, then review pull requests and demo at each sprint review. | Developer, Ou Pechly | 6, 8, 9–14 | `tests/`, `lab-03/accessibility-checklist.md` | Every implemented Must story has passing automated tests, and the TA's review decision is recorded in the repository. |
| Evolution | Record actual change requests and defects from sprint reviews, assess their effect on the event list or registration rules, then update the affected C++ code and regression tests. | Product Owner, Ung Phearakleap | 10–15 | `src/Student.cpp`, `tests/StudentPrivacyTest.cpp` | Each accepted change is traceable to a repository revision and has passing regression tests. |

## Sub-activities and ISO/IEC/IEEE 12207 processes

- **Specification:** stakeholder elicitation, rule analysis, SRS specification, requirements validation with the TA. **12207:** Stakeholder needs and requirements definition, System requirements definition.
- **Design and implementation:** architecture design, detailed service and CSV interface design, C++ coding, CLI integration. **12207:** Architecture definition, Implementation.
- **Validation:** requirements review, checkpoint inspection, automated unit and integration testing, sprint acceptance review. **12207:** Verification, Validation.
- **Evolution:** review-feedback triage, change impact analysis, corrective or feature implementation, regression testing. **12207:** Maintenance, System analysis.

## Overlaps and loops

1. **November 11–12, 2026 — implementation ↔ validation:** The team moved privacy test code out of `src/Student.cpp` into `tests/StudentPrivacyTest.cpp` (`a151bab`), revised the tests (`642803b`), then fixed two test errors and added the `Student::giveSmsConsent` body (`8c44300`). This is a recorded loop from implementation to tests and back to implementation.
2. **November 12, 2026 — implementation + validation:** The team added console-output code and its tests together (`9c8e159`). A later commit renamed the files, changed `CMakeLists.txt` and revised the tests so the target could be built and tested (`990b48c`). This records the overlap of coding and testing, followed by a build-driven revision.