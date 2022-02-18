#include <gtest/gtest.h>

#include <iostream>
#include <fstream>

#include "day03_part2_functions.h"
 
TEST(Day3Part2Test, GivenTestDataOxygenGeneratorRatingIs23) 
{ 
    std::vector<std::string> diagnostic_report;

    const std::string filename{"../test-data.txt"}; 
    std::cout << "Opening file " << filename << std::endl;
    std::ifstream myfile(filename);

    std::string myline;
    while (std::getline(myfile, myline))
    {
        diagnostic_report.push_back(myline);
    }

    const int oxygen_rating = oxygen_generator_rating(diagnostic_report);

    ASSERT_EQ(oxygen_rating, 23);
}

TEST(Day3Part2Test, GivenTestDataCo2ScrubberRatingIs10) 
{ 
    std::vector<std::string> diagnostic_report;

    const std::string filename{"../test-data.txt"}; 
    std::cout << "Opening file " << filename << std::endl;
    std::ifstream myfile(filename);

    std::string myline;
    while (std::getline(myfile, myline))
    {
        diagnostic_report.push_back(myline);
    }

    const int co2_rating = co2_scrubber_rating(diagnostic_report);

    ASSERT_EQ(co2_rating, 10);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
