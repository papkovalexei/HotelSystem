#include "POSTRequestHandler.h"

void POSTRequestHandler::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
{
    resp.setStatus(HTTPResponse::HTTP_OK);
}