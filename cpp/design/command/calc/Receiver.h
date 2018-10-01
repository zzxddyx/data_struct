#ifndef _RECEIVER_H_
#define _RECEIVER_H_

class Receiver
{
    public:
        Receiver(int, int);

    public:
        void ExecAdd();
        void ExecSub();
        void ExecMul();
        void ExecDiv();

    private:
        int m_param1;
        int m_param2;
};

#endif //_RECEIVER_H_
