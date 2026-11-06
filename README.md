# CubeSat Simulator

A software-in-the-loop CubeSat simulator built from scratch: orbit propagator,
attitude dynamics, Kalman filter and flight software in C++, plus a Python
ground station and plotting tools. Full plan: [`docs/project-plan.md`](docs/project-plan.md).

## Status

| Phase | Component | Status |
| --- | --- | --- |
| 1 | Orbit propagator (RK4, J2, drag, SGP4 validation) | In progress |
| 2 | Attitude dynamics and sensors | Not started |
| 3 | EKF state estimation | Not started |
| 4 | C++ flight software | Not started |
| 5 | Ground station | Not started |

## Layout

```
sim/          orbit propagator, attitude dynamics, sensor models (C++)
apps/         programs that run the simulator and write CSV (C++)
tools/        plots and SGP4 reference data (Python)
estimation/   Kalman filter
flight_sw/    C++ flight software and packet definitions
ground/       ground station and dashboard
tests/        unit tests
docs/         per-phase write-ups and validation plots
data/tles/    real TLEs used for validation
```

## Setup

You need `g++` with C++20 support and Python 3.11+. On Windows, `g++` comes from
MSYS2. CMake and Ninja install into `.venv`, so activate it in each new terminal.
The first configure downloads Eigen and GoogleTest.

```bash
python -m venv .venv
.venv\Scripts\activate          # Windows (PowerShell)
# source .venv/bin/activate     # macOS/Linux
pip install -r requirements.txt

cmake --preset default          # once, or after changing CMakeLists.txt
cmake --build build             # compile; also picks up new .cpp files
ctest --test-dir build          # run the tests
```
