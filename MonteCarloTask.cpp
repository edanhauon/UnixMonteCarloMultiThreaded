//
// Created by Edan Hauon on 26/08/2017.
//
#include "MonteCarloTask.h"

using namespace std;

void* MonteCarloTask::operator()(void *_arg) {
    int numberOfIteration = *static_cast<int *>(arg);
    result = 0;
    for (int i = 0; i < numberOfIteration; i ++) {
        srand(i * pthread_self()->__sig);
        double x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        double y = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        if (x * x + y * y <= 1.0) result++;
    }
    return NULL;
}
