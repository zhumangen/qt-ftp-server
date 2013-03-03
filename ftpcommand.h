#ifndef FTPCOMMAND_H
#define FTPCOMMAND_H

#include <QObject>

class QTcpSocket;

// The base class for all FTP commands that need a data connection.

class FtpCommand : public QObject
{
    Q_OBJECT
public:
    explicit FtpCommand(QObject *parent = 0);

signals:
    void reply(int code, const QString &details = QString());

public:
    void start(QTcpSocket *socket);

protected:
    virtual void startImplementation() = 0;
    QTcpSocket* socket;
};

#endif // FTPCOMMAND_H
