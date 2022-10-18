/******************************************************************
 * Section 13 Challenge
 * main.cpp
 *
 * Test the Movies project
 *
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

// function prototypes
void increment_watched(Movies &movies, const std::string &name);
void add_movie(Movies &movies, const std::string &name, const std::string &rating, int watched);


int main() {

    Movies my_movies;

    my_movies.display_movies();

    add_movie(my_movies,"The Lord of the Rings", "PG-13",5);
    add_movie(my_movies,"Pirates of Caribbean", "PG-13",1);
    add_movie(my_movies,"Lo Hobbit", "PG-13",3);

    my_movies.display_movies();   // Big, Star Wars, Cinderella

    add_movie(my_movies,"Lo Hobbit", "PG-13",3);
    add_movie(my_movies,"Harry Potter", "PG-13",1);

    my_movies.display_movies();

    increment_watched(my_movies,"The Lord of the Rings");
    increment_watched(my_movies,"Harry Potter");

    my_movies.display_movies();

    increment_watched(my_movies,"XXX");

    std::cout << "\nTotal movies watched: " << Movies::get_total_watches() << std::endl;

    return 0;
}


void increment_watched(Movies &movies, const std::string &name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}


void add_movie(Movies &movies, const std::string &name, const std::string &rating, int watched) {
    if (movies.add_movie(name, rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}
