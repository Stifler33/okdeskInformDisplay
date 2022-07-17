#ifndef OKDESKAPI_H
#define OKDESKAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <iostream>

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
public:
    explicit OkdeskApi(QObject *parent = nullptr);
    ~OkdeskApi() = default;
    QString getNameAccount();
signals:
void sendingTasks(QJsonDocument *tasks);
void sendResultConnect(QString result);

public slots:
void setAccountSettings(QString name, QString api);
void getResponse(QNetworkReply *replyNetwork);
void getNewTask();
};

#endif // OKDESKAPI_H
