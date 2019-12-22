//
//  YApi.cpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#include <iostream>
#include <Exception.hpp>

#include "yAPI.hpp"
#include "HTTPDownloader.hpp"
#include "taxiInfo.hpp"

const std::string clid = "ak1012";
const std::string apikey = "1c92306a5d1d4174a3d57fd69c65282e";
const std::string taxiClassNames = {"econom", "vip"};


std::string yAPI::createRequestURL(const location &locStart, const location &locEnd, taxiClass taxi_Class)
{
  std::stringstream req;
  req <<  "https://taxi-routeinfo.taxi.yandex.net/taxi_info?"
  << "clid=" << clid
  << "&apikey=" << apikey
  << "&rll=" << std::to_string(locStart.lon)
  << "," << std::to_string(locStart.lat)
  << "~" << std::to_string(locEnd.lon)
  << "," << std::to_string(locEnd.lat)
  << "&class=" << taxiClassNames.at(taxi_Class);
  
  return req.str();
}

yAPI::taxiInfo yAPI::checkTaxi(const location &locStart, const location &locEnd)
{
  auto s = network::getRequest(createRequestURL(locStart, locEnd, taxiClass::econom));
  return yAPI::fromJSON(s);
}
