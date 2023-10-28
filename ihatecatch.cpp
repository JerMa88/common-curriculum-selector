#include <iostream>
#include "./datastructure/list.cpp"

int main() {
    // add test cases (create lists and specify what the expected output is)

    DSList<int> s;

    std::cout << "Checking that DSList works\n";

    // Test Case 1: Constructing List
    std::cout << "Constructing List\n";
    std::cout << "Initial size: " << (s.empty() ? "Empty" : "Not Empty") << "\n";
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);

    std::cout << "After adding elements: Size = " << s.size() << "\n";
    s.push_back(50);
    std::cout << "After pushing back 50: Size = " << s.size() << "\n";
    s.pop_back();
    std::cout << "After popping back: Size = " << s.size() << "\n";
    int pos = s.find_element(20);
    std::cout << "Position of 20 in LIST: " << pos << "\n";
    if (pos == 1) {
        std::cout << "Position is as expected\n";
    } else {
        std::cout << "Position is not as expected\n";
    }

    // Test Case 2: Checking Top
    std::cout << "Checking Top\n";
    int top = s.front();
    std::cout << "Top position in LIST: " << top << "\n";
    if (top == 10) {
        std::cout << "Top is as expected\n";
    } else {
        std::cout << "Top is not as expected\n";
    }

    // Test Case 3: Checking at()
    std::cout << "Checking at()\n";
    int one = s.at(0);
    int two = s.at(1);
    int three = s.at(2);
    int four = s.at(3);

    std::cout << "Position 1 in LIST: " << one << "\n";
    std::cout << "Position 2 in LIST: " << two << "\n";
    std::cout << "Position 3 in LIST: " << three << "\n";
    std::cout << "Position 4 in LIST: " << four << "\n";

    if (one == 40 && two == 30 && three == 20 && four == 10) {
        std::cout << "Positions are as expected\n";
    } else {
        std::cout << "Positions are not as expected\n";
    }

    // Test Case 4: Clear
    std::cout << "Clear\n";
    s.clear();
    std::cout << "After clearing: Size = " << s.size() << "\n";

    return 0;
}
