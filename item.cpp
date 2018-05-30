#include "item.h"

Item::Item(const QString & e, const QString & n, const double & p, const double & t) : ean(e),
                                       name(n),
                                       priceWo(p),
                                       tax(t)
{

}

QString Item::getEan() const
{
    return ean;
}

QString Item::getName() const
{
    return name;
}

double Item::getPriceWo() const
{
    return priceWo;
}

double Item::getTax() const
{
    return tax;
}
