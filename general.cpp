#include "general.h"

General::General()
{
    setWindow = new setParameterAccount;
    okdeskApi = new OkdeskApi;
    okdeskApi->moveToThread(&thOkdeskApi);
    connect(setWindow, &setParameterAccount::callConnect, okdeskApi, &OkdeskApi::setAccountSettings);
    connect(okdeskApi, &OkdeskApi::sendResultConnect, setWindow, &setParameterAccount::showResultConnect);
    connect(okdeskApi, &OkdeskApi::signalSend, okdeskApi, &OkdeskApi::sendRequest);
    thOkdeskApi.start();
    setWindow->show();
}
