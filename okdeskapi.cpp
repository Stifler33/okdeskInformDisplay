#include "okdeskapi.h"

OkdeskApi::OkdeskApi()
{
    connect(&netManager, &QNetworkAccessManager::finished, this, &OkdeskApi::getResponse);
    //getAllTask.setUrl(QUrl(url.arg(accountName).arg(command.getAllTask).arg(accountApi)));
}

void OkdeskApi::setAccountSettings(QString name, QString api)
{
    accountName = name;
    accountApi = api;
    getHelpStatusTask.setUrl(QUrl(url.arg(accountName).arg(command.getHelpStatusesTask).arg(accountApi)));
    netManager.get(getHelpStatusTask);
}

void OkdeskApi::getResponse(QNetworkReply *replyNetwork)
{
    if (replyNetwork->error() == QNetworkReply::NoError){
        jsonDoc = QJsonDocument::fromJson(replyNetwork->readAll());
        emit sendResultConnect("connect completed");
    }else{
        emit sendResultConnect(replyNetwork->errorString());

    }
}
