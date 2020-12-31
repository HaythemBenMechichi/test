#include "printborder.h"

int PrintBorder::pageNumber = 0;

/*void PrintBorder::preparePage(QPainter *painter)
{ // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}/*/
