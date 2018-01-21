#include <MainWindow.h>
#include <QApplication>
#include <QDir>
#include <QSettings>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow window;
  window.setWindowIcon(QIcon(":/fennec/fennec.svg"));
  window.setBasicWindowName("Fennec");
  window.show();
  window.centerAndResize();
  return a.exec();
}
