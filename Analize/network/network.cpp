//
//  network.cpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#include <cURLpp.hpp>

#include "network.hpp"
#include <iostream>

#include "HTTPDownloader.hpp"

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
  data->append((char*) ptr, size * nmemb);
  std::cout << 1;
  return size * nmemb;
}

network::Responce network::getRequest(const std::string &url)
{
  HTTPDownloader downloader;
  std::string content = downloader.download(url);
  std::cout << content << std::endl;
  
  return network::Responce(url, 0, content);
  
  auto curl = curl_easy_init();
  if (curl)
  {
    char cstr[url.size() + 1];
    strcpy(cstr, url.c_str());
    
    curl_easy_setopt(curl, CURLOPT_URL, cstr);
    
    std::string response_string;
    std::string header_string;
    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

    long response_code;
  
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    curl_easy_cleanup(curl);
    curl = NULL;
    return network::Responce(url, response_code, response_string);
  }
  return network::Responce(url, network::curlInitErrorCode, "curl init error");
}
