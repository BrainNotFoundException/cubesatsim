#include "forces.hpp"
#include "constants.hpp"

Eigen::Vector3d sim::gravity_acceleration(const Eigen::Vector3d &r)
{

    double r_mag = r.norm();
    Eigen::Vector3d gravity_accel = -sim::MU_EARTH * r / (r_mag * r_mag * r_mag);

    return gravity_accel;
}