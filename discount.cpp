#include "discount.h"

Discount::Discount(const QString & e, const double & d) : ean(e),
                                                          discount(d)
{

}

QString Discount::getEan() const
{
    return ean;
}

double Discount::getDiscount() const
{
    return discount;
}
