#include <stdio.h>

typedef union
{
    unsigned short int value;
    unsigned char byte[2];
}byte;

int main(void)
{
    byte test_value;

    test_value.value = 0xabcd;

    if (test_value.byte[0] == 0xcd && test_value.byte[1] == 0xab)
    {
        printf("Low Order : byte[0] : 0x%x, byte[1] : 0x%x\n", test_value.byte[0], test_value.byte[1]);
    }   

    if (test_value.byte[0] == 0xab && test_value.byte[1] == 0xcd)
    {
        printf("High Order : byte[0] : 0x%x, byte[1] : 0x%x\n", test_value.byte[0], test_value.byte[1]);
    }

    return 0;
}
