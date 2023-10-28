#ifndef NOTETEXTEDIT_H
#define NOTETEXTEDIT_H

#include <QTextEdit>
#include "QString"

class NoteTextEdit : public QTextEdit
{
public:
    NoteTextEdit();
    NoteTextEdit(QWidget *parent = nullptr);
    QString getText1() const;
    QString getText2() const;
    void setText1(const QString &text);
    void setText2(const QString &text);

private:
    QTextEdit *textEdit;
    QTextEdit *textEdit2;
};

#endif // NOTETEXTEDIT_H
