#include "okdeskapi.h"

OkdeskApi::OkdeskApi(QObject *parent) : QObject(parent)
{
    connect(&netManager, &QNetworkAccessManager::finished, this, &OkdeskApi::getResponse);
}

void OkdeskApi::setAccountSettings(QString &nameAccount, QString &apiAccount)
{

}

void OkdeskApi::getResponse(QNetworkReply *replyNetwork)
{
    if (replyNetwork->error() == QNetworkReply::NoError){
        jsonDoc = QJsonDocument::fromJson(replyNetwork->readAll());
    }
}

void OkdeskApi::setParameter(QString &accauntName, QString &accountApi)
{

}
