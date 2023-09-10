#include "./include/window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Créez une instance de la classe Window (votre fenêtre principale)
    Window mainWindow;

    // Affichez la fenêtre principale
    mainWindow.show();

    return (app.exec()); // Exécution de l'application Qt
}