//
// Created by davidberiro on 1/17/17.
//

#include <algorithm>

#ifndef EX2_COORDINATE_H
#define EX2_COORDINATE_H

class Coordinate
{
public:
    char file;
    int rank;

    Coordinate(const char file, const int rank);

    Coordinate(const int file, const int rank);

    Coordinate(const Coordinate &other);

    bool operator==(const Coordinate &other);
    bool operator!=(const Coordinate &other);

    Coordinate &operator=(const Coordinate &other);

    Coordinate &operator=(Coordinate &&other);


};

#endif //EX2_COORDINATE_H
