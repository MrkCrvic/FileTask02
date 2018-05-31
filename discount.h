#ifndef DISCOUNT_H
#define DISCOUNT_H

#include <QString>
#include <QDebug>
#include <QStringList>

class Discount
{
public:
    Discount() = default;
    Discount(const double & d);
    //QString getEan() const;
    const double & getDiscount() const;
private:
    //QString ean;
    double discount;
};

#endif // DISCOUNT_H
