#include "order.h"

Order::Order(const double & q) : quantity(q)
{

}

//QString Order::getEan() const
//{
//    return ean;
//}

double Order::getQuantity() const
{
    return quantity;
}
