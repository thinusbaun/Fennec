#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  MainWindow window;
  window.show();
  window.centerAndResize();
  return a.exec();
}
