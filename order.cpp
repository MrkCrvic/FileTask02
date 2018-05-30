#include "order.h"

Order::Order(const QString & e, const double & q) : ean(e),
                                         quantity(q)
{

}

QString Order::getEan() const
{
    return ean;
}

double Order::getQuantity() const
{
    return quantity;
}
