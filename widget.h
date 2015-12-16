#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tablemodel.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
	void on_pushButton_folderPath_clicked();
	void on_pushButton_doIt_clicked();
	void on_pushButton_copy_clicked();

private:
    Ui::Widget *ui;
	TableModel *m_model;
};

#endif // WIDGET_H
