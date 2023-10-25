#include<iostream>

#include "cgicc/Cgicc.h"
#include <cgicc/HTTPContentHeader.h>

void print_api_info()
{
    std::cout << cgicc::HTTPContentHeader("text/plain");

    std::cout << "hello api!" << "\r\n";
    std::cout << "path: " << env.getPathInfo() << "\r\n";
    std::cout << "query: " << env.getQueryString() << "\r\n";
}

int main(int argc, char* argv[])
{
    cgicc::Cgicc cgi;
    auto env = cgi.getEnvironment();

    print_api_info();   

    return 0;
}

