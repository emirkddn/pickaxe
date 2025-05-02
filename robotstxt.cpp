#include <curl/curl.h>
#include <iostream>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void callRobotstxt(char* link){

    CURL* curl = curl_easy_init();
    if(curl){
        std::string response;

        char* rob = "/robots.txt";

        char* update_link = (char*)malloc(strlen(link) + strlen(rob) + 1);
        strcpy(update_link, link);
        strcat(update_link, rob);

        curl_easy_setopt(curl, CURLOPT_CAINFO, "C:\\Users\\ertugrul\\Desktop\\cacert.pem");
        curl_easy_setopt(curl, CURLOPT_URL, update_link);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            std::cout << "Sunucudan gelen ROBOTS.TXT cevap:\n" << response << std::endl;
        } else {
            std::cerr << "Hata: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);

    }

}

void callHtml(char* link){
    CURL* curl = curl_easy_init();
    if(curl){
        
        std::string response;

        curl_easy_setopt(curl, CURLOPT_CAINFO, "C:\\Users\\ertugrul\\Desktop\\cacert.pem");
        curl_easy_setopt(curl, CURLOPT_URL, link);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            std::cout << "Sunucudan gelen HTML cevap:\n" << response << std::endl;
        } else {
            std::cerr << "Hata: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);

    }

}