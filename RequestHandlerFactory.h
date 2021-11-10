#ifndef H_REQUEST_FACTORY
#define H_REQUEST_FACTORY

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

#include "POSTRequestHandler.h"
#include "GETRequestHandler.h"

using namespace Poco::Net;

class RequestHandlerFactory : public HTTPRequestHandlerFactory {
public:
    virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &req);
};

#endif