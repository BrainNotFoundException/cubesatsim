# sim/

Orbit propagator (Phase 1), attitude dynamics and sensor models (Phase 2), in
C++20 with Eigen for vectors and matrices.

`constants.hpp` is provided. Everything else here is yours to write. A layout
that tends to work for Phase 1:

| Files | What goes in them |
| --- | --- |
| `forces.hpp/.cpp` | Acceleration functions: two-body, J2, drag. Each takes position (and velocity for drag) and returns an `Eigen::Vector3d`. |
| `integrators.hpp/.cpp` | Euler and RK4 steps, written against a generic `f(t, y)` so they don't know about orbits. |
| `propagate.hpp/.cpp` | The loop that calls an integrator repeatedly and stores the trajectory. |
| `atmosphere.hpp/.cpp` | Exponential density model for drag. |

Keeping forces and integrators separate is the design decision worth being
able to explain: it lets you swap Euler for RK4, or add J2, without touching
the other piece.

Any `sim/*.cpp` you add is built automatically, with no CMake edits. Include
headers from the repo root, e.g. `#include "sim/forces.hpp"`.
