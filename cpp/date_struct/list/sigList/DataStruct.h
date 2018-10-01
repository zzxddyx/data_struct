#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

template<typename T>
struct DataStruct
{
    T data;
    struct DataStruct *next;
};

#endif //_DATA_STRUCT_H_
