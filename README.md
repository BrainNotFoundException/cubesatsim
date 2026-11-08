# CubeSat Simulator

A software-in-the-loop CubeSat simulator written from scratch: a virtual
satellite, the flight software that controls it, and a ground station that talks
to it. It needs no hardware.

**Target demo:** a command from the ground changes the satellite's behavior, an
injected fault triggers safe mode, and the estimator tracks the true attitude
despite sensor noise.

## Status

| Phase | Component | Status |
| --- | --- | --- |
| 1 | Orbit propagator: RK4, J2, drag, validated against SGP4 | In progress |
| 2 | Attitude dynamics and sensor models | Not started |
| 3 | Extended Kalman filter for attitude estimation | Not started |
| 4 | Flight software: mode state machine, scheduler, fault detection, CCSDS-style packets | Not started |
| 5 | Ground station: telemetry decoding, live dashboard, commands | Not started |

## Tech stack

- **Simulator and flight software:** C++20, Eigen, GoogleTest, CMake
- **Plots and SGP4 reference data:** Python, NumPy, Matplotlib, `sgp4`

## Project layout

```
sim/          simulator source and physical constants
tests/        unit tests
docs/plots/   validation plots
```

More folders are added as each phase starts.

## Build and test

You need `g++` with C++20 support and Python 3.11 or newer. CMake and Ninja
install into `.venv`, so activate it in each new terminal. The first configure
downloads Eigen and GoogleTest.

```bash
python -m venv .venv
.venv\Scripts\activate          # Windows
# source .venv/bin/activate     # macOS/Linux
pip install -r requirements.txt

cmake --preset default
cmake --build build
ctest --test-dir build
```

## Results

Notes on knowledge gained along with plots [updated with progress].

Phase 1 (Orbit Propagator):

- Periapsis - closest, Apoapsis - farthest
- Prograde burn -> when engines fired in direction of movement. -> altitude increases at the opposite side
    - speeds up at the point where engine was fired.
    - slows down at the opposite side -> converted to potential energy from kinetic.
- Retrograde burn -> when engines fired in opposite direction of movement. -> altitude decreases at the opposite side
    - opposite of prograde.
- Radial out burn -> pulls the opposite side or the orbit towards the earth cause no change in velocity in direction of motion.
- Radial in burn -> opposite of radial out burn effectively.
- Normal burns -> just rotating the orbit while maintaining centre.