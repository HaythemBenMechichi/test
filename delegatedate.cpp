#include "delegatedate.h"
delegatedate::delegatedate(QObject *parent):QItemDelegate(parent)
{

}

QWidget * delegatedate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
QDateEdit *n=new QDateEdit(parent);

    return n;
}
void delegatedate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QVariant value=index.model()->data(index,Qt::EditRole);

    QDateEdit* spinbox=static_cast<QDateEdit*>(editor);
    spinbox->setDate(value.toDate());

}
void delegatedate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {

 QDateEdit* spinbox=static_cast<QDateEdit*>(editor);;
 //spinbox->interpretText();
 QDate value=spinbox->date();
 model->setData(index,value,Qt::EditRole);
}
QWidget* delegatedate::createdate(QWidget *parent){
    QDateEdit *n=new QDateEdit(parent);

        return n;

}
void delegatedate::setdate(QWidget *editor, const QModelIndex &index){
    QVariant value=index.model()->data(index,Qt::EditRole);

    QDateEdit* spinbox=static_cast<QDateEdit*>(editor);
    spinbox->setDate(value.toDate());

}
QDate delegatedate::setmodeldate(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index){
   QVariant value=index.model()->data(index,Qt::EditRole);

   QDateEdit* spinbox=static_cast<QDateEdit*>(editor);
   spinbox->setDate(value.toDate());
 return value.toDate();
}

