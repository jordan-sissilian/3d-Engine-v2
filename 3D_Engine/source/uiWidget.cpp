#include "../include/uiWidget.hpp"

UIWidget::UIWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(200, 500);
    setStyleSheet("background-color: white;");

    // Créez et configurez les widgets UI à l'intérieur de UIWidget
    QPushButton *button = new QPushButton("Cliquez moi", this);
    button->setGeometry(50, 50, 100, 30);

    // Connectez un slot (fonction) au signal "clicked" du bouton
    connect(button, &QPushButton::clicked, this, &UIWidget::handleButtonClick);
}

void UIWidget::handleButtonClick()
{
    qDebug() << "Bouton cliqué!";
}