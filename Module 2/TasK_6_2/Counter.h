#pragma once
class Counter {
public:
    Counter(int init_count_value);
    Counter();
    int adder(char command);
private:
    int counter = 0;
};