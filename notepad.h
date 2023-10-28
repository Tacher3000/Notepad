#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include "notetoolbar.h"
#include "QTextEdit"
#include "QPushButton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad; }
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();

protected:

private slots:
    void syncScrollBars(int value);
    void cancel();
    void repeat();

    void copy();
    void cut();
    void paste();

    void AlignLeft();
    void AlignRight();
    void AlignCenter();
    void AlignJustify();

    void zoomIn();
    void zoomOut();

    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_3_triggered();
    void on_action_5_triggered();


private:
    void changeTextEdit2Line ();
    void colorTextEdit2Line();


    Ui::Notepad *ui;

    NoteToolBar *toolbar;

    QTextEdit *textEdit;
    QTextEdit *textEdit2;

    QString currentFile;

    int lineCount1;
    int lineCount2;
};
#endif // NOTEPAD_H
