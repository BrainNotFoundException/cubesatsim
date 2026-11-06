// Physical constants for Earth (units: km, s, kg).
//
// Values match WGS-84 and the numbers in docs/project-plan.md. Keeping them in
// one place means every module and test uses the same numbers.
#pragma once

#include <Eigen/Dense>

namespace sim {

inline constexpr double MU_EARTH = 398600.4418;      // km^3/s^2, gravitational parameter
inline constexpr double R_EARTH = 6378.137;          // km, equatorial radius
inline constexpr double J2 = 1.08262668e-3;          // dimensionless, Earth oblateness
inline constexpr double OMEGA_EARTH = 7.2921159e-5;  // rad/s, Earth rotation (for drag v_rel)

// Phase 1 starter state from the project plan (slightly elliptical LEO).
inline const Eigen::Vector3d STARTER_R0{7000.0, 0.0, 0.0};  // km
inline const Eigen::Vector3d STARTER_V0{0.0, 7.5, 0.0};     // km/s

}  // namespace sim
