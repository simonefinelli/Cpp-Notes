// Challenge 1
// Formatting output

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct City {
    std::string name;
    long population;
    double cost;
};

struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

struct Tours get_tours() {
    Tours tours{
        "Tour Ticket Prices from Miami",
        {
            {
                "Colombia",
                {
                    {"Bogota", 8778000, 400.98},
                    {"Cali", 2401000, 424.12},
                    {"Medellin", 2464000, 350.98},
                    {"Cartagena", 972000, 345.34}
                },
            },
            {
                "Brazil",
                {
                    {"Rio De Janeiro", 13500000, 567.45},
                    {"Sao Paulo", 11310000, 975.45},
                    {"Salvador", 18234000, 855.99}
                },
            },
            {
                "Chile",
                {
                    {"Valdivia", 260000, 569.12},
                    {"Santiago", 7040000, 520.00}
                },
            },
            {
                "Argentina",
                {
                    {"Buenos Aires", 3010000, 723.77}
                }
            },
        }
    };

    return tours;
}

void ruler() {
    cout << "\n---------*---------*---------*---------*---------*---------*---------*" << endl;
}

const size_t TABLE_WITH {65};
const size_t COUNTRY_COL_WITH {18};
const size_t CITY_COL_WITH {22};
const size_t POPULATION_COL_WITH {12};
const size_t PRICE_COL_WITH = {13};

void draw_title(const std::string &title) {
    size_t title_length = title.size();
    size_t total_padding = TABLE_WITH - title_length;
    int padding_left = int(total_padding / 2);
    int padding_right = int(total_padding - padding_left);
    padding_left--;  // to make space
    padding_right--;  // to make space

    std::cout << std::setfill('=');
    std::cout << std::setw(padding_left) << ""
              << " " << title << " "
              << std::setw(padding_right) << ""
              << "\n" << std::endl;
    std::cout << std::setfill(' '); // reset
}

void draw_header() {
    std::cout << std::setw(COUNTRY_COL_WITH)
              << std::left
              << "Country"
              << std::setw(CITY_COL_WITH)
              << std::left
              << "City"
              << std::setw(POPULATION_COL_WITH)
              << std::right
              << "Population"
              << std::setw(PRICE_COL_WITH)
              << std::right
              << "Price"
              << std::endl;

    std::cout << std::setfill('-');
    std::cout << std::setw(TABLE_WITH) << "" << std::endl;
    std::cout << std::setfill(' '); // reset

}

void draw_single_record(
        const std::string &country_name,
        const std::string &city_name,
        long city_population,
        double city_cost) {

    std::cout << std::setw(COUNTRY_COL_WITH)
              << std::left
              << country_name
              << std::setw(CITY_COL_WITH)
              << std::left
              << city_name
              << std::setw(POPULATION_COL_WITH)
              << std::right
              << city_population
              << std::setw(PRICE_COL_WITH)
              << std::right
              << std::setprecision(2) << std::fixed << city_cost
              << std::endl;
}

void draw_data(const Tours &tours) {
    std::string country_name;
    size_t counter;

    for (const auto &country: tours.countries) {
        counter = 0;
        for (const auto &city: country.cities) {
            country_name = (counter == 0) ? country.name : "";

            draw_single_record(
                    country_name, city.name, city.population, city.cost);

            counter++;
        }
    }
}


int main()
{
    // ruler();

    // get data
    Tours tours = get_tours();

    // draw data in a formatted table
    draw_title(tours.title);
    draw_header();
    draw_data(tours);

    return 0;
}