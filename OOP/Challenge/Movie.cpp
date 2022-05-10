#include "Movie.h"
#include <utility>

// Constructors
Movie::Movie(std::string n, std::string r, unsigned short w)
       : name {std::move(n)}, rating {std::move(r)}, times_watched {w} {
}

Movie::Movie(const Movie &m)
       : Movie(m.name, m.rating, m.times_watched){
}

Movie::~Movie() = default;

// Methods
void Movie::set_name(std::string n) {
    name = std::move(n);
}

std::string Movie::get_name() const {
    return name;
}

void Movie::set_rating(std::string r) {
    rating = std::move(r);
}

std::string Movie::get_rating() const {
    return rating;
}

void Movie::set_times_watched(unsigned short times) {
    times_watched = times;
}

unsigned short Movie::get_times_watched() const {
    return times_watched;
}
