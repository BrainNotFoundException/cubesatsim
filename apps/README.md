# apps/

Small programs that run the simulator. Each `apps/<name>.cpp` needs its own
`main()` and builds to `build/apps/<name>` with no CMake edits.

For Phase 1, an app runs a propagation and writes the result as CSV into
`output/`, for example `apps/euler_vs_rk4.cpp` writing
`output/euler_vs_rk4.csv`. Create `output/` first. The Python scripts in
`tools/` turn those CSV files into plots.
