#include<iostream>

#include"cgicc/Cgicc.h"
#include<cgicc/HTTPContentHeader.h>

#include"opencv2/opencv.hpp"

#include"query_string_parser.h"

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
    cv::Mat out;
    cv::Sobel(img, out, CV_32F, 0, 1);
    std::vector<uchar>buf;
    cv::imencode(".jpg", out, buf);

    std::cout.write(reinterpret_cast<const char*>(buf.data()), buf.size());
}

int main(int argc, char* argv[])
{
    cgicc::Cgicc cgi;
    auto env = cgi.getEnvironment();
    QueryStringParser query(env.getQueryString());

    std::cerr << "query k1:" << query.getAttribute("k1") << std::endl;
    std::cerr << "query k2:" << query.getAttribute("k2") << std::endl;

    // print_api_info(env);

    print_image();

    return 0;
}

