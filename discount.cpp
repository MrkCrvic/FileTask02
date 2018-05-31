#include "discount.h"

Discount::Discount(const double & d) : discount(d)
{

}

//QString Discount::getEan() const
//{
//    return ean;
//}

const double &Discount::getDiscount() const
{
    return discount;
}
