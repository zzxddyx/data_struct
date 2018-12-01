#include "common.h"

int main(void)
{
    // 创建客户端的fifo
    pid_t client_pid = getpid();
    char client_fifo_name[CLIENT_FIFO_NAME_LEN] = "";
    snprintf(client_fifo_name, CLIENT_FIFO_NAME_LEN-1, CLIENT_FIFO, client_pid);
    if (!check_exist(client_fifo_name))
    {
        if(mkfifo(client_fifo_name, FILE_MODE) < 0)
            my_print("client mkfifo error");
    }

    // 打开服务端的fifo
    int write_fd = open(SERVER_FIFO, O_WRONLY);
    if (write_fd < 0)
        my_print("client open server fifo error");

    IPC_DATA client_msg;
    memset(&client_msg, 0, sizeof(client_msg));
    client_msg.client_pid = client_pid;

    for (int i = 0; i < 5; ++i)
    {
        snprintf(client_msg.msg, MSG_LEN, "client_pid:%d\n", client_pid);
        write(write_fd, &client_msg, sizeof(client_msg));

        int read_fd = open(client_fifo_name, O_RDONLY);
        if (read_fd < 0)
        {
            close(write_fd);
            unlink(SERVER_FIFO);
            my_print("open from server error");
        }

        int n = read(read_fd, &client_msg, sizeof(client_msg));
        if (n < 0)
            my_print("read from server error");
        if (n > 0)
            cout << "read from server info is : " << client_msg.msg << endl;

        close(read_fd);
    }

    close(write_fd);
    unlink(client_fifo_name);

    return 0;
}
