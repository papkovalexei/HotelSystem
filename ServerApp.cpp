#include "ServerApp.h"

int MyServerApp::main(const std::vector<std::string> &args) {
    HTTPServer s(new RequestHandlerFactory, ServerSocket(9090), new HTTPServerParams);

    s.start();
    std::cout << std::endl << "Server started" << std::endl;
    waitForTerminationRequest();
    std::cout << std::endl << "Shutting down..." << std::endl;
    s.stop();

    return Application::EXIT_OK;
}