#ifndef DISCOUNT_H
#define DISCOUNT_H

#include <QString>
#include <QDebug>
#include <QStringList>

class Discount
{
public:
    Discount() = default;
    Discount(const QString & e, const double & d);
    QString getEan() const;
    double getDiscount() const;
private:
    QString ean;
    double discount;
};

#endif // DISCOUNT_H
