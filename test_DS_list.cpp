#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes
#include <cstddef>
#include "datastructure/list.h"

TEST_CASE("Check that DSList works", "[DSList]")
{
    // add test cases (create lists and specify what the expected output is)

    DSList<int> s;

    REQUIRE(s.empty() == true);
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);

    SECTION("Constructing List")
    {
        REQUIRE(s.size() == 4);
        s.push_back(50);
        REQUIRE(s.size() == 5);
        s.pop_back();
        REQUIRE(s.size() == 4);
        int pos = s.find_element(20);
        std::cout << "Position of 2 in LIST: " << pos << "\n";
        REQUIRE(pos == 1);
    }

    SECTION("Checking Top")
    {
        int top = s.front();
        std::cout << "Top position in LIST: " << top << "\n";
        REQUIRE(top == 10);
    }

    SECTION("Checking at()")
    {
        int one = s.at(0);
        int two = s.at(1);
        int three = s.at(2);
        int four = s.at(3);

        std::cout << "Position 1 in LIST: " << one << "\n";
        std::cout << "Position 2 in LIST: " << two << "\n";
        std::cout << "Position 3 in LIST: " << three << "\n";
        std::cout << "Position 4 in LIST: " << four << "\n";
        REQUIRE(one == 40);
        REQUIRE(two == 30);
        REQUIRE(three == 20);
        REQUIRE(four == 10);
    }

    SECTION("Clear")
    {
        s.clear();
        REQUIRE(s.size() == 0);
    }
}
// you can run the test using Run CTest in the task bar or by running the tests executable.