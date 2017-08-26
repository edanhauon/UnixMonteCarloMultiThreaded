//
// Created by Edan Hauon on 25/08/2017.
//
#ifndef MONTECARLOTHREADS_TASKPOOLMANAGER_H

#define MONTECARLOTHREADS_TASKPOOLMANAGER_H

#include "queue"
#include "Task.h"
#include <pthread.h>
#include "MonteCarloTask.h"

using namespace std;


class TaskPoolManager {
private:
    queue<Task*> taskQueue;
    pthread_t* workerPool;
    pthread_mutex_t* lockFlagPool;
public:
    TaskPoolManager(int numberOfWorkers, Task** tasks);
};


#endif //MONTECARLOTHREADS_TASKPOOLMANAGER_H
