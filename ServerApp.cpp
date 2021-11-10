#include "ServerApp.h"

void GETRequestHandler::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
{
    string fileName = req.getURI();
    string mediaType = "";
    fileName.erase(fileName.begin());

    if (fileName.find(".js") != string::npos) {
        mediaType = "text/javascript";
    } else if (fileName.find(".html") != string::npos) {
        mediaType = "text/html";
    } else if (fileName.find(".css") != string::npos) {
        mediaType = "text/css";
    } else if (fileName.find(".jpg") != string::npos) {
        mediaType = "images/jpg";
    } else if (fileName.find(".png") != string::npos) {
        mediaType = "images/png";
    } else if (fileName.find(".ico") != string::npos) {
        mediaType = "image/ico";
    } else if (req.getURI() == "/"){
        mediaType = "text/html";
        fileName = "index.html";
    } else {
        resp.setStatus(HTTPResponse::HTTP_BAD_REQUEST);
        return;
    }

    resp.sendFile(fileName, mediaType);
    resp.setStatus(HTTPResponse::HTTP_OK);
}

void POSTRequestHandler::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
{
    resp.setStatus(HTTPResponse::HTTP_OK);
}

HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(const HTTPServerRequest &req) {
    cout << req.getMethod() << " URI = " << req.getURI() << endl;
    if (req.getMethod() == "GET") {
        return new GETRequestHandler;
    } else if (req.getMethod() == "POST") {
        return new POSTRequestHandler;
    }
}

int MyServerApp::main(const vector<string> &args) {
    HTTPServer s(new RequestHandlerFactory, ServerSocket(9090), new HTTPServerParams);

    s.start();
    cout << endl << "Server started" << endl;
    waitForTerminationRequest();
    cout << endl << "Shutting down..." << endl;
    s.stop();

    return Application::EXIT_OK;
}