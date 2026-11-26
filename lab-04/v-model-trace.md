# V-model trace · Team Crayon Munchers

## Trace table

| Level | Left side (defines) | Right side (tests) |
|-------|---------------------|--------------------|
| Requirement ↔ acceptance | **REQ-12** as written above | **AT-12** (two Gherkin scenarios below, run by the client at the sprint review): cancel at 2026-11-06 14:00:00 → status "Cancelled", one seat free; cancel at 2026-11-06 14:00:01 → rejected with a message and exit code 1 |
| System specification ↔ system test | **SYS-12:** **clubhub cancel <student_id> <event_id> --now <YYYY-MM-DDTHH:MM:SS>** in **src/cli/main.cpp**. On success it prints **E001  Robotics Workshop  [CANCELLED]** and exits 0. If the deadline has passed it prints **Error: cannot cancel registration for E001: the event starts in less than 24 hours.** and **Next step: contact the club leader of C01.** and exits 1 (CLI output rules 3 and 4, Lab-03). The **--now** option exists so that tests can fix the clock | **ST-12a:** **clubhub cancel S001 E001 --now 2026-11-06T14:00:00** on a temporary copy of the data files → exit 0, output contains **[CANCELLED]**. **ST-12b:** same command with **--now 2026-11-06T14:00:01** → exit 1, output contains **cannot cancel** and **Next step:**, registration still **Registered** in the file |
| Architecture design ↔ integration test | **ARCH-12:** **RegistrationService::cancel(studentId, eventId, now)** in **src/** asks **canCancel** whether it may proceed, then asks **RegistrationRepository** (CSV implementation over **data/registrations.csv**, columns **student_id,event_id,status**) to set the status to **Cancelled** and save | **IT-12:** **RegistrationService** + the CSV repository on a temporary file. Register S001 for E001, call **cancel** with now = start − 24 h → returns success; reload the file → S001/E001 has status **Cancelled**, seats taken 1 → 0. Call **cancel** with now = start − 24 h + 1 s → returns "too late"; reload the file → status still **Registered** |
| Module design ↔ unit test | **MOD-12:** **canCancel(now, start)** in **include/clubhub/CancellationPolicy.hpp** returns **start - now >= 24h** | **UT-12a** now = start − 24 h → true (boundary). **UT-12b** now = start − 24 h + 1 s → false (boundary). **UT-12c** now = start − 7 days → true (class "well before"). **UT-12d** now = start + 1 h → false (class "after the start"). **UT-12e** now = start → false (boundary). All in **tests/cancellation_rule_test.cpp** |

## Acceptance test (Gherkin)

```gherkin
Feature: Cancel a registration (REQ-12, acceptance test AT-12)

  Background:
    Given the event "Robotics Workshop" starts on 2026-11-07 at 14:00
    And student "S001" is registered for "Robotics Workshop"

  Scenario: Cancellation exactly 24 hours before the start is allowed
    Given the current time is 2026-11-06 14:00:00
    When student "S001" cancels the registration
    Then the registration status is "Cancelled"
    And one seat becomes free

  Scenario: Cancellation less than 24 hours before the start is rejected
    Given the current time is 2026-11-06 14:00:01
    When student "S001" cancels the registration
    Then the registration status is still "Registered"
    And the message is "Error: cannot cancel registration for E001: the event starts in less than 24 hours."
    And the program exits with a non-zero code
    And no seat becomes free
```