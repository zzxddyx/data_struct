#include "Sale_date.h"

Sale_date::Sale_date(istream &is)
{
    read(is, *this);
}

istream &read(istream *is, Sale_date *item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sale_date &item)
{
    os << item.isbn() <<  ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price();
    return os;
}

double Sale_date::avg_price()
{
    
}
