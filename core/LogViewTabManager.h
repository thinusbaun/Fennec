#ifndef LOGVIEWTABMANAGER_H
#define LOGVIEWTABMANAGER_H

#include <QObject>

class LogViewTabManager : public QObject
{
    Q_OBJECT
public:
    explicit LogViewTabManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LOGVIEWTABMANAGER_H