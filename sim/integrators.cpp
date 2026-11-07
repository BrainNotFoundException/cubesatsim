#include "integrators.hpp"
#include "forces.hpp"

sim::State sim::euler_next_state(const State &state, double dt)
{
    State next_state;
    next_state.t = state.t + dt;
    next_state.r = state.r + state.v * dt;
    next_state.v = state.v + gravity_acceleration(state.r) * dt;
    return next_state;
}