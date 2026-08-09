#ifndef COUNTER_H
#define COUNTER_H
class Counter {
private:
    int num;

public:
    Counter();
    Counter(int user_num);

    void add();
    void subtract();
    int get_current();
};
#endif
