
#ifndef _SALES_DATA_
#define _SALES_DATA_

#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
    public:
        // construct
        Sales_data() = default;
        Sales_data(const string &_bookNo)
            :bookNo(_bookNo)
        {}
        Sales_data(const string &_bookNo, unsigned _units_sold, double _revenue)
            :bookNo(_bookNo), units_sold(_units_sold), revenue(_revenue * _units_sold)
        {}
        Sales_data(istream &);

        // function
        string isbn() const { return bookNo; }
        Sales_data &combine(const Sales_data&);
    private:
        inline double avg_price() const;
        double avg_price() const
        {
            return units_sold ? revenue / units_sold : 0;
        }
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

    public:
        // friend function
        friend Sales_data add(const Sales_data &, const Sales_data &);
        friend ostream &print(ostream &, const Sales_data &);
        friend istream &read(istream &, Sales_data &);
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data &);
istream &read(istream &, Sales_data &);


#endif //_SALES_DATA_

/*
 * string Sales_data::isbn(const Sales_data *const this) { return this->bookNo; }
 */
