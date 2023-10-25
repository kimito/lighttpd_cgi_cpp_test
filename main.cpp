#include<iostream>

#include "cgicc/Cgicc.h"

int main(int argc, char* argv[])
{
    cgicc::Cgicc cgi;
    auto env = cgi.getEnvironment();

    std::cout << "Content-type: text/plain" << "\r\n";
    std::cout << "\r\n";
    std::cout << "hello api!" << "\r\n";
    std::cout << "path: " << env.getPathInfo() << "\r\n";
    std::cout << "query: " << env.getQueryString() << "\r\n";

    return 0;
}