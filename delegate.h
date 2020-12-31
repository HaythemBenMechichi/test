#ifndef DELEGATE_H
#define DELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QWidget>
#include <QModelIndex>
#include <QSize>
#include <QString>
#include <QtGui>
#include <QSpinBox>
#include <QLineEdit>
class Delegate : public QItemDelegate
{
    Q_OBJECT
    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
   void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

public:
    explicit Delegate(QObject* parent=0);
    QWidget* create(QWidget *parent);
    void set(QWidget *editor, const QModelIndex &index);
    QString setmodel(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index);



};

#endif // DELEGATE_H
