#include "bill.h"

Bill::Bill(const QString & n, const double & t, const double & d, const double & p, const double & u, const double & q)
    : name(n), tax(t), discount(d), price(p), unitPrice(u), quantity(q)
{

}

//QString Bill::getEan() const
//{
//    return ean;
//}

const QString &Bill::getName() const
{
    return name;
}

const double &Bill::getTax() const
{
    return tax;
}

const double &Bill::getDiscount() const
{
    return discount;
}

const double &Bill::getPrice() const
{
    return price;
}

const double &Bill::getUnitPrice() const
{
    return unitPrice;
}

const double &Bill::getQuantity() const
{
    return quantity;
}
