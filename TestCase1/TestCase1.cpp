// TestCase1.cpp : https://netology.ru/profile/program/job-tz-prog-cpp-1/lessons/433914/lesson_items/2341092
//

#include <iostream>
#include "IdentifierGenerator.h"

int main()
{
    IdentifierGenerator generator;
    std::string current_id = "A9";

    for (int i = 0; i < 1000; ++i) {
        current_id = generator.GenerateNextIdentifier(current_id);
        std::cout << current_id << std::endl;
    }
    return 0;
}