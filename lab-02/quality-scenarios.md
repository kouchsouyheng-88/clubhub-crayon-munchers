# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-__-__ · Reviewed by (Scrum Master): __

## QAS-01 · Availability · written by Kouch Souyheng
| Part             | Content            |
|------------------|--------------------|
| Source           |   system administrator |
| Stimulus         |   the server goes offline for an update|
| Environment      |   weekday 2:00 AM when few users are online, with about 3000 students registered      |
| Artifact         |   the server and application     |
| Response         |   it shows "under maintenance" message to students if they were online; the server restart after update            |
| Response measure |   server will be back in 10 minutes; monthly availability >= 99.5%(30 d * 24 h * 0.5% = 3.6 h downtime allowed)                |






## QAS-02 · Performance of check-in at the door · written by __
| Part             | Content            |
|------------------|--------------------|
| Source           |                    |
| Stimulus         |                    |
| Environment      |                    |
| Artifact         |                    |
| Response         |                    |
| Response measure |                    |






## QAS-03 · Usability · written by
| Part             | Content            |
|------------------|--------------------|
| Source           |                    |
| Stimulus         |                    |
| Environment      |                    |
| Artifact         |                    |
| Response         |                    |
| Response measure |                    |






## QAS-04 · Security · written by
| Part             | Content            |
|------------------|--------------------|
| Source           |                    |
| Stimulus         |                    |
| Environment      |                    |
| Artifact         |                    |
| Response         |                    |
| Response measure |                    |






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
| Scenario | Business importance | Technical risk | Protects | First? |
|----------|---------------------|----------------|----------|--------|
| QAS-01   |                     |                |          |        |