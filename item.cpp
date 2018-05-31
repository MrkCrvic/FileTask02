#include "item.h"

Item::Item(const QString & n, const double & p, const double & t) :
                                       name(n),
                                       priceWo(p),
                                       tax(t)
{

}

//QString Item::getEan() const
//{
//    return ean;
//}

const QString &Item::getName() const
{
    return name;
}

const double &Item::getPriceWo() const
{
    return priceWo;
}

const double &Item::getTax() const
{
    return tax;
}
