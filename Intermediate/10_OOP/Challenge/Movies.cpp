#include "Movies.h"
#include "Movie.h"
#include <iostream>


unsigned short Movies::total_movies_watched = 0;

// constructor
Movies::Movies() = default;

// methods
bool Movies::add_movie(
        std::string name, std::string rating, unsigned short times_watched) {

    // check if the movie already exist
    if (check_movie_by_name(name))
        return false;

    // create a new movie
    Movie movie = Movie(
            std::move(name), std::move(rating), times_watched);

    // update global counter to keep track of all watches
    total_movies_watched += times_watched;

    // update list
    movies.push_back(movie);

    return true;
}

bool Movies::increment_watched(const std::string &name) {
    for (auto &m : movies) {
        if (m.get_name() == name) {
            unsigned short times = m.get_times_watched();
            times++;
            m.set_times_watched(times);

            // update global counter
            total_movies_watched ++;

            return true;
        }
    }

    return false;
}

void Movies::display_movies() const {
    if (movies.empty())
        std::cout << "Sorry, no movies to display!\n\n";
    else {
        std::cout << "\n********** Movies List ***********" << std::endl;

        for (auto &m : movies)
            std::cout << m.get_name() << ", "
                      << m.get_rating() << ", "
                      << m.get_times_watched() << std::endl;

        std::cout << "************** End ***************\n\n";
    }

}

bool Movies::check_movie_by_name(const std::string &name) {
    for (const Movie &m : movies) {
        if (m.get_name() == name)
            return true;
    }

    return false;
}

unsigned short Movies::get_total_watches() {
    return total_movies_watched;
}
