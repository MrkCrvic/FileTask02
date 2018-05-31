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
            QString ean = list.at(0);
            QString name = list.at(1);
            QString price = list.at(2);
            QString tax = list.at(3);

            items.insert(ean, Item(name, price.toDouble(), tax.toDouble()));
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
            QString ean = list.at(0);
            QString quant = list.at(1);

            order.insert(ean, Order(quant.toDouble()+order[ean].getQuantity()));
            //qDebug() << ean << quant.toDouble();
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
            QString ean = list.at(0);
            QString discount_value = list.at(1);

            discount.insert(ean, Discount(discount_value.toDouble()));
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

        for(auto & key: bill.keys())
        {
            totalPrice += bill[key].getPrice();
            out << bill[key].getName() << ";   "
                << bill[key].getTax() << ";   "
                << bill[key].getDiscount() << ";   "
                << bill[key].getUnitPrice() << ";   "
                << bill[key].getQuantity() << ";   "
                << bill[key].getPrice() << "\n";
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
    for(auto & key : order.keys())
    {
        if(items.contains(key))
        {
            Item item = items[key];
            double price = 0;
            double totalPrice = 0;

            if(discount.contains(key))
            {
                // with discount
                price = item.getPriceWo() * ( 1 + item.getTax()/100) * ( 1 - discount[key].getDiscount()/100);
            }
            else
            {
                // without discount
                price = item.getPriceWo() * ( 1 + item.getTax());
            }
            bill.insert(key,
                        Bill(item.getName(), item.getTax(), discount[key].getDiscount(),
                             price*order[key].getQuantity(), price, order[key].getQuantity()));
        }
        else
        {
            qDebug() << "There is no product with EAN-13 " << key << " in our shop";
        }
    }
}

bool ReadCommandLineArguments(const int &argc, char ** argv, QStringList & orderList)
{
    QString itemFileName = "items.csv";
    QString orderFileName1 = "order_";
    QString orderFileName2 = ".csv";
    QString discountFileName = "discount.csv";

    int numItemFiles = 0;
    int numOrderFiles = 0;
    int numDiscountFiles = 0;

    if(argc < 4)
    {
        qDebug() << "Some command line arguments are missing!";
        return false;
    }
    else
    {
        for(int i = 1; i < argc; ++i)
        {
            QString fileName = argv[i];
            if(QString::compare(fileName, itemFileName) == 0)
            {
                ++numItemFiles;
            }
            else if(QString::compare(fileName.left(6), orderFileName1) == 0 && QString::compare(fileName.right(4), orderFileName2) == 0 &&
                    fileName.mid(6, 2).toInt() != 0)
            {
                orderList << fileName;
                ++numOrderFiles;
            }
            else if(QString::compare(fileName, discountFileName) == 0)
            {
                ++numDiscountFiles;
            }
        }

        if(numItemFiles != 1)
        {
            qDebug() << "Wrong number of items.csv files";
            return false;
        }
        if(numDiscountFiles != 1)
        {
            qDebug() << "Wrong number of discount.csv files";
            return false;
        }
        if(numOrderFiles == 0)
        {
            qDebug() << "There are no order_xx.csv files";
            return false;
        }
    }
    return true;
}
