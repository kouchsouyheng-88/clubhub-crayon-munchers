# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-__-__ · Reviewed by (Scrum Master): Buntong Anupheap

## QAS-01 · Availability · written by Kouch Souyheng
| Part             | Content            |
|------------------|--------------------|
| Source           |   system administrator |
| Stimulus         |   the server goes offline for an update|
| Environment      |   weekday 2:00 AM when few users are online, with about 3000 students registered      |
| Artifact         |   the server and application     |
| Response         |   it shows "under maintenance" message to students if they were online; the server restart after update            |
| Response measure |   server will be back in 10 minutes; monthly availability >= 99.5%(30 d * 24 h * 0.5% = 3.6 h downtime allowed)                |






## QAS-02 · Performance of check-in at the door · written by Yam Soksopheakna
| Part             | Content            |
|------------------|--------------------|
| Source           | Organizer                    |
| Stimulus         | Organizer checks registered students and sees attendance                   |
| Environment      | During peak arrival time, when 200 students arrive within 10 minutes and Wi-Fi is weak or overloaded. 
| Artifact         | Check-in                    |
| Response         | The application verifies the student's registration and records their attendance.                   |
| Response measure | 95 % of check-ins confirmed within 1 s; throughput >= 20 per minute per door                   |






## QAS-03 · Usability · written by Yam Soksopheakna
| Part             | Content            |
|------------------|--------------------|
| Source           | A new ITC student                   |
| Stimulus         | Student wants to register for an event                   |
| Environment      | Student is using for the first time                     |
| Artifact         | ITC Club Hub                   |
| Response         | System provides clear navigation, understandable information, and registration steps. |
| Response measure |  A first-time student registers for an event in at most 3 taps and 30 seconds, without help. |






## QAS-04 · Security · written by Buntong Anupheap
| Part             | Content            |
|------------------|--------------------|
| Source           | A logged-in student without organizer or administrator permissions |
| Stimulus         | The student attempts to change an event's attendance records by sending a request directly to the system. |
| Environment      | During normal operation, while the student has a valid account and an active session. |
| Artifact         | Attendance records and the server's access-control mechanism |
| Response         | The system checks the student's permissions, rejects the request, leaves attendance records unchanged, and logs the unauthorized attempt. |
| Response measure | 100% of unauthorized attendance-change requests in security tests are rejected; zero attendance records are changed; each rejected attempt is logged within 5 seconds. |






## QAS-05 · Modifiability · written by Ou Pechly
| Part             | Content            |
|------------------|--------------------|
| Source           | A club organizer asks the developers for a new rule |
| Stimulus         | Change the cancellation deadline from 24 hours to 12 hours before the event starts |
| Environment      | During development in the semester (15 weeks), with the existing code base and tests; team of 4 developers |
| Artifact         | The Club Hub business rule |
| Response         | A developer changes the rule in one place, runs the existing tests, and no other module needs editing |
| Response measure | At most 2 files changed; 100% of existing tests will pass |




## QAS-06 · Portability · written by Ung Phearakleap
| Part             | Content            |
|------------------|--------------------|
| Source | A student, an organiser or an administrator |
| Stimulus | Opens Club Hub on a device different from the developers' own |
| Environment | Android 10 or newer with Chrome, iPhone with iOS 16.4 or newer with Safari, desktop Windows with Chrome or Firefox |
| Artifact | PWA (front end), C++ core library (build) |
| Response | Same features work on every supported platform, the PWA can be installed on Android and iPhone, and the C++ core builds with the same CMake file on three compilers |
| Response measure | 100% of the 12 acceptance test cases pass on the 4 platform combinations (Android Chrome, iPhone Safari, desktop Chrome, desktop Edge) before each release |



## Priorities
| Scenario | Business importance | Technical risk |     Protects                | First? |
|----------|---------------------|----------------|------------------           |--------|
| QAS-01   |         H           |       H        | All users                   | Yes    |
| QAS-02   |         H           |       H        | Students, organizers        | Yes    |
| QAS-03   |         H           |       M        | Students                    | No     |
| QAS-04   |         H           |       H        | Students, organizers, admins| No     |
| QAS-05   |         M           |       M        | Developers                  | No     |
| QAS-06   |         H           |       M        | Students, organizers        | No     |
