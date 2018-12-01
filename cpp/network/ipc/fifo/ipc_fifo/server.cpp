#include "./common.h"

int main(void)
{
    if (!check_exist(SERVER_FIFO))
    {
        if(mkfifo(SERVER_FIFO, FILE_MODE) < 0 && errno != EEXIST)
            my_print("mkfifo error");
    }

    int read_fd = open(SERVER_FIFO, O_RDONLY);
    if(read_fd < 0)
        my_print("open fifo error");

    IPC_DATA client_msg;
    memset(&client_msg, 0, sizeof(client_msg));
    int read_bytes = 0;

    do{
        read_bytes = read(read_fd, &client_msg, sizeof(client_msg));
        if (read_bytes < 0)
        {
            close(read_fd);
            my_print("read from fifo error");
        }

        char *tmp_msg = client_msg.msg;
        while(*tmp_msg)
        {
            *tmp_msg = toupper(*tmp_msg);
            tmp_msg++;
        }

        char client_fifo[CLIENT_FIFO_NAME_LEN] = "";
        snprintf(client_fifo, CLIENT_FIFO_NAME_LEN-1, CLIENT_FIFO, client_msg.client_pid);

        int write_fd = open(client_fifo, O_WRONLY);
        if (write_fd < 0)
            my_print("write error");

        write(write_fd, &client_msg, sizeof(client_msg));
        cout << "write to client : " << client_msg.client_pid << endl;
        close(write_fd);
    }while(read_bytes > 0);

    close(read_fd);
    return 0;
}
