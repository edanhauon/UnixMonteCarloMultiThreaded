//
// Created by Edan Hauon on 25/08/2017.
//

#ifndef MONTECARLOTHREADS_TASK_H
#define MONTECARLOTHREADS_TASK_H

using namespace std;

class Task {
protected:
    void* arg;
public:
    Task(void* arg) : arg(arg) {}
    virtual void* operator()(void* _arg) = 0;
    static void* runner(void *_taskArg) {
        Task* task = static_cast<Task*>(_taskArg);
        return (*task)(task->arg);
    }
};


#endif //MONTECARLOTHREADS_TASK_H
