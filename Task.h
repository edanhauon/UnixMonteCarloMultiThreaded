//
// Created by Edan Hauon on 25/08/2017.
//

#ifndef MONTECARLOTHREADS_TASK_H
#define MONTECARLOTHREADS_TASK_H

using namespace std;

class Task {
protected:
    void* arg;
    bool busy;
public:
    Task(void* arg) : arg(arg), busy(false) {}

    virtual void* operator()(void* _arg) = 0;
    static void* runner(void *_taskArg) {
        Task* task = static_cast<Task*>(_taskArg);
        task->busy = true;
        //Should implement queue extraction and start working here
        for(;;) {

        }
        task->busy = true;
//        return (*task)(task->arg);
        return NULL;
    }

    bool isBusy() const { return busy; }
};


#endif //MONTECARLOTHREADS_TASK_H
