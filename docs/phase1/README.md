# Phase 1: Orbit propagator

Write-up for this phase goes here once the plots exist. Plots go in `plots/`.

## Checklist

- [x] Create the repo with the planned structure
- [x] Install the C++ toolchain (g++, CMake, Ninja, Eigen, GoogleTest) and the Python tools (NumPy, Matplotlib, `sgp4`)
- [ ] Watch one video on how orbits work (Scott Manley or similar)
- [ ] Implement the two-body acceleration function
- [ ] Implement the Euler integrator, write the path to CSV and plot the orbit from the starter values
- [ ] Implement RK4 and plot energy drift for Euler against RK4
- [ ] Add the J2 term and show the orbital plane rotating
- [ ] Add exponential-atmosphere drag
- [ ] Validate against `sgp4` using a real TLE and plot the error
- [ ] Write unit tests and a Phase 1 README with plots

## Done when these exist

| Artifact | File |
| --- | --- |
| Euler vs RK4 energy + angular momentum drift | `plots/energy_drift.png` |
| J2 orbital plane rotation (RAAN vs time) | `plots/j2_raan.png` |
| Position error vs SGP4 over time | `plots/sgp4_error.png` |
| Unit tests passing (`ctest --test-dir build`) | `tests/` |

## Tests to aim for

- Two-body acceleration points toward Earth's center and has magnitude μ/r².
- Circular orbit returns to its start position after one period (tolerance depends on dt).
- RK4 energy drift is orders of magnitude smaller than Euler's for the same dt.
- RK4 error shrinks ~16x when dt is halved (4th-order convergence).
- J2 acceleration is zero-ish in z at the equator and matches a hand-computed value at one point.

## Write-up (fill in at the end)

- What I built:
- Results (plots + one sentence each):
- What went wrong and how I found it:
- What I'd do differently:
