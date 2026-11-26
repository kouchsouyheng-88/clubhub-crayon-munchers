# Process Comparison · Team Crayon Munchers · v1.0

Date: 2026-11-26
Status: Complete — weights, scores, tie-breaks and discussion outcomes approved by the team on 2026-11-26.

Scale: 1 = fits Club Hub badly on this criterion, 5 = fits very well.

## Aggregation method

Each score is the mode, or most frequently occurring value, of the five individual submissions. Four cells have two equally frequent values. The team approved selection of the lower tied value as a conservative tie-break, with both modes recorded below. The agreed weights total 100 and provide the basis for the calculations.

| Member | GitHub username | Individual submission | Submission commit |
|--------|-----------------|-----------------------|-------------------|
| Buntong Anupheap | anupheap | [BuntongAnupheap.md](scores/BuntongAnupheap.md) | `ba5f5b2` |
| Kouch Souyheng | kouchsouyheng-88 | [KouchSouyheng.md](scores/KouchSouyheng.md) | `224e35b` |
| Ou Pechly | Ou-Pechly | [Ou-Pechly.md](scores/Ou-Pechly.md) | `5144502` |
| Ung Phearakleap | phearakleap | [UngPhearakleap.md](scores/UngPhearakleap.md) | `6847188` |
| Yam Soksopheakna | YamSoksopheakna | [YamSoksopheakna.md](scores/YamSoksopheakna.md) | `f79815c` |

Git history records all five submissions before preparation of this aggregation. The individual scores are preserved in their original files.

## Team-approved scores and weights

W = Waterfall; I = Incremental delivery; S = Scrum-style iterative development.

| Criterion | Weight | Waterfall | Incremental | Scrum-style | Justification (one line each) |
|-----------|-------:|----------:|------------:|------------:|-------------------------------|
| Requirements stability | 20 | 2 | 4 | 4 | W requires earlier agreement on interacting Club Hub rules; I accommodates revisions in later increments; S supports backlog revision after client reviews. |
| Client availability | 10 | 2 | 4 | 4 | W concentrates formal approvals at stage boundaries; I supports feedback on each working feature; S provides scheduled sprint reviews through the PO. |
| Team experience | 15 | 3 | 4 | 3 | W requires coordinated planning across stages; I fits the team's task division and code integration; S introduces sprint practices that require consistent coordination. |
| Deadline (week 14) | 25 | 2 | 4 | 4 | W leaves greater exposure to delays before a complete demonstration; I provides an early working subset; S provides sprint goals, reviews and scope prioritisation. |
| Risk | 30 | 2 | 4 | 5 | W risks later discovery of implementation defects; I supports validation of each increment; S combines repeated rule testing with scheduled client review and reprioritisation. |
| **Weighted score** | **100** | **2.15** | **4.00** | **4.15** | |

The justifications summarise the individual submissions and the scores and assumptions confirmed during team review.

## Why these weights

- **Requirements stability (20):** The [problem statement](../lab-01/problem-statement.md#scope) specifies capacity limits, duplicate prevention, the 24-hour cancellation cutoff, past-event restrictions and approved-club publication. Clarifying their interactions has a substantial effect on implementation and rework.
- **Client availability (10):** The [team charter](../lab-01/team-charter.md#members-and-roles) assigns a fixed Product Owner and establishes communication channels. The [stakeholder analysis](../lab-01/stakeholders.md) identifies weekly lab contact with the client through the PO, providing a defined route for clarification and review.
- **Team experience (15):** The [team charter](../lab-01/team-charter.md#members-and-roles) defines five members, shared responsibilities and a rotating Scrum Master. Its pull-request review agreement makes the team's ability to coordinate implementation and review relevant to process selection.
- **Deadline (25):** The [team charter](../lab-01/team-charter.md#working-agreements) requires work to be completed at least 24 hours before deadlines. The week-14 submission specified by the lab therefore requires a demonstrable implementation with time reserved for review.
- **Risk (30):** The [problem statement](../lab-01/problem-statement.md#scope) requires cancellation to release seats while enforcing capacity and the cancellation cutoff. Defects across these related rules can produce inconsistent registrations and seat counts, making early validation the highest priority in this comparison.

Weight check: 20 + 10 + 15 + 25 + 30 = **100**.

## Tied modes

| Criterion | Model | Equally frequent scores | Frequency of each | Selected score |
|-----------|-------|-------------------------|------------------:|---------------:|
| Team experience | Waterfall | 3 and 4 | 2 of 5 | 3 |
| Team experience | Incremental | 4 and 5 | 2 of 5 | 4 |
| Deadline (week 14) | Scrum-style | 4 and 5 | 2 of 5 | 4 |
| Risk | Waterfall | 2 and 3 | 2 of 5 | 2 |

## Team discussion outcomes

The team reviewed the six cells with a difference of at least two points between the highest and lowest individual scores and confirmed the aggregated scores below. The score order is Buntong Anupheap, Kouch Souyheng, Ou Pechly, Ung Phearakleap and Yam Soksopheakna.

| Criterion | Model | Individual scores | Range | Agreed score | Basis for agreement |
|-----------|-------|-------------------|------:|-----------------:|------------------|
| Requirements stability | Waterfall | 4, 2, 2, 2, 2 | 2–4 | 2 | The team retained the mode of 2, selected by four members, after reviewing requirements stability and the potential for rework. |
| Client availability | Incremental | 5, 4, 4, 3, 4 | 3–5 | 4 | The team retained the mode of 4, selected by three members, reflecting the opportunity for client feedback after each increment. |
| Team experience | Waterfall | 3, 2, 4, 4, 3 | 2–4 | 3 | Scores 3 and 4 each occurred twice; the team confirmed 3 under the agreed lower-mode tie-break after reviewing planning demands. |
| Team experience | Incremental | 5, 5, 3, 4, 4 | 3–5 | 4 | Scores 4 and 5 each occurred twice; the team confirmed 4 under the agreed lower-mode tie-break after reviewing task division and integration experience. |
| Deadline (week 14) | Scrum-style | 4, 3, 5, 4, 5 | 3–5 | 4 | Scores 4 and 5 each occurred twice; the team confirmed 4 under the agreed lower-mode tie-break, considering sprint progress and coordination demands. |
| Risk | Waterfall | 3, 3, 1, 2, 2 | 1–3 | 2 | Scores 2 and 3 each occurred twice; the team confirmed 2 under the agreed lower-mode tie-break after reviewing validation and integration risks. |

Discussion status: complete. The team confirmed the weights, aggregated scores and all four tie-break selections on 2026-11-26. The calculations below reflect the approved values.

## Weighted scores

For each model:

**Weighted score = Σ(weight × score) / 100**

- **Waterfall:** 215 / 100 = **2.15**.
- **Incremental delivery:** 400 / 100 = **4.00**.
- **Scrum-style:** 415 / 100 = **4.15**.

### Full calculation for Scrum-style

Criteria are ordered as requirements stability, client availability, team experience, deadline and risk.

```text
(20 × 4 + 10 × 4 + 15 × 3 + 25 × 4 + 30 × 5) / 100
= (80 + 40 + 45 + 100 + 150) / 100
= 415 / 100
= 4.15
```

## Sensitivity check

Transfer 10 weight points from **risk**, the heaviest criterion, to **client availability**, the lightest criterion. All aggregated scores remain fixed.

| Criterion | Original weight | Revised weight |
|-----------|----------------:|---------------:|
| Requirements stability | 20 | 20 |
| Client availability | 10 | 20 |
| Team experience | 15 | 15 |
| Deadline (week 14) | 25 | 25 |
| Risk | 30 | 20 |
| **Total** | **100** | **100** |

```text
Waterfall:
(20 × 2 + 20 × 2 + 15 × 3 + 25 × 2 + 20 × 2) / 100
= 215 / 100 = 2.15

Incremental delivery:
(20 × 4 + 20 × 4 + 15 × 4 + 25 × 4 + 20 × 4) / 100
= 400 / 100 = 4.00

Scrum-style:
(20 × 4 + 20 × 4 + 15 × 3 + 25 × 4 + 20 × 5) / 100
= 405 / 100 = 4.05
```

Scrum-style remains the highest-scoring model, with its lead over incremental delivery decreasing from 0.15 to 0.05 points.

## Conclusion

Under the agreed weights, Scrum-style ranks first at 4.15, followed by incremental delivery at 4.00 and waterfall at 2.15. Its higher risk score reflects the priority given to reviewing interacting registration and cancellation rules throughout development. The team will manage the learning and coordination demands of sprint practices through clear responsibilities, concise meetings and early blocker reporting. A hybrid combining Scrum-style planning with incremental delivery is expected to retain the same score, as the assessed Scrum-style approach already assumes working increments at sprint reviews.

## Completion record

- [x] Team approved the weights and resolved the six discussion items.
- [x] Team approved the tie-break selections and final scores.
- [x] Weighted scores and the sensitivity check were verified.
- [x] Final team agreement was recorded on 2026-11-26.

Commit message: `Lab-04 task 2: scored process comparison`.
