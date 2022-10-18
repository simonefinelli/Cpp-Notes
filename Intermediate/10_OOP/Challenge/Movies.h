#ifndef CHALLENGE_MOVIES_H
#define CHALLENGE_MOVIES_H


#include <string>
#include <vector>
#include "Movie.h"


class Movies {
private:
    static unsigned short total_movies_watched;
    std::vector<Movie> movies = {};
    bool check_movie_by_name(const std::string& name);

public:
    // constructor
    Movies();

    // methods
    bool add_movie(
            std::string name, std::string rating, unsigned short times_watched);

    bool increment_watched(const std::string &name);

    void display_movies() const;

    static unsigned short get_total_watches();

};


#endif //CHALLENGE_MOVIES_H
