#include "bill.h"

Bill::Bill(const QString & e, const QString & n, const double & t, const double & d, const double & p, const double & u, const double & q)
    : ean(e), name(n), tax(t), discount(d), price(p), unitPrice(u), quantity(q)
{

}

QString Bill::getEan() const
{
    return ean;
}

QString Bill::getName() const
{
    return name;
}

double Bill::getTax() const
{
    return tax;
}

double Bill::getDiscount() const
{
    return discount;
}

double Bill::getPrice() const
{
    return price;
}

double Bill::getUnitPrice() const
{
    return unitPrice;
}

double Bill::getQuantity() const
{
    return quantity;
}
