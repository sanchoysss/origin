#include "counter.h"

void Counter::add() {
    num++;
}

void Counter::subtract() {
    num--;
}

int Counter::get_current() {
    return num;
}

Counter::Counter(int user_num) {
    this->num = user_num;
}

Counter::Counter() {
    num = 1;
}