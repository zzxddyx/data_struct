#include "./common.h"

int main(void)
{
    int msg_id = msgget(IPC_KEY, FILE_MODE | IPC_CREAT);
    if (msg_id < 0)
        my_print("proc2 msgget error");

    bool keep = true;
    while(keep)
    {
        MSG_DATA datas;
        memset(&datas, 0, sizeof(datas));
        datas.type = 3;
        datas.pid = getpid();

        char buf[MAX_SIZE] = "";
        fgets(buf, MAX_SIZE, stdin);
        strcpy(datas.data, buf);

        if(msgsnd(msg_id, &datas, sizeof(datas), 0) < 0)
            my_print("msgsnd error");

        memset(&datas, 0, sizeof(datas));
        if(msgrcv(msg_id, &datas, sizeof(datas), 0, 0) < 0)
            my_print("proc2 msgrcv error");

        cout << "recv from msg info is : " << " pid : " << datas.pid << " info's is : " << datas.data << endl;

        if(strncmp(datas.data, "quit", 4) == 0)
            keep = false;
    }

    if(msgctl(msg_id, IPC_RMID, NULL) < 0)
        my_print("proc2 msgctl error");

    return 0;
}
