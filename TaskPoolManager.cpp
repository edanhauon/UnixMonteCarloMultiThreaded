//
// Created by Edan Hauon on 25/08/2017.
//

#include <iostream>
#include "TaskPoolManager.h"

TaskPoolManager::TaskPoolManager(int numberOfWorkers, Task** tasks) :
        workerPool(new pthread_t[numberOfWorkers]){
    for (int i = 0; i < numberOfWorkers; ++i) {
        pthread_create(&workerPool[i], NULL, Task::runner, tasks[i]);
    }
//    for (int i = 0; i < numberOfWorkers; ++i) {
//        pthread_join(workerPool[i], NULL);
//    }
}

void TaskPoolManager::run() {
    while (!taskQueue.empty()) {
        
    }

}
