//
// Created by Edan Hauon on 26/08/2017.
//

#ifndef MONTECARLOTHREADS_MONTECARLOTASK_H
#define MONTECARLOTHREADS_MONTECARLOTASK_H

#include <iostream>
#include "Task.h"

using namespace std;

class MonteCarloTask : public Task {
private:
    double result;
public:
    MonteCarloTask(void* arg) : Task(arg) {}
    void* operator()(void* _arg);
    double getResult() const { return result; }
};


#endif //MONTECARLOTHREADS_MONTECARLOTASK_H
