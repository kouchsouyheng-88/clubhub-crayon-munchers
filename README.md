# ITC Club Hub · Team Crayon Munchers

An application for the student clubs of the Institute of Technology of
Cambodia. Course project, Introduction to Software Engineering.

## Team
| Member          | GitHub            | Role (Sprint 1) |
| --------------- | ----------------- | --------------- |
| Ung Phearakleap | @phearakleap      | Product Owner   |
| Kouch Souyheng  | @kouchsouyheng-88 | Developer       |
| Yam Soksopheakna| @YamSoksopheakna  | Developer       |
| Buntong Anupheap| @anupheap         | Scrum Master    |
| Ou Pechly       | @Ou-Pechly        | Developer       |

## Repository layout
| Path                  | Content                                |
| --------------------- | -------------------------------------- |
| `lab01/` ... `lab11/` | Documents of each lab                  |
| `include/clubhub/`    | Public C++ headers (namespace clubhub) |
| `src/`                | C++ sources                            |
| `tests/`              | Unit tests (added in a later lab)      |

## Build
    cmake -S . -B build
    cmake --build build

## Licence

The Club Hub source code is prepared under the [MIT License](LICENSE). The team chose it for its simplicity and broad reuse; the [decision record](lab-03/licence-decision.md) has placeholders for contributor responses. [Third-party notices](THIRD_PARTY_NOTICES.md) credit GoogleTest, which is used only for tests.
