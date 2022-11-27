#include "Counter.h"

Counter::Counter(int init_count_value) {
    if (init_count_value == 0) {
        this->counter = 1;
    }
    else {
        this->counter = init_count_value;
    }
}
Counter::Counter() {
    counter = 1;
}
int Counter::adder(char command) {
    switch (command) {
    case '+':
        counter++;
        break;
    case '-':
        counter--;
        break;
    case '=':
        return counter;
        break;
    default:
        nullptr;
    }
}
