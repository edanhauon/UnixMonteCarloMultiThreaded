//
// Created by Edan Hauon on 25/08/2017.
//

#include <iostream>
#include <iomanip>
#include "TaskPoolManager.h"


TaskPoolManager::TaskPoolManager(int numberOfWorkers, Task** tasks) {
    workerPool = new pthread_t[numberOfWorkers];
    lockFlagPool = new pthread_mutex_t[numberOfWorkers];
    double sum = 0;
    for (int i = 0; i < numberOfWorkers; ++i) {
        pthread_create(&workerPool[i], NULL, Task::runner, tasks[i]);
    }
    for (int i = 0; i < numberOfWorkers; ++i) {
        pthread_join(workerPool[i], NULL);
    }
    for (int i = 0; i < numberOfWorkers; ++i) {
        sum += dynamic_cast<MonteCarloTask*>(tasks[i])->getResult();
        cout << dynamic_cast<MonteCarloTask*>(tasks[i])->getResult() / 100000000 << endl;
    }
    sum = sum / 100000000 * 4.0;
    cout << setprecision(13) << sum << endl;
    cout << setprecision(13) << 3.14159265359 - sum << endl;
}
