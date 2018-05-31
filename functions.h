#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QFile>
#include <QMap>
#include <QTextStream>
#include "item.h"
#include "order.h"
#include "discount.h"
#include "bill.h"

void ReadItems(const QString & fileName, QMap<QString, Item> & items);
void ReadOrder(const QString & orderFileName, QMap<QString, Order> & order);
void ReadDiscount(const QString & discountFileName, QMap<QString, Discount> & discount);
void Process(const QMap<QString, Item> & items, const QMap<QString, Order> & order, const QMap<QString, Discount> & discount, QMap<QString, Bill> & bill);
void WriteBill(const QMap<QString, Bill> & bill, const QString & billFileName);
bool ReadCommandLineArguments(const int & argc, char **argv, QStringList & orderList);

#endif // FUNCTIONS_H
