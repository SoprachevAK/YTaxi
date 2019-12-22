//
//  HTTPDownloader.hpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#ifndef HTTPDOWNLOADER_HPP
#define HTTPDOWNLOADER_HPP
#include <string>

namespace network {
  
  std::string getRequest(const std::string& url);
  
  class HTTPDownloader
  {
  public:
    HTTPDownloader();
    ~HTTPDownloader();
    std::string download(const std::string& url);
  private:
    void* curl;
  };
}

#endif  /* HTTPDOWNLOADER_HPP */
