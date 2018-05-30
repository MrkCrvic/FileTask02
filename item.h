#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QDebug>
#include <QStringList>

class Item
{
public:
    Item() = default;
    Item(const QString & e, const QString & n, const double & p, const double & t);
    QString getEan() const;
    QString getName() const;
    double getPriceWo() const;
    double getTax() const;

private:
    QString ean;
    QString name;
    double priceWo;
    double tax;
};

#endif // ITEM_H
