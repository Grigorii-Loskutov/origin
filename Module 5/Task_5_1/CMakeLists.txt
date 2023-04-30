cmake_minimum_required(VERSION 3.20)
project(Task_5_1)
add_executable(Task_5_1 main.cpp)
add_subdirectory(e:/Sources/libpqxx-7.7.5 libpqxx-build) # Укажите путь к libpq++
target_compile_features(Task_5_1 PRIVATE cxx_std_17) # Включите C++17
target_link_libraries(Task_5_1 pqxx) # Слинкуйте libpq++ к проекту