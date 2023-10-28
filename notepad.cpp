#include "notepad.h"
#include "./ui_notepad.h"
#include "QFile"
#include "QFileDialog"
#include "QMessageBox"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QPushButton"
#include "QKeyEvent"
#include <QTextEdit>
#include <QMenuBar>
#include <QDebug>
#include <QScrollBar>
#include <QTextCursor>
#include <QTextBlock>
#include <QTextCursor>
#include "notetoolbar.h"



Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    // Инициализация пользовательского интерфейса
    ui->setupUi(this);

//    тул бар
    toolbar = new NoteToolBar(this);
    // Конект кнопок к их методам
    connect(toolbar->action_1, &QAction::triggered, this, &Notepad::on_action_3_triggered);
    connect(toolbar->action_2, &QAction::triggered, this, &Notepad::cancel);
    connect(toolbar->action_3, &QAction::triggered, this, &Notepad::repeat);
    connect(toolbar->action_4, &QAction::triggered, this, &Notepad::copy);
    connect(toolbar->action_5, &QAction::triggered, this, &Notepad::cut);
    connect(toolbar->action_6, &QAction::triggered, this, &Notepad::paste);
    connect(toolbar->action_7, &QAction::triggered, this, &Notepad::AlignLeft);
    connect(toolbar->action_8, &QAction::triggered, this, &Notepad::AlignRight);
    connect(toolbar->action_9, &QAction::triggered, this, &Notepad::AlignCenter);
    connect(toolbar->action_10, &QAction::triggered, this, &Notepad::AlignJustify);
    connect(toolbar->action_11, &QAction::triggered, this, &Notepad::zoomIn);
    connect(toolbar->action_12, &QAction::triggered, this, &Notepad::zoomOut);


//    основное текстовое окно
    textEdit = new QTextEdit();
    textEdit->document()->setMaximumBlockCount(999);

    connect(textEdit, &QTextEdit::textChanged, this, &Notepad::changeTextEdit2Line);
    connect(textEdit, &QTextEdit::textChanged, this, &Notepad::colorTextEdit2Line);

    connect(textEdit->verticalScrollBar(), &QScrollBar::valueChanged, this, &Notepad::syncScrollBars);


//    счетчик сторк справа от текстового окна
    textEdit2 = new QTextEdit();

    textEdit2->append(QString::number(1));
    textEdit2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit2->setAlignment(Qt::AlignRight);

    textEdit2->setMaximumWidth(28);
    textEdit2->setEnabled(false);

//    расстановка виджетов
    QHBoxLayout *HLayot = new QHBoxLayout;
    HLayot->setSpacing(0);
    HLayot->addWidget(textEdit2);
    HLayot->addWidget(textEdit);

    QVBoxLayout *VBoxlayout = new QVBoxLayout;

    VBoxlayout->addWidget(toolbar);
    VBoxlayout->addLayout(HLayot);

    // Установка компоновки в основное окно
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(VBoxlayout);
    setCentralWidget(centralWidget);
}

//соединение прокрутки основного текстового редактора с прокруткой колличество строк
void Notepad::syncScrollBars(int value) {

    textEdit2->verticalScrollBar()->setValue(value);
}

//логика добавления и удаления строк в счетчик строк
void Notepad::changeTextEdit2Line()
{
    QString text1 = textEdit->toPlainText();
    QStringList lines1 = text1.split("\n");
    lineCount1 = lines1.size();

    QString text2 = textEdit2->toPlainText();
    QStringList lines2 = text2.split("\n");
    lineCount2 = lines2.size();

    if (lineCount1 - lineCount2 == 1){
        textEdit2->append(QString::number(lineCount1));
        textEdit2->setAlignment(Qt::AlignRight);
    }else if(lineCount1 == lineCount2){
        return;
    }else if(lineCount1 - lineCount2 == -1){
        QTextCursor cursor2 = textEdit2->textCursor();
        cursor2.movePosition(QTextCursor::End);
        cursor2.select(QTextCursor::BlockUnderCursor);
        cursor2.removeSelectedText();
    }else {
        textEdit2->clear();
        for (int i = 1; i <= lineCount1; ++i) {
            textEdit2->append(QString::number(i));
            textEdit2->setAlignment(Qt::AlignRight);
        }
    }
}

//подсвечивание номеров активных строк
void Notepad::colorTextEdit2Line()
{
    // Создаем QTextCursor, чтобы работать с текстом
    QTextCursor cursor = textEdit2->textCursor();

    // Перемещаем курсор к началу строки, которую вы хотите отформатировать (например, строка 2)
    cursor.movePosition(QTextCursor::Start);
    cursor.movePosition(QTextCursor::NextBlock, QTextCursor::MoveAnchor, 1); // Перемещаем курсор к строке 2

    // Создаем объект QTextCharFormat для установки форматирования
    QTextCharFormat format;
    format.setForeground(QColor(Qt::red)); // Устанавливаем цвет текста (красный)

    // Устанавливаем форматирование для текущей позиции курсора
    cursor.setCharFormat(format);

    // Устанавливаем курсор обратно в QTextEdit
    textEdit2->setTextCursor(cursor);
}


//взаимодействие тул бара с текстовым редактором

void Notepad::cancel()
{
    textEdit->undo();
}

void Notepad::repeat()
{
    textEdit->redo();
}

void Notepad::copy()
{
    textEdit->copy();
}

void Notepad::cut()
{
    textEdit->cut();
}

void Notepad::paste()
{
    textEdit->paste();
}

void Notepad::AlignLeft()
{
    textEdit->setAlignment(Qt::AlignLeft);
}

void Notepad::AlignRight()
{
    textEdit->setAlignment(Qt::AlignRight);
}

void Notepad::AlignCenter()
{
    textEdit->setAlignment(Qt::AlignCenter);
}

void Notepad::AlignJustify()
{
    textEdit->setAlignment(Qt::AlignJustify);
}

void Notepad::zoomIn()
{

    textEdit->zoomIn(2);
}

void Notepad::zoomOut()
{
    textEdit->zoomOut(2);
}

Notepad::~Notepad()
{
    delete ui;
}

// Создать файл (очищает существующее поле)
void Notepad::on_action_triggered()
{
    currentFile.clear();
    textEdit->setText(QString());
}

// Открыть существующий txt file
void Notepad::on_action_2_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выбрать файл", "C:/",
                                                    "all file (*.txt *.doc);; Txt file (*.txt) ;; doc file (*.doc)");
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    textEdit->setText(text);
    file.close();
}

// Сохранить txt file
void Notepad::on_action_3_triggered()
{
    QString fileName;
    // If we don't have a filename from before, get one.
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        if (fileName.isEmpty())
            return;
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = textEdit->toPlainText();
    out << text;
    file.close();
}

// Сохранить как
void Notepad::on_action_5_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    if (fileName.isEmpty())
        return;
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = textEdit->toPlainText();
    out << text;
    file.close();
}

