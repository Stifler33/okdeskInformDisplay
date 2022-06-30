#include "okdeskapi.h"

OkdeskApi::OkdeskApi(QObject *parent) : QObject(parent)
{
    connect(&netManager, &QNetworkAccessManager::finished, this, &OkdeskApi::getResponse);
    getHelpStatusTask.setUrl(QUrl(url.arg(accountName).arg(command.getHelpStatusesTask).arg(accountApi)));
    //getAllTask.setUrl(QUrl(url.arg(accountName).arg(command.getAllTask).arg(accountApi)));
}

void OkdeskApi::setAccountSettings(QString &name, QString &api)
{
    accountName = name;
    accountApi = api;
    netManager.get(getHelpStatusTask);
}

void OkdeskApi::getResponse(QNetworkReply *replyNetwork)
{
    if (replyNetwork->error() == QNetworkReply::NoError){
        jsonDoc = QJsonDocument::fromJson(replyNetwork->readAll());
        emit sendResultConnect("connect completed");
    }else{
        emit sendResultConnect("connect ERROR");
    }
}
