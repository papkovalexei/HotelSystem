#include "RequestHandlerFactory.h"

HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(const HTTPServerRequest &req) {
    std::cout << req.getMethod() << " URI = " << req.getURI() << std::endl;
    if (req.getMethod() == "GET") {
        return new GETRequestHandler;
    } else if (req.getMethod() == "POST") {
        return new POSTRequestHandler;
    }
}