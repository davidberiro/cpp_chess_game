//
// Created by davidberiro on 1/17/17.
//

#include "Coordinate.h"

Coordinate::Coordinate(const char file, const int rank) {
    this->file = file;
    this->rank = rank;
}

Coordinate::Coordinate(const Coordinate &other) {
    this->file = other.file;
    this->rank = other.rank;
}

bool Coordinate::operator==(const Coordinate &other) {
    return this->file == other.file && this->rank == other.rank;
}

bool Coordinate::operator!=(const Coordinate &other) {
    // TODO: Use ==?
    return this->file != other.file || this->rank != other.rank;
}

Coordinate &Coordinate::operator=(const Coordinate &other)
{
    Coordinate temp = other;
    std::swap(*this, temp);
    return *this;
}

Coordinate &Coordinate::operator=(Coordinate &&other)
{
    if (*this != other)
    {
        this->rank = other.rank;
        this->file = other.file;
    }
    return *this;
}
