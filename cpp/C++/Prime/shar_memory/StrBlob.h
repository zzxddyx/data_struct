#ifndef _STRBLOB_H_
#define _STRBLOB_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class StrBlob
{
    public:
        typedef vector<string>::size_type size_type;
    public:
        StrBlob();
        StrBlob(initialization_list<string> il);

        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }

        void push_back(const string *t) { data->push_back(t); }
        void pop_back();

        string &front();
        string &back();
    private:
        shared_ptr<vector<string>> data;
        void check(size_type t, const string &msg) const;
}

#endif //_STRBLOB_H_
