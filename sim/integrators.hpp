#include <vector>
#include <Eigen/Dense>

namespace sim
{

    struct State
    {
        double t;
        Eigen::Vector3d r;
        Eigen::Vector3d v;
    };


    std::vector<State> path_history;

    State euler_next_state(const State &state, double dt);

}