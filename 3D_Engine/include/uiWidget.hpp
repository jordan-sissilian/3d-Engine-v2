#ifndef UIWIDGET_HPP
#define UIWIDGET_HPP

#include <QWidget>
#include <QPushButton>
#include <QDebug>

class UIWidget : public QWidget
{

public:
    explicit UIWidget(QWidget *parent = nullptr);

private:
    void handleButtonClick();
};

#endif
