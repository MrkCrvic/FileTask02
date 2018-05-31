#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QDebug>
#include <QStringList>

class Item
{
public:
    Item() = default;
    Item(const QString & n, const double & p, const double & t);
    //QString getEan() const;
    const QString & getName() const;
    const double & getPriceWo() const;
    const double & getTax() const;

private:
    //QString ean;
    QString name;
    double priceWo;
    double tax;
};

#endif // ITEM_H
