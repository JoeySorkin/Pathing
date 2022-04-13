//
// Created by Joey Sorkin on 4/11/22.
//

#ifndef PATHER_COMBINED_H
#define PATHER_COMBINED_H
#include <concepts>

#include "../../core/Path.h"

template<class T>
concept PathType = std::is_base_of<Path, T>::value;


template<PathType A_path_t, PathType B_path_t>
class Combined : public Path {
    std::pair<A_path_t, B_path_t> paths;
public:
    Combined(A_path_t a, B_path_t b):paths({a,b}){};
    Combined(A_path_t a); //not finished
    [[nodiscard]] double getLength() const override;
    [[nodiscard]] Pose derivativeFromT(double t) const override;
    [[nodiscard]] Pose pointFromT(double t) const override;
    [[nodiscard]] Pose dubderivativeFromT(double t) const override;
    [[nodiscard]] double getTfromDistance(double distance) override;
    Pose getOrigin() override;
    Pose getDestination() override;
};

template<PathType A_path_t, PathType B_path_t>
Pose Combined<A_path_t, B_path_t>::getOrigin() {
    return paths.first.getOrigin();
}
template<PathType A_path_t, PathType B_path_t>
Pose Combined<A_path_t, B_path_t>::getDestination() {
    return paths.second.getDestination();
}
template<PathType A_path_t, PathType B_path_t>
double Combined<A_path_t, B_path_t>::getLength() const {
    return paths.first.getLength() + paths.second.getLength();
}

template<PathType A_path_t, PathType B_path_t>
Pose Combined<A_path_t, B_path_t>::derivativeFromT(double t) const {
    return t < 0.5 ? paths.first.derivativeFromT(t * 2) : paths.second.derivativeFromT((t * 2)-1);
}

template<PathType A_path_t, PathType B_path_t>
Pose Combined<A_path_t, B_path_t>::pointFromT(double t) const {
    return t < 0.5 ? paths.first.pointFromT(t * 2) : paths.second.pointFromT((t * 2)-1);
}

template<PathType A_path_t, PathType B_path_t>
Pose Combined<A_path_t, B_path_t>::dubderivativeFromT(double t) const {
    return t < 0.5 ? paths.first.dubderivativeFromT(t * 2) : paths.second.dubderivativeFromT((t * 2)-1);
}

//TODO: Generate Continued Paths!
template<PathType A_path_t, PathType B_path_t>
Combined<A_path_t, B_path_t>::Combined(A_path_t a) {
    a.derivativeFromT(1);
}

template<PathType A_path_t, PathType B_path_t>
double Combined<A_path_t, B_path_t>::getTfromDistance(double distance) {
    return distance < paths.first.getLength() ? paths.first.getTfromDistance(distance) : paths.second.getTfromDistance(distance);
}

#endif //PATHER_COMBINED_H
