#ifndef LOCK_GUARD_H
#define LOCK_GUARD_H

#include<mutex>
#include<thread>

class loguard
{

public:
    loguard ()
    {
        my_mutex.lock();
    }

    ~loguard ()
    {
        my_mutex.unlock();
    }

private:
    std::mutex my_mutex;
};


#endif // LOCK_GUARD_H

