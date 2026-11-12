# Accessibility checklist · ITC Club Hub (planned web and mobile UI)
Target: WCAG 2.2 level AA · Version 0.1 · 2026-11-12 ·

| SC | Name | Principle | Level | Screen | How we meet it | How we test it |
|----|------|-----------|-------|--------|----------------|----------------|
| 1.1.1 | Non-text Content | Perceivable | A | Event list | Event images have alt text (title + date); decorative icons use empty alt | Screen reader (NVDA/TalkBack) reads each image sensibly |
| 1.3.1 | Info and Relationships | Perceivable | A | Registration form | Real `<label>`, `<fieldset>`, headings and table headers | Inspect DOM; navigate by headings in a screen reader |
| 1.4.1 | Use of Color | Perceivable | A | Event list / CLI | Status shown as text ("Full", [CANCELLED]); colour only repeats it | View in greyscale mode |
| 1.4.3 | Contrast (Minimum) | Perceivable | AA | Both screens | Text colours ≥ 4.5:1 (see contrast audit) | WebAIM Contrast Checker |
| 1.4.4 | Resize Text | Perceivable | AA | Event list | Relative units (rem); layout works at 200% zoom | Browser zoom to 200%, no clipped text |
| 1.4.11 | Non-text Contrast | Perceivable | AA | Registration form | Input borders and buttons ≥ 3:1 | WebAIM Contrast Checker |
| 2.1.1 | Keyboard | Operable | A | Registration form | All controls reachable and usable with Tab/Enter/Space | Unplug mouse, complete a registration |
| 2.4.7 | Focus Visible | Operable | AA | Both screens | 3 px focus outline on every control | Tab through page, outline always visible |
| 2.4.11 | Focus Not Obscured (Minimum) | Operable | AA | Event list | Sticky header uses `scroll-padding-top`; focused item never hidden | Tab to last list item with header visible |
| 2.5.7 | Dragging Movements | Operable | AA | Event list | No drag-only action; reorder/filter use buttons | Complete every task with single clicks |
| 2.5.8 | Target Size (Minimum) | Operable | AA | Registration form | Buttons and checkboxes ≥ 24×24 CSS px | Measure in browser dev tools |
| 3.2.6 | Consistent Help | Understandable | A | All screens | "Help / Contact clubs office" link in the same place on every page | Compare footer position across screens |
| 3.3.1 | Error Identification | Understandable | A | Registration form | Error text names the field and the problem (not colour alone) | Submit empty form, read messages |
| 3.3.2 | Labels or Instructions | Understandable | A | Registration form | Format hints shown ("Student ID: e2099xxxx") | Review form without placeholders |
| 3.3.7 | Redundant Entry | Understandable | A | Registration form | Name/email prefilled from profile; not asked twice | Register for 2 events, no re-typing |
| 3.3.8 | Accessible Authentication (Minimum) | Understandable | AA | Login | Password paste and password managers allowed; no puzzle/CAPTCHA | Log in using a password manager |
| 4.1.2 | Name, Role, Value | Robust | A | Both screens | Native HTML controls; ARIA only where needed | Accessibility tree in dev tools; axe scan |
| 4.1.3 | Status Messages | Robust | AA | Registration form | "Registered" / "Event full" announced with `role="status"` | Screen reader announces result without focus move |

## Contrast audit (two planned screens)

### Screen 1: Event list
Design decisions:
1. Status shown as a text badge ("Full", "Open"), colour is secondary.
2. Event cards are keyboard-focusable links with a visible outline.
3. Dates in unambiguous format (2026-10-14 17:30).

| Element | Foreground | Background | Ratio | Required | Result |
|---------|-----------|-----------|-------|----------|--------|
| Body text | #1A1A1A | #FFFFFF | 17.40:1 | 4.5:1 | Pass |
| "Register" button text | #FFFFFF | #0B5CAD | 6.67:1 | 4.5:1 | Pass |
| "Full" badge text | #8A1C1C | #FDECEC | 8.12:1 | 4.5:1 | Pass |

### Screen 2: Registration form
Design decisions:
1. Every field has a visible label above it (no placeholder-only labels).
2. Errors appear next to the field with an icon and text.
3. Submit button ≥ 44 px tall; optional consents are separate, unticked checkboxes.

| Element | Foreground | Background | Ratio | Required | Result |
|---------|-----------|-----------|-------|----------|--------|
| Field label | #333333 | #FFFFFF | 12.63:1 | 4.5:1 | Pass |
| Error text | #B00020 | #FFFFFF | 7.33:1 | 4.5:1 | Pass |
| Submit button text | #FFFFFF | #0B6B3A | 6.61:1 | 4.5:1 | Pass |
| Input border (UI component) | #767676 | #FFFFFF | 4.54:1 | 3:1 | Pass |
