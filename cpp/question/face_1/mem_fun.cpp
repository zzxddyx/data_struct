#include<iostream>
using namespace std;

void* memcpy(void *dst, const void *src, size_t size)
{
    if(dst == NULL || src == NULL)
        return NULL;

    unsigned char *c_dst = (unsigned char *)dst;
    const unsigned char *c_src = (const unsigned char *)src;

    bool dst_size = (c_dst >= c_src && c_dst < c_src + size); 
    bool src_size = (c_src >= c_dst && c_src < c_dst + size);
    
    if(dst_size || src_size)
        return NULL;

    while(size--)
    {
        *dst++ = *src++;
    }

    return dst;
}

void *memmve(void *dst, const void *src, size_t size)
{
    if(dst == NULL || src == NULL)
        return NULL;

    unsigned char *p_dst = (unsigned char*)dst;
    const  unsigned char *p_src = (const unsigned char*)src;

    bool flag_dst = (p_dst >= p_src && p_dst < p_src + size);
    bool flag_src = (p_src >= p_dst && p_src < p_dst + size);

    if(flag_dst || flag_src)
    {
        while(size--)
        {
            *(dst+size-1) = *(src+size-1);
        }
    }
    else
    {
        while(size--)
        {
            *(dst++) = *(src++);
        }
    }
    return dst;
}

