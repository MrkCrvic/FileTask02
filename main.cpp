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

    QString itemFile = "items.csv";
    QString discountFile = "discount.csv";

    QStringList orderList;

    if(ReadCommandLineArguments(argc, argv, orderList))
    {
        ReadItems(itemFile, items);
        ReadDiscount(discountFile, discount);

        for(auto & orderFile : orderList)
        {
            ReadOrder(orderFile, order);
            Process(items, order, discount, bill);
            WriteBill(bill, "processed_" + orderFile);
            order.clear();
        }

    }

    return a.exec();
}
