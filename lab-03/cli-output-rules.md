# CLI output rules · ITC Club Hub
Version 0.1 · 2026-11-12 · 

## Rule 1: Never use colour alone
**Why:** Colour-blind users and screen readers cannot see colour.
- Bad: `E-017  Git Workshop` (printed in red)
- Good: `E-017  Git Workshop      [CANCELLED]`

## Rule 2: Honour NO_COLOR and a --no-color flag
**Why:** Colour codes break logs, pipes and some terminals.
- Bad: `\033[31mCANCELLED\033[0m` always printed, even into a file
- Good: no escape codes when `--no-color` is given or `NO_COLOR` is set

## Rule 3: Errors say what failed, why, and the next step
**Why:** Users need to recover without reading the source code.
- Bad: `ERR_CAP`
- Good: `Error: cannot register for E-017: the event is full (40 of 40 seats).`
  `Next step: clubhub waitlist E-017`

## Rule 4: Return a non-zero exit code on error
**Why:** Scripts and assistive tools detect failure by exit code, not by text.
- Bad: print "Error: ..." and `return 0;`
- Good: print the error and `return 1;`

## Rule 5: Prompts state the expected format
**Why:** Users should not have to guess how to type an answer.
- Bad: `Date?`
- Good: `Event date and time (YYYY-MM-DD HH:MM, e.g. 2026-10-14 17:30):`

## Rule 6: Use unambiguous dates
**Why:** 04/10/2026 means different dates in different countries.
- Bad: `Starts 04/10/26 5pm`
- Good: `Starts 2026-10-04 17:00`

## Rule 7: Do not rely on symbols or alignment alone
**Why:** Screen readers read symbols oddly and skip visual spacing.
- Bad: `✔ E-017` / `✘ E-018`
- Good: `E-017  [REGISTERED]` / `E-018  [CANCELLED]`