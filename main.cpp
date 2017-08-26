#include <iostream>
#include "TaskPoolManager.h"

using namespace std;

int main(int argc, char** argv) {
    srand(time(NULL));
    int numberOfThreads = atoi(argv[1]);
    int numberOfIterationsPerThread = atoi(argv[2]) / numberOfThreads;
    Task** monteCarloTasks = new Task*[numberOfThreads];
    for (int i = 0; i < numberOfThreads; ++i) {
        monteCarloTasks[i] = new MonteCarloTask(&numberOfIterationsPerThread);
    }
    TaskPoolManager taskPoolManager(numberOfThreads, monteCarloTasks);
    return 0;
}