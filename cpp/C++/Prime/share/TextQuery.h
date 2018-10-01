#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
using namespace std;

class QueryResult;
class TextQuery
{
    public:
        using Line_No = vector<string>::size_type;
        TextQuery(ifstream &);
        QueryResult query(const string&) const;

    private:
        shared_ptr<vector<string>> input;
        map<string, shared_ptr<set<Line_No>>> result;
};

class QueryResult
{
    public:
        QueryResult(const string &_word, shared_ptr<set<TextQuery::Line_No>> _pos, shared_ptr<vector<string>> _input)
            :word(_word), nos(_pos), input(_input)
        {}

    public:
        friend ostream& print(ostream &, QueryResult &);

    private:
        string word;
        shared_ptr<set<TextQuery::Line_No>> nos;
        shared_ptr<vector<string>> input;
};

ostream &print(ostream &, QueryResult &);

#endif //_TEXTQUERY_H_

