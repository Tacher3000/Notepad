#ifndef NOTETOOLBAR_H
#define NOTETOOLBAR_H

#include <QToolBar>


class NoteToolBar : public QToolBar
{
public:
    NoteToolBar(QWidget *parent = nullptr);

//private:
    QAction *action_1;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QAction *action_11;
    QAction *action_12;
};

#endif // NOTETOOLBAR_H
