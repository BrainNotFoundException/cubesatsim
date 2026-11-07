#include <gtest/gtest.h>

#include <cmath>

#include "sim/constants.hpp"
#include "sim/forces.hpp"

TEST(Forces, GravityAcceleration)
{

    Eigen::Vector3d r(7000.0, 0.0, 0.0);
    Eigen::Vector3d expected_accel(-sim::MU_EARTH / (7000.0 * 7000.0), 0.0, 0.0);

    Eigen::Vector3d computed_accel = sim::gravity_acceleration(r);

    EXPECT_NEAR(computed_accel.x(), expected_accel.x(), 1e-7);
    EXPECT_NEAR(computed_accel.y(), expected_accel.y(), 1e-7);
    EXPECT_NEAR(computed_accel.z(), expected_accel.z(), 1e-7);
}