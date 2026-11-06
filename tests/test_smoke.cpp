// Smoke test: the toolchain works and the constants are sane.
//
// Your real Phase 1 tests go in new files here, e.g. test_forces.cpp and
// test_integrators.cpp. They are picked up automatically after you re-run the
// build. See docs/phase1/README.md for the list to aim for.
#include <gtest/gtest.h>

#include <cmath>
#include <numbers>

#include "sim/constants.hpp"

TEST(Smoke, StarterOrbitIsBoundAndNear95Minutes) {
  // Uses only the vis-viva relation, not a propagator.
  const double r = sim::STARTER_R0.norm();
  const double v = sim::STARTER_V0.norm();
  const double energy = v * v / 2.0 - sim::MU_EARTH / r;
  ASSERT_LT(energy, 0.0) << "starter state should be a bound orbit";

  const double a = -sim::MU_EARTH / (2.0 * energy);
  const double period_min =
      2.0 * std::numbers::pi * std::sqrt(a * a * a / sim::MU_EARTH) / 60.0;
  EXPECT_GT(period_min, 90.0);
  EXPECT_LT(period_min, 100.0);
}
