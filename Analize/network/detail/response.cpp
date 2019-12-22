//
//  Response.cpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#include <ostream>

#include "response.hpp"



network::Responce::Responce(std::string url, long code, std::string data) :
  url_(url),
  code_(code),
  data_(data)
{ }

std::string network::Responce::getUrl() const
{
  return url_;
}

long network::Responce::getCode() const
{
  return code_;
}

std::string network::Responce::getData() const
{
  return data_;
}

void network::Responce::print(std::ostream &output) const
{
  output << "url: " << url_ << "\n"<<
   "code: " << code_ << "\n" <<
    "data: " << data_ << "\n";
}
