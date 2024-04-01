#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <QWidget>
#include <QDockWidget>
#include <QPlainTextEdit>


class TextBox : public QDockWidget {
    Q_OBJECT

private:
    QPlainTextEdit textBox;

public:
    TextBox();
};

#endif
