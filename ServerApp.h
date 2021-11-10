#ifndef H_SERVER_APP
#define H_SERVER_APP

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/Util/ServerApplication.h>
#include <iostream>
#include <string>
#include <vector>

using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;

class GETRequestHandler : public HTTPRequestHandler {
public:
    virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp);
};

class POSTRequestHandler : public HTTPRequestHandler {
public:
    virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp);
};

class RequestHandlerFactory : public HTTPRequestHandlerFactory {
public:
    virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &req);
};

class MyServerApp : public ServerApplication {
protected:
    int main(const vector<string> &args);
};

#endif