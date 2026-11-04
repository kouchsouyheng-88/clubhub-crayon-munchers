# ADR-001 Application types for ITC Club Hub
Version 1.0 2026-10-31 Status: Proposed | Accpeted (2026-10-31) Deciders: Ung Phearakleap, Buntong Anupheap

## User groups
| Group | Device | Where | Connectivity | How often | Must never fail |
|---|---|---|---|---|---|
| Students | Mobile Phones (Both Android and iOS) | Anywhere | Most of the times via mobile data so it depends (not that stable) | Few times a week | Event registration and visibility of Annoucements |
| Organizers | One or two phones at door | Door of a room where wifi is weak | Weak | Few times a month | QR scanning no matter the network condition |
| Administrators | Desktop PCs | From their Office | Relies on Office wifi so it should be stable | Weekly for approvals and monthly for activity reports | The approval and rejection process |

## Options
A. Native App on Android and iOS   B. Cross-Platform    C. Responsive Web App   D. PWA

## Weighted Comparison (score 1-5 x weight)
| Criterion (weight) | Why this weight | A native | B cross-platform | C Responsive Web App | D PWA |
|--------------------|-----------------|----------|------------------|-------|------------------|
| Cost for team in one semester (3) | 5 students, 15 weeks, and the C++ core must be built so must put in alot of effort | 1 x 3 = 3 | 3 x 3 = 9 | 5 x 3 = 15 | 5 x 3 = 15 |
| Reach (3) | 3,000 students (android and iOS), many on limited mobile data; anything that needs a store account or a large download loses users | 3 x 3 = 9 | 3 x 3 = 9 | 5 x 3 = 15 | 5 x 3 = 15 |
| Offline check-in at the door (3) | Wi-Fi at the door is weak so they mustn't wait for the network. | 5 x 3 = 15 | 4 x 3 = 12 | 1 x 3 = 3 | 4 x 3 = 12 |
| Reminders (2) | Reminders reduce people from not showing up, but e-mail is an acceptable fallback, so it is slightly less than essential | 5 x 2 = 10 | 5 x 2 = 10 | 2 x 2 = 4 | 3 x 2 = 6 |
| Admin report printing and desktop use (1) | 2 to 3 users, Once a month | 1 x 1 = 1 | 2 x 1 = 2 | 5 x 1 = 5 | 5 x 1 = 5 |
| **Total** (maximum 60) | | 3 + 9 + 15 + 10 + 1 = **38** | 9 + 9 + 12 + 10 + 2 = **42** | 15 + 15 + 12 + 6 + 5 = **53** | 15 + 15 + 3 + 4 + 5 = **42** |

Deal-breaker check:
1. QR Checkins must work without wifi.
2. Registrations must happen without an app (in other words, students must not need to download anything in order to register).
3. The team must be able to deliver all three user groups in one semester.

## Decision
We build **one PWA** for students and organisers (mobile first, installable, offline check-in queue) and use **the same web app on desktop** for administrators (monthly report with a print-friendly view). Reminders go by push notification where the browser supports it, and always by e-mail.

## Consequences
+ One code base and one skill set for all three user groups, so a 5-person team can finish in one semester.
+ Students use Club Hub with a link (shared in chat groups), and updates are released immediately to everyone.
- Browser storage is limited and can be cleared by the browser, so unsynchronised check-ins must be uploaded quickly and the app should warn when many are pending.
- A PWA has fewer device features than a native app, so a native app may be needed later if the club demands it.

## Rejected options
- **A. Native apps**: three front ends (Android, iOS, administrators' web) are too much for a 5-person team in one semester.
- **B. Cross-platform app**: still needs store publication and a download for 3,000 students, and the team has no experience with the framework.
- **D. Responsive web app**: fails the deal-breaker "check-in must work without Wi-Fi". It would be fine for students and administrators, but not for the organisers at the door.

## How the front ends reach the C++ core
In production the C++ core (`include/clubhub/`, `src/`) would sit behind an HTTP API, and the PWA would call that API with JSON. In this course the PWA is **modelled only**: the command-line front end (`src/cli/main.cpp`) calls the core library directly in the same process. Because the core has no console and no file names, the same library can later be linked into the API service without changes.