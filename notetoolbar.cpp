#include "notetoolbar.h"
#include "notepad.h"
#include <QToolBar>
#include <QAction>

NoteToolBar::NoteToolBar(QWidget *parent)
    : QToolBar("Tool Bar", parent)
{

    action_1 = new QAction("Сохранить", parent);
    action_1->setIcon(QIcon(":/icons/resurse/image/icons8-save-64.png"));
    addAction(action_1);

    addSeparator();

    action_2 = new QAction("Назад", parent);
    action_2->setIcon(QIcon(":/icons/resurse/image/icons8-cancel-64.png"));
    addAction(action_2);

    action_3 = new QAction("Вперед", parent);
    action_3->setIcon(QIcon(":/icons/resurse/image/icons8-repeat-64.png"));
    addAction(action_3);

    addSeparator();

    action_4 = new QAction("Копировать", parent);
    action_4->setIcon(QIcon(":/icons/resurse/image/icons8-copy-64.png"));
    addAction(action_4);

    action_5 = new QAction("Вырезать", parent);
    action_5->setIcon(QIcon(":/icons/resurse/image/icons8-cut-64.png"));
    addAction(action_5);

    action_6 = new QAction("Вставить", parent);
    action_6->setIcon(QIcon(":/icons/resurse/image/icons8-paste-64.png"));
    addAction(action_6);

    addSeparator();

    action_7 = new QAction("Выравнивание по левому краю", parent);
    action_7->setIcon(QIcon(":/icons/resurse/image/icons8-align-left-64.png"));
    addAction(action_7);

    action_8 = new QAction("Выравнивание по правому краю", parent);
    action_8->setIcon(QIcon(":/icons/resurse/image/icons8-align-right-64.png"));
    addAction(action_8);

    action_9 = new QAction("Выравнивание по центру", parent);
    action_9->setIcon(QIcon(":/icons/resurse/image/icons8-align-center-64.png"));
    addAction(action_9);

    action_10 = new QAction("Выравнивание по ширине", parent);
    action_10->setIcon(QIcon(":/icons/resurse/image/icons8-align-Justify-64.png"));
    addAction(action_10);

    addSeparator();

    action_11 = new QAction("Увеличить", parent);
    action_11->setIcon(QIcon(":/icons/resurse/image/icons8-zoomIn-64.png"));
    addAction(action_11);

    action_12 = new QAction("Уменьшить", parent);
    action_12->setIcon(QIcon(":/icons/resurse/image/icons8-zoomOut-64.png"));
    addAction(action_12);

    setMovable(false);
}
