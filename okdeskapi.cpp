#include "okdeskapi.h"

OkdeskApi::OkdeskApi(QObject *parent) : QObject(parent)
{
    connect(&netManager, &QNetworkAccessManager::finished, this, &OkdeskApi::getResponse);
    //getAllTask.setUrl(QUrl(url.arg(accountName).arg(command.getAllTask).arg(accountApi)));
}

void OkdeskApi::setAccountSettings(QString name, QString api)
{
    accountName = name;
    accountApi = api;
    getHelpStatusTask.setUrl(QUrl(url.arg(accountName, command.getHelpStatusesTask, accountApi)));
    netManager.get(getHelpStatusTask);
}

void OkdeskApi::getResponse(QNetworkReply *replyNetwork)
{
    if (replyNetwork->error() == QNetworkReply::NoError){
        jsonDoc = QJsonDocument::fromJson(replyNetwork->readAll());
        emit sendResultConnect("connect completed");
        //QJsonArray arJson = jsonDoc.array();
        emit sendingTasks(&jsonDoc);
    }else{
        emit sendResultConnect(replyNetwork->errorString());
    }
}

void OkdeskApi::getNewTask()
{
    getAllTask.setUrl(QUrl(url.arg(accountName, command.getAllTask, accountApi)));
    netManager.get(getAllTask);
}

QString OkdeskApi::getNameAccount()
{
    return accountName;
}
