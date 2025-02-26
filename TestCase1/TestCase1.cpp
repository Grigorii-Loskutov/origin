// Пример тестового задания от Нетологии
// «Создание собственного алфавита идентификаторов»
// https://netology.ru/profile/program/job-tz-prog-cpp-1/lessons/433914/lesson_items/2341092

#include <iostream>
#include <windows.h>
#include "IdentifierGenerator.h"

int main()
{
    IdentifierGenerator generator;
    std::string current_id = "A1";

    for (int i = 0; i < 10000; ++i) {
       current_id = generator.GenerateNextIdentifier(current_id);
        std::cout << current_id << std::endl;
        //Sleep(1);
    }
   // std::cout << generator.GenerateNextIdentifier(current_id);

    return 0;
}
