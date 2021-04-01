#ifndef HOST_H
#define HOST_H

#include <QWidget>

class QPushButton;

class Host : public QWidget
{
    Q_OBJECT
public:
    explicit Host(QWidget *parent = nullptr);

    QSize sizeHint() const;

protected:
    void adjustPopup();
    void resizeEvent(QResizeEvent *event);
    void moveEvent(QMoveEvent *event);

    QWidget* mPopup;
    QPushButton* mButton;
};

#endif // HOST_H
