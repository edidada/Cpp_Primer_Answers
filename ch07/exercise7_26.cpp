#include "exercise7_26.h"

// 实现 read 函数
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = item.units_sold * price;
    } else {
        item = Sales_data(); // 输入失败时，将对象重置为默认状态
    }
    return is;
}

// 实现 print 函数
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " ";
    if (item.units_sold) {
        os << item.avg_price();
    } else {
        os << "(no sales)";
    }
    return os;
}

// 实现 add 函数
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.units_sold += rhs.units_sold;
    sum.revenue += rhs.revenue;
    return sum;
}

// 实现 combine 成员函数
Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}