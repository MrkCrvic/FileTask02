#ifndef BILL_H
#define BILL_H

#include <QString>
#include <QDebug>
#include <QStringList>

class Bill
{
public:
    Bill(){}
    Bill(const QString & n, const double & t, const double & d, const double & p, const double & u, const double & q);
    //QString getEan() const;
    const QString & getName() const;
    const double & getTax() const;
    const double & getDiscount() const;
    const double & getPrice() const;
    const double & getUnitPrice() const;
    const double & getQuantity() const;

private:
    //QString ean;
    QString name;
    double tax;
    double discount;
    double price;
    double unitPrice;
    double quantity;

};

#endif // BILL_H
