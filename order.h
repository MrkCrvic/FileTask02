#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QDebug>
#include <QStringList>

class Order
{
public:
    Order() = default;
    Order(const QString & e, const double & q);
    QString getEan() const;
    double getQuantity() const;

private:
    QString ean;
    double quantity;
};

#endif // ORDER_H
