#include "searchw.h"
#include <QDesktopWidget>

SearchW::SearchW(QWidget* parent):QWidget (parent)
{
    Qt::WA_DeleteOnClose;
    setFixedSize(900,400);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());
}
