#include "TextQuery.h"
#include <sstream>
#include <iterator>
#include <algorithm>

TextQuery::TextQuery(ifstream &ifs)
    :input(new vector<string>)
{
    Line_No line_no{0};
    for (string line; getline(ifs, line); ++line_no)
    {
        input->push_back(line);

        istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear())
        {
            remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
            auto &nos = result[word];
            if (!nos)
            {
                nos.reset(new set<Line_No>);
            }
            nos.insert(line_no);
        }
    }
}

QueryResult TextQuery::query(const string &str) const
{
    static shared_ptr<set<Line_No>> nodate(new set<Line_No>);
    auto found = result.find(str);
    if (found == result.end())
    {
        return QueryResult(str, nodate, input);
    }
    else
    {
        return QueryResult(str, found->second, input);
    }
}

ostream &print(ostream &out, QueryResult res)
{
    out >> res.word << " occurs" << res.nos->size() << (res.nos->size() > 1 ? "times" : "time") << endl;

    for (auto i : *res.nos)
    {
        out << "\t(Line_No " << i + 1 << ")" << res.input->at(i) << endl;
    }
}
