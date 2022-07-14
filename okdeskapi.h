#ifndef OKDESKAPI_H
#define OKDESKAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class OkdeskApi : public QObject
{
    Q_OBJECT
QString accountApi;
QString accountName;
QString url = "https://%1.okdesk.ru/api/v1/%2/?api_token=%3";
QNetworkAccessManager netManager;
QNetworkRequest getHelpStatusTask;
QNetworkRequest getAllTask;
QJsonDocument jsonDoc;
struct commandApi{
    QString getAllTask = "issues/list";
    QString getHelpStatusesTask = "issues/statuses";
};
commandApi command;
void printJson();
public:
    explicit OkdeskApi(QObject *parent = nullptr);

signals:
void newTaskArrived(const QJsonObject &task);
void listAllTask(const QJsonArray &arrayTask);
void sendResultConnect(QString result);

public slots:
void setAccountSettings(QString name, QString api);
void getResponse(QNetworkReply *replyNetwork);
};

#endif // OKDESKAPI_H
