#ifndef DELEGATEDATE_H
#define DELEGATEDATE_H
#include <QItemDelegate>

#include <QObject>
#include <QItemDelegate>
#include <QWidget>
#include <QModelIndex>
#include <QSize>
#include <QString>
#include <QtGui>
#include <QSpinBox>
#include <QLineEdit>
#include <QDateEdit>

class delegatedate : public QItemDelegate
{

    Q_OBJECT
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
   void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
   // void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
public:
    explicit delegatedate(QObject* parent=0);
    QWidget* createdate(QWidget *parent);
    void setdate(QWidget *editor, const QModelIndex &index);
     QDate setmodeldate(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index);


};

#endif // DELEGATEDATE_H
