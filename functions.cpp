#include "functions.h"

void ReadItems(const QString & fileName, QMap<QString, Item> & items)
{
    QFile itemsFile(fileName);

    if(!itemsFile.open(QFile::ReadOnly))
        qDebug() << "Cannot open file for reading items!";
    else
    {
        qDebug() << "File with items successfully opened!";
        QTextStream line(&itemsFile);

        while(!line.atEnd())
        {
            QString stringLine = line.readLine();
            QStringList list = stringLine.split(';');
            QString price = list.at(2);
            QString tax = list.at(3);

            items.insert(list.at(0), Item(list.at(0), list.at(1), price.toDouble(), tax.toDouble()));
            //qDebug() << list.at(0) << list.at(2);
        }

    }

}

void ReadOrder(const QString & orderFileName, QMap<QString, Order> & order)
{
    QFile orderFile(orderFileName);

    if(!orderFile.open(QFile::ReadOnly))
        qDebug() << "Cannot open file for reading orders!";
    else
    {
        qDebug() << "File with orders successfully opened!";
        QTextStream line(&orderFile);

        while(!line.atEnd())
        {
            QString stringLine = line.readLine();
            QStringList list = stringLine.split(';');
            QString quant = list.at(1);

            order.insert(list.at(0), Order(list.at(0), quant.toDouble()));
            //qDebug() << list.at(0) << list.at(1);
        }
    }
}

void ReadDiscount(const QString &discountFileName, QMap<QString, Discount> &discount)
{
    QFile discountFile(discountFileName);

    if(!discountFile.open(QFile::ReadOnly))
        qDebug() << "Cannot open file for reading discounts!";
    else
    {
        qDebug() << "File with discounts successfully opened!";
        QTextStream line(&discountFile);

        while(!line.atEnd())
        {
            QString stringLine = line.readLine();
            QStringList list = stringLine.split(';');

            discount.insert(list.at(0), Discount(list.at(0), list.at(1).toDouble()));
            //qDebug() << list.at(0) << list.at(1);
        }
    }
}

void WriteBill(const QMap<QString, Bill> & bill, const QString & billFileName)
{
    // fout writing
    QFile billFile(billFileName);
    if(!billFile.open(QFile::WriteOnly))
    {
        qDebug() << "Cannot open file for writing bill!";
    }
    else
    {
        qDebug() << "Output file successfully opened for writing!";

        QTextStream out(&billFile);
        QString fHeader = "#name,   #tax,   #discount,   #unit price,   #quantity,   #price\n";
        out << fHeader;
        double totalPrice = 0;

        for(auto iter: bill.keys())
        {
            totalPrice += bill[iter].getPrice();
            out << bill[iter].getName() << ";   "
                << bill[iter].getTax() << ";   "
                << bill[iter].getDiscount() << ";   "
                << bill[iter].getUnitPrice() << ";   "
                << bill[iter].getQuantity() << ";   "
                << bill[iter].getPrice() << "\n";
        }
        QString fFooter = "Total -------------------------";
        out << fFooter << totalPrice;
        qDebug() << "Output file successfully written!";
        billFile.flush();
        billFile.close();
    }
}

void Process(const QMap<QString, Item> & items, const QMap<QString, Order> &order, const QMap<QString, Discount> &discount, QMap<QString, Bill> & bill)
{
    for(auto iter : order.keys())
    {
        if(items.contains(iter))
        {
            Item item = items[iter];
            double price = 0;
            double totalPrice = 0;

            if(discount.contains(iter))
            {
                // with discount
                price = item.getPriceWo() * ( 1 + item.getTax()/100) * ( 1 - discount[iter].getDiscount()/100);
            }
            else
            {
                // without discount
                price = item.getPriceWo() * ( 1 + item.getTax());
            }
            bill.insert(iter, Bill(iter, item.getName(), item.getTax(), discount[iter].getDiscount(), price*order[iter].getQuantity(), price, order[iter].getQuantity()));
        }
        else
        {
            qDebug() << "There is no product with EAN-13 " << iter << " in our shop";
        }
    }
}
