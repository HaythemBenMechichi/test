#include "delegate.h"

Delegate::Delegate(QObject *parent):QItemDelegate(parent)
{

}

QWidget * Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
QLineEdit *n=new QLineEdit(parent);
    QSpinBox *editor=new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(20);
    return n;
}
void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QVariant value=index.model()->data(index,Qt::EditRole);

    QLineEdit* spinbox=static_cast<QLineEdit*>(editor);
    spinbox->setText(value.toString());

}
void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {

 QLineEdit* spinbox=static_cast<QLineEdit*>(editor);;
 //spinbox->interpretText();
 QString value=spinbox->text();
 model->setData(index,value,Qt::EditRole);
}
void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {

}
QWidget* Delegate::create(QWidget *parent){
    QLineEdit *n=new QLineEdit(parent);

        return n;

}
void Delegate::set(QWidget *editor, const QModelIndex &index){
    QVariant value=index.model()->data(index,Qt::EditRole);

    QLineEdit* spinbox=static_cast<QLineEdit*>(editor);
    spinbox->setText(value.toString());

}
 QString Delegate::setmodel(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index){
    QVariant value=index.model()->data(index,Qt::EditRole);

    QLineEdit* spinbox=static_cast<QLineEdit*>(editor);
    spinbox->setText(value.toString());
  return value.toString();
}

