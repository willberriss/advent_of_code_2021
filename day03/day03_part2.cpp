// Thu 17 Feb 2022 10:18:19 GMT

#include <iostream>
#include <fstream>

#include "day03_part2_functions.h"

int main (int argc, char *argv[])
{
    assert(argc == 2);

    std::vector<std::string> diagnostic_report;

    std::cout << "Opening file " << argv[1] << std::endl;
    std::ifstream myfile(argv[1]);

    std::string myline;
    while (std::getline(myfile, myline))
    {
        diagnostic_report.push_back(myline);
    }

    const int oxygen_rating = oxygen_generator_rating(diagnostic_report);
    const int co2_rating = co2_scrubber_rating(diagnostic_report);

    const int life_support_rating = oxygen_rating * co2_rating;

    std::cout << "life_support_rating: " << life_support_rating << std::endl;

    return 0;
}

