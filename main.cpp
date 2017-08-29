#include <iostream>
#include <iomanip>
#include "TaskPoolManager.h"

using namespace std;

int main(int argc, char** argv) {
    int numberOfThreads = atoi(argv[1]);
    int numberOfIterationsPerThread = atoi(argv[2]) / numberOfThreads;
    double sum = 0;
    Task** monteCarloTasks = new Task*[numberOfThreads];
    for (int i = 0; i < numberOfThreads; ++i) {
        monteCarloTasks[i] = new MonteCarloTask(&numberOfIterationsPerThread);
    }
    TaskPoolManager taskPoolManager(numberOfThreads, monteCarloTasks);
    for (int i = 0; i < numberOfThreads; ++i) {
        sum += dynamic_cast<MonteCarloTask*>(monteCarloTasks[i])->getResult();
    }
    sum = sum / numberOfIterationsPerThread / numberOfThreads * 4.0;
    cout << setprecision(13) << sum << endl << 3.14159265359 - sum << endl;
    return 0;
}