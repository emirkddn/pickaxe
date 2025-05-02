#include <iostream>
#include <string>
#include <curl/curl.h>
#include "robotstxt.cpp"

using namespace std;

int main() {

    char* link = "https://httpbin.org";
    
    callRobotstxt(link);
    callHtml(link);
    
    return 0;

}
