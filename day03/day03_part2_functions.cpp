// Thu 17 Feb 2022 10:18:19 GMT

#include <iostream>
#include <fstream>

#include "day03_part2_functions.h"

std::vector<int> tallyTheOnes(const std::vector<std::string> &data)
{
    std::vector<int> tally;
    tally.resize(data[0].size());
    for (const auto &v : data)
    {
        for (int i = 0; i < tally.size(); ++i)
        {
            tally[i] += (v[i] == '1');
        }
    }
    return tally;
}

int oxygen_generator_rating(std::vector<std::string> &diagnostic_report)
{
    int num_numbers = diagnostic_report.size();
    std::cout << "num_numbers=" << num_numbers << std::endl;

    int num_bits = diagnostic_report[0].size();
    std::cout << "num_bits=" << num_bits << std::endl;
   
    std::vector<std::string> oxygen = diagnostic_report;
    std::vector<int> ones;

    // Look at the oxygen data column by column
    for (int c = 0; c < num_bits; ++c)
    {
        // Update the tally for the new subset of data that is oxygen
        ones = tallyTheOnes(oxygen);

        // Based on the most common bit value, '0' or '1'
        // keep all rows where the digit matches by copying the rows to tmp
        // if 0 and 1 are equally common, keep values with a 1
        std::vector<std::string> tmp;
        std::copy_if(
            oxygen.begin(), 
            oxygen.end(), 
            std::back_inserter(tmp),
            [c, &ones, &oxygen](const std::string &s)
            {
                return (s[c] == (ones[c] >= (oxygen.size() - ones[c]) ? '1' : '0'));
            });

        // Update oxygen
        oxygen = tmp;

        if (oxygen.size() == 1)
        {
            std::cout << "Converged." << std::endl;
            break;
        }

    }
        
    std::cout << "oxygen: " << oxygen[0] << std::endl; 
    const int oxygen_rating = stoi(oxygen[0], nullptr, 2);
    std::cout << "oxygen_rating: " << oxygen_rating << std::endl; 

    return oxygen_rating;
}

int co2_scrubber_rating(std::vector<std::string> &diagnostic_report)
{
    int num_numbers = diagnostic_report.size();
    std::cout << "num_numbers=" << num_numbers << std::endl;

    int num_bits = diagnostic_report[0].size();
    std::cout << "num_bits=" << num_bits << std::endl;
   
    std::vector<std::string> co2 = diagnostic_report;
    std::vector<int> ones;

    // Look at the co2 data column by column
    for (int c = 0; c < num_bits; ++c)
    {
        // Update the tally for the new subset of data that is oxygen
        ones = tallyTheOnes(co2);

        // Based on the least common bit value, '0' or '1'
        // keep all rows where the digit matches by copying the rows to tmp
        // if 0 and 1 are equally common, keep values with a 0
        std::vector<std::string> tmp;
        std::copy_if(
            co2.begin(), 
            co2.end(), 
            std::back_inserter(tmp),
            [c, &ones, &co2](const std::string &s)
            {
                return (s[c] == (ones[c] >= (co2.size() - ones[c]) ? '0' : '1'));
            });

        // Update co2
        co2 = tmp;

        if (co2.size() == 1)
        {
            std::cout << "Converged." << std::endl;
            break;
        }

    }
        
    std::cout << "co2: " << co2[0] << std::endl; 
    const int co2_rating = stoi(co2[0], nullptr, 2);
    std::cout << "co2_rating: " << co2_rating << std::endl; 

    return co2_rating;
}

