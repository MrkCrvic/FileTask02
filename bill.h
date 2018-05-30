#ifndef BILL_H
#define BILL_H

#include <QString>
#include <QDebug>
#include <QStringList>

class Bill
{
public:
    Bill() = default;
    Bill(const QString & e, const QString & n, const double & t, const double & d, const double & p, const double & u, const double & q);
    QString getEan() const;
    QString getName() const;
    double getTax() const;
    double getDiscount() const;
    double getPrice() const;
    double getUnitPrice() const;
    double getQuantity() const;

private:
    QString ean;
    QString name;
    double tax;
    double discount;
    double price;
    double unitPrice;
    double quantity;

};

#endif // BILL_H
