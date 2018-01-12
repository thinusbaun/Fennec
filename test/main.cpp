#include "LogEntryTest.h"
#include "LogModelTest.h"
#include <QTest>

int main(int argc, char *argv[]) {
  int status = 0;

  {
    LogEntryTest ta;
    status |= QTest::qExec(&ta, argc, argv);
  }

  {
    LogModelTest ta;
    status |= QTest::qExec(&ta, argc, argv);
  }

  return status;
}
