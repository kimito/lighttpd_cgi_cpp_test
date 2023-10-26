#include<iostream>

#include"cgicc/Cgicc.h"
#include<cgicc/HTTPContentHeader.h>

#include"opencv2/opencv.hpp"

void print_api_info(const cgicc::CgiEnvironment &env)
{
    std::cout << cgicc::HTTPContentHeader("text/plain");

    std::cout << "hello api!" << "\r\n";
    std::cout << "path: " << env.getPathInfo() << "\r\n";
    std::cout << "query: " << env.getQueryString() << "\r\n";
}

void print_image()
{
    std::cout << cgicc::HTTPContentHeader("image/jpeg");

    cv::Mat img = cv::imread("./berries.jpg");
    std::vector<uchar>buf;
    cv::imencode(".jpg", img, buf);

    std::cout.write(reinterpret_cast<const char*>(buf.data()), buf.size());
}

int main(int argc, char* argv[])
{
    cgicc::Cgicc cgi;
    auto env = cgi.getEnvironment();

    // print_api_info(env);

    print_image();

    return 0;
}

