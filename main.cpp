#include <QCoreApplication>
//#include <QStringList>
//#include <QString>
//#include <QDebug>
#include <QMap>
#include <QMapIterator>
#include "item.h"
#include "functions.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, Item> items;
    QMap<QString, Order> order;
    QMap<QString, Discount> discount;
    QMap<QString, Bill> bill;

    QString itemFile = "C:\\Users\\mcorovic\\Desktop\\fileTask02\\items.csv";
    QString orderFile = "C:\\Users\\mcorovic\\Desktop\\fileTask02\\order_01.csv";
    QString discountFile = "C:\\Users\\mcorovic\\Desktop\\fileTask02\\discount.csv";
    QString billFile = "C:\\Users\\mcorovic\\Desktop\\fileTask02\\marko.csv";
    ReadItems(itemFile, items);
    ReadOrder(orderFile, order);
    ReadDiscount(discountFile, discount);
    Process(items, order, discount, bill);
    WriteBill(bill, billFile);

    return a.exec();
}
