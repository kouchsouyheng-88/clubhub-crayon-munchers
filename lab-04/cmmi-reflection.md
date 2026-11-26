# CMMI reflection · Team Crayon Munchers

## Where we are today (level 1, with some level 2 habits) and the evidence

We are at maturity level 1 (Initial) with a few level 2 habits. Evidence from the repository on 2026-11-26 (141 commits):

- All five members have commits (souyheng 49 including a second account, phearakleap 29, YamSoksopheakna 23, Ou-Pechly 22, anupheap 18), so everyone contributes, but one account holds about a third of the history.
- Pull requests were used to merge the lab-01 and lab-02 branches into main (for example #4), which is a level 2 habit, but the repository holds no review evidence, so we cannot show that the "one reviewer within 24 h" agreement is followed.

## The practice area we adopt now and why

We adopt **Configuration Management**. From Sprint 1 every story must be traceable to commits, and the Definition of Done says a story is finished when the build is warning-free, tests pass in CI and a reviewer has approved. Today none of that is checked automatically, and the evidence above shows that our agreements depend on memory.

## Three actions (who, from when)

1. Kouch Souyheng adds `.github/workflows/ci.yml`, which configures, builds with warnings enabled and runs `ctest` on every pull request, before Sprint 1 planning in week 9.
2. Buntong Anupheap (Scrum Master in Sprint 1) protects `main` so that a merge needs one approval and a green CI run, and adds a commit message template (`S1-<story id>: <what>`), from the first day of Sprint 1.
3. Ung Phearakleap (Product Owner) creates a GitHub Issue for every backlog story and asks that each pull request description names its issue, from Sprint 1 planning.

## How we measure it (metric, target) and when we check

Metric: the share of commits made during the sprint whose message follows the agreed format, counted with `git log --since=<sprint start> --format=%s`. Baseline today: 8 of 141, about 6%. Target for Sprint 1: at least 90%. We check it at the Sprint 1 retrospective at the end of week 10, and the Scrum Master records the number in the retrospective notes. If the target is missed, we look at which commits broke the format and decide whether the template or the habit needs fixing.