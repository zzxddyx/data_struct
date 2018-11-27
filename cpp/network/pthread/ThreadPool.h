#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include <iostream>
#include <pthread.h>
#include <deque>
#include <string>
#include <cstdlib>
using namespace std;

namespace thread_pool
{
    class Task
    {
        public:
            Task(void *args, string taskName)
                :m_arg(args), m_taskName(taskName)
            {
            }
            virtual ~Task()
            {
            }

        public:
            void setArg(void *args)
            {
                m_arg = args;
            }
            virtual void run() = 0;

        private:
            void*       m_arg;
            string      m_taskName;
    };

    class ThreadPool
    {
        public:
            ThreadPool(int pthreadNum = 10);
            virtual ~ThreadPool();

        public:
            size_t  addTask(Task *task);
            void    stop();
            int     size();
            Task*   take();

        private:
            int createThreads();
            static void* threadFunc(void *threadData);

        private:
            volatile bool           m_isRunning;    // 是否在运行
            int                     m_threadNum;    // 线程个数
            pthread_t*              m_thread;       // 线程标识

            deque<Task*>            m_taskQueue;    
            pthread_mutex_t         m_mutex;
            pthread_cond_t          m_cond;
    };
}

#endif //_THREAD_POOL_H
