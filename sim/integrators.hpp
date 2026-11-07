#pragma once

#include <Eigen/Dense>

namespace sim
{

    struct State
    {
        double t;
        Eigen::Vector3d r;
        Eigen::Vector3d v;
    };

    State euler_next_state(const State &state, double dt);

}