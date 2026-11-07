#pragma once

#include "integrators.hpp"
#include <vector>

namespace sim
{

    std::vector<State> propagate(State state0, double dt, int steps);

}