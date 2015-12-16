#include "widget.h"
#include <QApplication>
#include "hasheval.h"

int main(int argc, char *argv[])
{
	init();
	//uint32_t q = hash(QByteArray("12345678"));
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
