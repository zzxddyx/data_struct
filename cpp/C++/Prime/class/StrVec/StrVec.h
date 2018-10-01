#ifndef _STRVEC_H_
#define _STRVEC_H_

#include <iostream>
#include <memory>

class StrVec
{
    public:
        StrVec() //allocator成员进行默认初始化
            :elements(nullptr), first_free(nullptr), cap(nullptr)
        {}
        StrVec(const StrVec&);
        StrVec &operator=(const StrVec &);
        ~StrVec();

    public:
        void push_back(const string &);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        string *begin() const { return elements; }
        string *end() const { return first_free; }

    private:
        static allocator<string> alloc;  
        string *elements;
        string *first_free;
        string *cap;

    private:
        void chk_n_alloc()
        {
            if (size() == capacity()) { reallocate(); }
        }

        pair<string*, string*> alloc_n_copy(const string *, const string *);
        void free();
        void reallocate();


        
};

#endif //_STRVEC_H_
