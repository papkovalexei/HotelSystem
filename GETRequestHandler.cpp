#include "GETRequestHandler.h"

void GETRequestHandler::handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
{
    std::string fileName = req.getURI();
    std::string mediaType = "";
    fileName.erase(fileName.begin());

    if (fileName.find(".js") != std::string::npos) {
        mediaType = "text/javascript";
    } else if (fileName.find(".html") != std::string::npos) {
        mediaType = "text/html";
    } else if (fileName.find(".css") != std::string::npos) {
        mediaType = "text/css";
    } else if (fileName.find(".jpg") != std::string::npos) {
        mediaType = "images/jpg";
    } else if (fileName.find(".png") != std::string::npos) {
        mediaType = "images/png";
    } else if (fileName.find(".ico") != std::string::npos) {
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