# tools/

Python helpers that sit outside the simulator. They read and write files and
never link with the C++ code.

- **Plots:** read CSV from `output/` and save PNGs to `docs/phase1/plots/`.
- **SGP4 reference:** propagate a TLE from `data/tles/` with the `sgp4` library
  and write the states to CSV for the C++ propagator to start from and be
  compared against.
