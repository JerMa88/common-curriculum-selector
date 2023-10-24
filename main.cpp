#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>

#include "data/list_CC_req.h"
#include "algorithm/db2ds.h"
#include "algorithm/interceptor.h"
#include "datastructure/multi_linked_list.h"

int main(){
    std::cout << "Initializing Program";




//UI----------------------------------------------------------------------------------------------------------------
    // Welcome message
    std::cout << "Thanks for using common-curriculum-selector!\n";
    std::cout << "So you are a SMU student wanting to fulfill your Common Curriclum Credits?\n";
    std::cout << "Well, you've come to the right place!\n";
    std::cout << "Just tell me the Breadths and proficiencies that you need to take and I will give you the most efficient ways to do CC while taking fun classes YOU are interested in!\n";

    // Explain Common Curriculum
    std::cout << "The Common Curriculum is a set of courses that all SMU students must take in order to graduate.\n";
    std::cout << "There are 3 types of Common Curriculum courses: Foundations, Breadths, and Proficiencies.\n";
    std::cout << "Foundations are courses that all students must take. There are 4 Foundations: Academic Writing, Critical Reasoning, Quantitative Reasoning, and Second Language.\n";
    std::cout << "Breadths are courses that all students must take. There are 8 Breadths: Creativity and Aesthetics, Exploring Science, Historical Contexts, Literature Analysis and Interpretation, Social and Behavioral Sciences, Tech Advances and Society, and 2 Second Language Breadths.\n";
    std::cout << "Proficiencies are courses that all students must take. There are 6 Proficiencies: Community Engagement, Civics and Individual Ethics, Global Perspectives, Human Diversity, Oral Communication, and Writing.\n";\
    std::cout << "Each course can PROBABLY fulfill multiple Breadths and Proficiencies.\n";
    std::cout << "Now for simplicity's sake, here are the abbreviations for each Common Curriculum course:\n";

    // Print out Common Curriculum abbreviations
    listCCReq cc;
    cc.printCC();

    // Ask user for input
    std::cout << "Now, please enter the Abbreivations of the Foundations Breadths and Proficiencies that you still need to take.\n";
    std::cout << "Please enter them in the format shown above (ALL CAPITALIZED LETTERS PLEASE). Write \"quit\" if you have finished filling in your CC requirements.\n";

    std::vector<CCReq> userQuery;
    std::string input = "";
    while (input != "quit") {
        std::getline(std::cin, input);
        CCReq enumValue = stringToCCReq(input);

        if (enumValue == CCReq::INVALID) {
            std::cout << "Invalid input. Please try again.\n";
        } else {
            userQuery.push_back(enumValue);
        }
    }

    std::cout << "You have entered the following CC requirements:\n";
    for (auto req : userQuery) {
        std::cout << req << std::endl;
    }
    std::cout << "Finding the most efficient way to fulfill your CC requirements";

//Algorithm----------------------------------------------------------------------------------------------------------
    // data structure prebuilt from database
    // multi_linked_list<CCReq> database = db2ds();

    Interceptor ntrcptr;
    ntrcptr.setQuery(userQuery);

    ntrcptr.intercept();

    std::cout << "Here are the most efficient ways to fulfill your CC requirements:\n";
    ntrcptr.print();


    std::string fileDir = "report_" + std::to_string(std::time(nullptr)) + ".txt";
    ntrcptr.printToFileDir(fileDir);
    std::cout << "For your reference, a report was generated to file directory" << fileDir << "\n";

    std::cout << "Thanks for using common-curriculum-selector!\nPlease give me a feedback in one line on how I did XD\n";

    std::getline(std::cin, input);

    std::ofstream file;
    file.open("feedback.txt", std::ios::app);
    file << std::time(nullptr) << " " << input << "\n";
    file.close();

    std::cout << "Thanks for your feedback! Have a nice day!\n";

    return 0;
}
