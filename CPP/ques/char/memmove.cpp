#include <iostream>

void* memmove(void* dest, const void* src, size_t size)
{
    if(NULL == dest || NULL == src)
        return NULL;

    unsigned char* memTo = (unsigned char*)dest;
    const unsigned char* memFrom = (const unsigned char*)src;

    bool dest_flag = (memTo >= memFrom && memTo < memFrom + size);
    bool src_flag = (memFrom >= memTo && memFrom < memTo + size);

    if (dest_flag || src_flag)
    {
        while(size--)
        {
           // memTo[size-1] = memFrom[size-1];
           *(memTo+size-1) = *(memFrom+size-1);
        }
    }
    else
    {
        while(size--)
            *memTo++ = *memFrom++;
    }

    return memTo;
}

int main(void)
{
    char src[] = "Hello Boy";
    char dest[1024] = "";

    memmove(dest, src, sizeof(src));
    std::cout << dest << std::endl;

    return 0;
}
