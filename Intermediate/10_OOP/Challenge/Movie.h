#ifndef CHALLENGE_MOVIE_H
#define CHALLENGE_MOVIE_H


#include <string>

/**
 * Movie Class manipulate a real world movie.
 *
 * Each movie has:
 *  - string name,
 *  - string rating - (G, PG, PG-13, R, NC-17)
 *  - int times_watched - the number of times the movie is been watched.
 */
class Movie {
private:
    std::string name;
    std::string rating;
    unsigned short times_watched;

public:
    // constructor
    Movie(std::string n, std::string r, unsigned short times_watched);
    // copy constructor
    Movie(const Movie &m);  // not implemented

    void set_name(std::string n);
    [[nodiscard]] std::string get_name() const;  // [[nodiscard]] C++17

    void set_rating(std::string r);
    [[nodiscard]] std::string get_rating() const;

    void set_times_watched(unsigned short times);
    [[nodiscard]] unsigned short get_times_watched() const;

    // destructor
    ~Movie();  // not implemented - no pointers to delete
};


#endif // CHALLENGE_MOVIE_H
