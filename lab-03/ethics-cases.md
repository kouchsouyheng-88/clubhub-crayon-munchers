# Ethics case analyses · ITC Club Hub
Version 1.0 · 2026-11-12 · Leads: A = <name>, B = Ou Pechly

## Scenario A: "Just a small report"
| Step | Analysis |
|------|----------|
| 1 Facts | TODO (and what we still need to find out) |
| 2 Stakeholders and harms | TODO |
| 3 Codes, law, policy | SE Code principle TODO; ACM TODO; GDPR TODO |
| 4 Options | (a) TODO (b) TODO (c) TODO |
| 5 Tests | harm / rights / fairness / publicity for each option |
| 6 Decision and action | TODO |
| 7 Reflection | TODO |

**Message sent:** TODO (max. 120 words)
**Preventive change:** TODO, issue #TODO

## Scenario B: "Don't mention it in the demo"

| Step | Analysis |
|------|----------|
| 1 Facts | Two days before the Sprint 1 review, a developer found two defects: (1) cancellations inside the 24-hour window are accepted, which breaks a business rule; (2) the monthly report counts cancelled registrations as attendance, so its numbers are too high. The Scrum Master asks the team not to mention it and to fix it in Sprint 2. **Still to find out:** how many records are affected, whether the client already uses the report, the root cause, and how long the fix and its tests would take. |
| 2 Stakeholders and harms | **Client / clubs office:** decides on wrong numbers and feels deceived when it finds out. **Organisers:** wrong attendance and seat counts. **Students:** their attendance records are inaccurate. **Developer who found it:** pressure to stay silent. **Team:** loses the client's trust and builds a habit of hiding defects. |
| 3 Codes, law, policy | SE Code 3.10 (adequate testing and review) and 6.08 (take responsibility for detecting, correcting and reporting errors). SE Code 6.12 (express concerns to the people involved). ACM 1.3 (be honest and trustworthy) and ACM 2.5 (evaluate systems and their risks thoroughly). GDPR Art. 5(1)(d) accuracy: attendance records are personal data and must be accurate. |
| 4 Options | (a) Stay silent as asked. (b) Postpone the whole demo. (c) Demo as planned and state both defects and a fix date under "known issues". (d) Fix both defects in the two days, with regression tests, and drop a lower-priority item from the demo. |
| 5 Tests | **(a)** Harm: wrong report data reaches the client. Rights: students' records are inaccurate. Fairness: the client is denied information it needs. Publicity: fails; the client would feel deceived. **(b)** Harm: low. Rights and fairness: pass. Publicity: acceptable, but it wastes the review and protects nothing extra. **(c)** Passes all four: no harm is hidden, the client decides with full information, and the team could defend it publicly. **(d)** Passes all four, but only if the fix and its tests are done in time. |
| 6 Decision and action | Choose **(c)**, and **(d)** if the regression tests are green two days from now. The developer first raises it with the Scrum Master (SE Code 6.12), then the Product Owner adds it to the review agenda. If the Scrum Master still refuses, the developer informs the Product Owner and the instructor. |
| 7 Reflection | Hiding a known defect feels cheap now but costs trust later. A defect reported with a plan is a normal project event; a defect the client discovers is a breach of trust. We should make reporting easy by adding a "Known issues" section to the review template, so nobody has to choose between honesty and loyalty. |

**Message sent:**
Hi Buntong Anupheap and Ung Phearakleap, while preparing the Sprint 1 review I found two defects: (1) cancellations are accepted inside the 24-hour window, which breaks a business rule; (2) the monthly report counts cancelled registrations as attendance, so its numbers are too high. I suggest we list both under "known issues" in the review with a Sprint 2 fix date, and fix and test them before the demo if time allows. Staying silent could mislead the client if they rely on the report. Can we agree on this today? I can write the regression tests and a fix estimate by tomorrow.

**Preventive change:** Add regression tests for the 24-hour cancellation rule and for attendance excluding `Cancelled` registrations, and add a "Known issues" section to the review template. Issue #TODO, label `ethics`.