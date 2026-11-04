# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-__-__ · Reviewed by (Scrum Master): __

## QAS-01 · Availability · written by __
| Part             | Content            |
|------------------|--------------------|
| Source           |                    |
| Stimulus         |                    |
| Environment      |                    |
| Artifact         |                    |
| Response         |                    |
| Response measure |                    |






## QAS-02 · Performance of check-in at the door · written by Yam Soksopheakna
| Part             | Content                    |
|------------------|--------------------        |
| Source           | Organizer                   |
| Stimulus         | Organizer checks registered students and sees attendance|
| Environment      | During peak arrival time, when 200 students arrive within 10 minutes and Wi-Fi is weak or overloaded.      |
| Artifact         | Check-in                    |
| Response         | The application verifies the student's registration and records their attendance.   |
| Response measure | 95 % of check-ins confirmed within 1 s; throughput >= 20 per minute per door          |






## QAS-03 · Usability · written by Yam Soksopheakna
| Part             | Content            |
|------------------|--------------------|
| Source           | A new ITC student                   |
| Stimulus         | Student wants to register for an event                   |
| Environment      | Student is using for the first time                   |
| Artifact         | ITC Club Hub                   |
| Response         | System provides clear navigation, understandable information, and registration steps.|                  
| Response measure | A first-time student registers for an event in at most 3 taps and 30 seconds, without help         |






## QAS-04 · Security · written by
| Part             | Content            |
|------------------|--------------------|
| Source           |                    |
| Stimulus         |                    |
| Environment      |                    |
| Artifact         |                    |
| Response         |                    |
| Response measure |                    |






## QAS-05 · Modifiability · written by
| Part             | Content            |
|------------------|--------------------|
| Source           |                    |
| Stimulus         |                    |
| Environment      |                    |
| Artifact         |                    |
| Response         |                    |
| Response measure |                    |




## QAS-06 · Portability · written by __
| Part             | Content            |
|------------------|--------------------|
| Source           |                    |
| Stimulus         |                    |
| Environment      |                    |
| Artifact         |                    |
| Response         |                    |
| Response measure |                    |



## Priorities
| Scenario | Business importance | Technical risk |     Protects                | First? |
|----------|---------------------|----------------|------------------           |--------|
| QAS-01   |         H           |       H        | All users                   | Yes    |
| QAS-02   |         H           |       H        | Students, organizers        | Yes    |
| QAS-03   |         H           |       M        | Students                    | No     |
| QAS-04   |         H           |       H        | Students, organizers, admins| No     |
| QAS-05   |         M           |       M        | Developers                  | No     |
| QAS-06   |         H           |       M        | Students, organizers        | No     |