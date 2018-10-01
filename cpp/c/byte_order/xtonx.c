#include <stdio.h>

typedef union
{
    unsigned long int value;
    unsigned char byte[4];
}byte32;

typedef union
{
    unsigned short int value;
    unsigned char byte[2];
}byte16;

void show(unsigned char *value, int num)
{
    int i = 0;
    for (i = 0; i < num; ++i)
    {
        printf("%x", value[i]);
    }
    printf("\n");
}

int main(void)
{
    byte32 o32, l32, t32;
    byte16 o16, l16, t16;

    o32.value = 0x12345678;
    o16.value = 0xabcd;

    l32.value = htonl(o32.value);
    t32.value = htonl(l32.value);

    show(o32.byte, 4);
    show(l32.byte, 4);
    show(t32.byte, 4);



    return 0;
}
