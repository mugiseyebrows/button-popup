#include "host.h"

#include <QPushButton>
#include <QVBoxLayout>

Host::Host(QWidget *parent) : QWidget(parent)
{
    mButton = new QPushButton("show popup");
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(mButton);
    layout->addStretch(1);
    setLayout(layout);

    mPopup = new QWidget(this);
    mPopup->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // blue color for demonstration
    QPalette palette = mPopup->palette();
    palette.setColor(QPalette::Window, Qt::blue);
    mPopup->setPalette(palette);

    connect(mButton,&QPushButton::clicked,[=](){
        mPopup->setVisible(!mPopup->isVisible());
        adjustPopup();
    });
}

void Host::adjustPopup() {
    if (!mPopup->isVisible()) {
        return;
    }
    QRect rect = mButton->geometry();
    QPoint bottomLeft = this->mapToGlobal(rect.bottomLeft());
    mPopup->setGeometry(QRect(bottomLeft, QSize(rect.width(),200)));
}

void Host::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    adjustPopup();
}

void Host::moveEvent(QMoveEvent *event)
{
    QWidget::moveEvent(event);
    adjustPopup();
}

QSize Host::sizeHint() const
{
    return QSize(200,100);
}
