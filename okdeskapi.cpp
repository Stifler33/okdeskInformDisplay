#include "okdeskapi.h"

OkdeskApi::OkdeskApi(QObject *parent) : QObject(parent)
{
    connect(&netManager, &QNetworkAccessManager::finished, this, &OkdeskApi::getResponse);
    commandApi command;
}

void OkdeskApi::setAccountSettings(QString &name, QString &api)
{
    accountName = name;
    accountApi = api;
    netManager.get(QNetworkRequest(url.arg(accountName).arg(command.getHelpStatusesTask).arg(accountApi)));
}

void OkdeskApi::getResponse(QNetworkReply *replyNetwork)
{
    if (replyNetwork->error() == QNetworkReply::NoError){
        jsonDoc = QJsonDocument::fromJson(replyNetwork->readAll());
    }
}
