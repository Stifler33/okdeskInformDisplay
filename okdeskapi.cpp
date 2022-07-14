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
    getHelpStatusTask.setUrl(QUrl(url.arg(accountName).arg(command.getHelpStatusesTask).arg(accountApi)));
    netManager.get(getHelpStatusTask);
}

void OkdeskApi::getResponse(QNetworkReply *replyNetwork)
{
    if (replyNetwork->error() == QNetworkReply::NoError){
        jsonDoc = QJsonDocument::fromJson(replyNetwork->readAll());
        printJson();
        emit sendResultConnect("connect completed");
    }else{
        emit sendResultConnect(replyNetwork->errorString());
    }
}

void OkdeskApi::printJson()
{
    if (jsonDoc.isArray())
    {
        printf("json array\n");
    }
    if (jsonDoc.isObject())
    {
        printf("json obeject\n");
    }
    QJsonArray jsonArray = jsonDoc.array();
    QTextStream textStream;
    textStream << jsonArray.size();

    printf(QString(jsonArray.size()).toUtf8());
}
