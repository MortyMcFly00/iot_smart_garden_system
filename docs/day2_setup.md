# Day 2 – GitHub Repo Setup and Project Structuring

## Date
May 6, 2025

---

## Objectives
- Initialize GitHub repository
- Push PlatformIO project files to version control
- Create documentation directory and `day1-setup.md`
- Test `.gitignore` behavior and fix untracked files
- Handle GitHub authentication with Personal Access Token (PAT)

---

## Actions Taken
- Cloned empty repo containing `README.md`
- Copied PlatformIO project into cloned repo root
- Cleaned `.pio/` directory to avoid binary bloat
- Verified all project directories:
  - `src/`, `lib/`, `include/`, `docs/`, `platformio.ini`
- Rebuilt `src/main.cpp` after file was lost (not saved during Day 1)
- Resolved Git authentication issues:
  - Created GitHub PAT with `repo` scope
  - Used token instead of password during push

---

## Results
- Successfully staged, committed, and pushed:
  - `src/main.cpp`
  - `platformio.ini`
  - `docs/day1-setup.md`
- GitHub repo now reflects accurate project state
- Git workflow confirmed functional on Linux

---

## Next Steps (Day 3)
- Test and wire soil moisture sensor
- Begin logic for threshold-based auto-watering
- Document moisture input behavior