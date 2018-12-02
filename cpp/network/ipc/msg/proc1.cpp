#include "./common.h"

int main(void)
{
    int msg_id = msgget(IPC_KEY, FILE_MODE | IPC_CREAT);
    if (msg_id < 0)
        my_print("msgget error");

    bool keep = true;
    while(keep)
    {
        MSG_DATA datas;
        memset(&datas, 0, sizeof(datas));

        char buf[MAX_SIZE] = "";
        datas.pid = getpid();
        datas.type = 2;
        fgets(buf, MAX_SIZE, stdin);
        strcpy(datas.data, buf);

        if(msgsnd(msg_id, &datas, sizeof(datas), 0) < 0)
            my_print("msgsnd error");

        if(msgrcv(msg_id, &datas, sizeof(datas), 0, 0) < 0)
            my_print("proc1 msgrcv error");
        cout << "recv from msg info is : " << " pid : " << datas.pid << " info's is : " << datas.data << endl;

        if(strncmp(datas.data, "quit", 4) == 0)
        {
            keep = false;
        }
    }

    if(msgctl(msg_id, IPC_RMID, NULL) < 0)
        my_print("msgctl delete error");

    return 0;
}
