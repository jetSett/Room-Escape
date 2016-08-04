#include "widget.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget wid;
    wid.show();

    return a.exec();
}
