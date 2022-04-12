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
    double getLength() const override;
    Pose derivativeFromT(double t) const override;
    Pose pointFromT(double t) const override;
};




template<PathType A_path_t, PathType B_path_t>
double Combined<A_path_t, B_path_t>::getLength() const {
    return paths.first.getLength() + paths.second.getLength();
}

template<PathType A_path_t, PathType B_path_t>
Pose Combined<A_path_t, B_path_t>::derivativeFromT(double t) const {
    return Pose();
}

template<PathType A_path_t, PathType B_path_t>
Pose Combined<A_path_t, B_path_t>::pointFromT(double t) const {
    return t < 0.5 ? paths.first.pointFromT(t * 2) : paths.second.pointFromT((t * 2)-1);
}

#endif //PATHER_COMBINED_H
