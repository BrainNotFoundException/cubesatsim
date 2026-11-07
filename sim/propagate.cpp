#include "propagate.hpp"

std::vector<sim::State> sim::propagate(State state0, double dt, int steps)
{

    std::vector<State> path_history;
    path_history.reserve(steps + 1);
    path_history.push_back(state0);

    State current_state = state0;
    for (int i = 0; i < steps; i++)
    {
        current_state = euler_next_state(current_state, dt);
        path_history.push_back(current_state);
    }

    return path_history;
}
