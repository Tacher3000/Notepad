#include "notetextedit.h"
#include "QVBoxLayout"
#include "QString"

NoteTextEdit::NoteTextEdit()
{
    int a;
}

NoteTextEdit::NoteTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    textEdit = new QTextEdit(this);
    textEdit2 = new QTextEdit(this);
    textEdit2->setMaximumWidth(20);
    QVBoxLayout *VLayot = new QVBoxLayout;
    VLayot->addWidget(textEdit2);
    VLayot->addWidget(textEdit);

}

// Методы доступа к содержимому редакторов
QString NoteTextEdit::getText1() const {
    return textEdit->toPlainText();
}

QString NoteTextEdit::getText2() const {
    return textEdit2->toPlainText();
}

void NoteTextEdit::setText1(const QString &text) {
    textEdit->setPlainText(text);
}

void NoteTextEdit::setText2(const QString &text) {
    textEdit2->setPlainText(text);
}
