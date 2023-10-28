#include "notepad.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    загрузка стилей
    QFile styleFile(":/style/resurse/style/Aqua.qss");
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = styleFile.readAll();

        a.setStyleSheet(styleSheet);

        styleFile.close();
    } else {
        qWarning() << "Не удалось открыть файл стилей.";
    }



    Notepad w;

    w.showMaximized();

    w.show();
    return a.exec();
}
