#ifndef LOCK_GUARD_H
#define LOCK_GUARD_H

#include<mutex>
#include<thread>

class loguard
{

public:
    loguard (std::mutex *my_m)
    {
        my_mutex = my_m;
        my_mutex->lock();
    }

    ~loguard ()
    {
        my_mutex->unlock();
    }

private:
    std::mutex *my_mutex;
};


#endif // LOCK_GUARD_H

