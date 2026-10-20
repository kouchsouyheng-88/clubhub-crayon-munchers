# Problem statement · ITC Club Hub (v0.1, 2026-10-16)

## Problem
The problem of finding, joining and cancelling club events through scattered chat groups affects students, club leaders, organisers and administrators at ITC; the impact of which is seats that stay "taken" after students silently drop out, students who never hear about events they would have liked, and clubs and administrators who have no numbers on who actually came.
A successful solution would give every event one visible place where students can discover it, register and cancel, and where attendance is recorded so clubs can show their activity.

## Vision
For ITC students and club leaders who want events to be found, filled and counted, ITC Club Hub is a web and mobile application that publishes events in one place, frees seats when students cancel and records attendance.
Unlike announcements buried in chat groups, our product shows every approved club's events to all students, enforces capacity and the cancellation deadline, and gives administrators real attendance numbers.

## Today's workaround
Some workarounds that are used currently include:
- Club leaders post events in their own chat groups and students outside the group never see them.
- Students who cannot come say nothing or write in the chat, but the organiser does not notice, so the seat stays taken and others are turned away.
- Organisers count people by hand at the door and rarely keep the numbers and the monthly report to administrators is a guess.
## Scope
- Built in C++ this semester:
    - Domain model (clubs, events, registrations, attendance)
    - Business rules (capacity, no double registration, cancellation closes 24 h before start, no registration for past events, only approved clubs publish).
    - Cancellation that frees a seat, browse of all approved clubs' events.
    - Attendance records and monthly activity totals per club; command-line front end.
    - CSV or JSON file storage.
- Modelled only (web and mobile):
    - Screens and flows for students, club leaders, organisers and administrators
    - Reminders
    -  Layout of the monthly activity report.
- Out of scope:
    - Online payments
    - Real login with the institute's accounts
    - Push notifications in production
    - Waiting list (unless it's a *MUST* by the lecturer)
    - Room booking and schedule clashes
    - Hosting and deployment.