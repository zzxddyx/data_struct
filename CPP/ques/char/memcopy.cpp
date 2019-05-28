#include <iostream>

void* memcpy(void* memTo, const void* memFrom, size_t size)
{
    if (memTo == NULL || memFrom == NULL)
        return NULL;

    unsigned char* dest = (unsigned char*) memTo;
    const unsigned char* src = (const unsigned char*)memFrom;

    // 内存有重叠
    bool dest_flag = (dest >= src && dest < src + size);
    bool src_flag = (src >= dest && src < dest + size);

    if (dest_flag || src_flag)
        return NULL;

    while(size--)
    {
        *dest++ = *src++;
    }

    return dest;
}

int main(void)
{
    char src[] = "Hello Come on";
    char dest[1024] = "";
    memcpy(dest, src, sizeof(src));

    std::cout << dest << std::endl;

    return 0;
}
