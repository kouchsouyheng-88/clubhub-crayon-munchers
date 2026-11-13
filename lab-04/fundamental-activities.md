# Fundamental activities · Team Crayon Munchers · v1.0 (2026-11-13)

| Activity | What happens in Club Hub | Who leads (role, name) | Weeks | Artifact | Done when |
|----------|--------------------------|------------------------|-------|----------|-----------|
| Specification | Elicit stories for browsing approved clubs' events, registering and cancelling, write acceptance criteria for capacity, no duplicate registration and the 24-hour cancellation deadline. | Product Owner, Ung Phearakleap | 5–6, revisit 11 after Sprint 1 feedback | `lab05/srs.md` (planned) | The SRS records each rule with testable acceptance criteria, and the TA's review decisions are recorded in the repository. |
| Design and implementation | Define the `RegistrationService` and `EventService` interfaces and their CSV repository boundaries, implement event browsing, registration and cancellation in the C++ core and CLI. | Scrum Master, Buntong Anupheap | 7–14 (Sprint 1 and Sprint 2) | `lab-02/architecture.mmd`, `include/clubhub/`, `src/` | The C++ project builds without warnings and the CLI demonstrates the agreed Must stories from the SRS. |
| Validation | Review the SRS with the TA and inspect the week-8 checkpoint, add GoogleTest cases for capacity, duplicate registration, the 24-hour deadline and seat release, then review pull requests and demo at each sprint review. | Dev-Ops (shared hat), Ou Pechly | 6, 8, 9–14 | `tests/` | Every implemented Must story has passing automated tests, and review notes record the TA's acceptance or requested corrections. |
| Evolution | Record requests from the Sprint 1 review, such as showing seats left beside each event, assess their effect on the event list and registration rules, then change the code and regression tests in Sprint 2. | Product Owner, Ung Phearakleap | 10–15 | `CHANGELOG.md` (planned), `tests/` | Each accepted post-review change has a dated change-log entry, updated acceptance criteria and passing regression tests. |

## Sub-activities and ISO/IEC/IEEE 12207 processes

- **Specification:** stakeholder elicitation, rule analysis, SRS specification, requirements validation with the TA. **12207:** Stakeholder needs and requirements definition, System requirements definition.
- **Design and implementation:** architecture design, detailed service and CSV interface design, C++ coding, CLI integration. **12207:** Architecture definition, Implementation.
- **Validation:** requirements review, checkpoint inspection, automated unit and integration testing, sprint acceptance review. **12207:** Verification, Validation.
- **Evolution:** review-feedback triage, change impact analysis, corrective or feature implementation, regression testing. **12207:** Maintenance, System analysis.

## Overlaps and loops

1. **Week 8 → week 9:** The checkpoint review may reveal that the cancellation boundary is unclear. The Product Owner clarifies the 24-hour rule in `lab05/srs.md`, the developer adjusts the service design and tests before Sprint 1 code is accepted.
2. **Week 10 → week 11:** If the Sprint 1 review requests seats left in the event list, the Product Owner records that request in `lab09/review-notes.md` and writes its story and acceptance criteria in `lab05/srs.md` in week 11. Design, implementation and validation then repeat in Sprint 2.
3. **Weeks 9–14:** Design and validation overlap on each pull request: a change to registration or cancellation includes its GoogleTest cases and a peer review before merge. A failed test returns the change to implementation, followed by another test run.