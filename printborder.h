#ifndef PRINTBORDER_H
#define PRINTBORDER_H
#include "tableprinter.h"
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>

class PrintBorder : public PagePrepare
{
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

#endif // PRINTBORDER_H
