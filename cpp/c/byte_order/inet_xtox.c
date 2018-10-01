#include <netdb.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char host[] = "www.sina.com";
    struct  hostent *ht = NULL;

    ht = gethostbyname(host);

    if (ht) 
    {
        printf("host : %s\n", host);
        printf("name : %s\n", ht->h_name);

        printf("type : %s\n", ht->h_addrtype);

        printf("length : %d\n", ht->h_length);

        int i = 0;
        for (i = 0 ; ; i++)
        {
            if (ht->h_addr_list[i] != NULL)
            {
                printf("IP : %s\n", inet_ntoa((unsigned int *)ht->h_addr_list[i]));
            }
            else
            {
                break;
            }
        }

        for (i = 0; ; i++)
        {
            if (ht->h_aliases[i] != NULL)
            {
                printf("Rname : %s\n", ht->h_aliases[i]);
            }
            else
            {
                break;
            }
        }

    }

    return 0;
}
