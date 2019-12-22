//
//  HTTPDownloader.cpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#include "HTTPDownloader.hpp"
#include <curl/curl.h>
#include <curl/easy.h>
#include <sstream>
#include <iostream>

std::string network::getRequest(const std::string& url)
{
  HTTPDownloader downloader;
  std::string content = downloader.download(url);
  return content;
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  std::string data((const char*) ptr, (size_t) size * nmemb);
  *((std::stringstream*) stream) << data << std::endl;
  return size * nmemb;
}

network::HTTPDownloader::HTTPDownloader()
{
  curl = curl_easy_init();
}

network::HTTPDownloader::~HTTPDownloader()
{
  curl_easy_cleanup(curl);
}

std::string network::HTTPDownloader::download(const std::string& url) {
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
  curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
  std::stringstream out;
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK)
  {
    std::fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
  }
  return out.str();
}
