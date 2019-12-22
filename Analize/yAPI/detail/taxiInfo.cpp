//
//  taxiInfo.cpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "json.hpp"

#include "taxiInfo.hpp"

#include <chrono>
#include <thread>


yAPI::taxiInfo::taxiInfo(int price, double waitingTime, double time, double distance, taxiClass taxi_class):
  snapTime_(std::time(nullptr)),
  price_(price),
  waitingTime_(waitingTime),
  time_(time),
  distance_(distance),
  class_(taxi_class)
{ }

yAPI::taxiInfo::taxiInfo(std::time_t snapTime, int price, double waitingTime, double time, double distance, taxiClass taxi_class):
snapTime_(snapTime),
price_(price),
waitingTime_(waitingTime),
time_(time),
distance_(distance),
class_(taxi_class)
{ }

void yAPI::taxiInfo::print(std::ostream &output) const
{
  output << std::asctime(std::localtime(&snapTime_)) <<
            "price: " << price_ << "\n" <<
            "waitingTime: " << waitingTime_ << "\n" <<
            "time: " << time_ << "\n" <<
            "distance: " << distance_ << "\n" <<
            "class: " << class_ << "\n";
}


void yAPI::taxiInfo::save(std::string path)
{
  std::ofstream input(path);
  if(input)
  {
    input << snapTime_ << " " << price_ << " " << waitingTime_ << " " << time_ << " " << distance_ << " " << class_;
  }else
  {
    std::cout << "error Open\n";
  }
  
  input.close();
  std::cout << "save correct to " << path << "\n";
  
}

yAPI::taxiInfo yAPI::taxiInfo::load(std::string path)
{
  std::time_t snapTime = 0;
  int cl;
  double dist = 0;
  double price = 0;
  double waiting_time = 0;
  double time = 0;
  
  std::ifstream input(path);
  if(input)
  {
    input >> snapTime >> price >> waiting_time >> time >> dist >> cl;
  }else
  {
    std::cout << "error Open\n";
  }
  
  input.close();
  return yAPI::taxiInfo(snapTime, price, waiting_time, time, dist, static_cast<taxiClass>(cl));
}



yAPI::taxiInfo yAPI::fromJSON(std::string JSON)
{
  //std::cout << JSON << "\n\n";
  
  //JSON = "{\"currency\":\"RUB\",\"distance\":8336.6227774620056,\"options\":[{\"class_level\":50,\"class_name\":\"econom\",\"class_text\":\"Эконом\",\"min_price\":79.0,\"price\":203.0,\"price_text\":\"~203 руб.\",\"waiting_time\":129.69039511680603}],\"time\":869.61515406821468,\"time_text\":\"15 мин\"}";
  
  auto jsonParse = nlohmann::json::parse(JSON);
  double dist = 0;
  double price = 0;
  double waiting_time = 0;
  double time = 0;
  jsonParse.at("distance").get_to(dist);
  jsonParse.at("options").at(0).at("price").get_to(price);
  jsonParse.at("options").at(0).at("waiting_time").get_to(waiting_time);
  jsonParse.at("time").get_to(time);
  
  //std::cout << std::endl << dist << std::endl << price << std::endl << waiting_time << std::endl << time << std::endl  << std::endl;
  return yAPI::taxiInfo(price, waiting_time, time, dist, taxiClass::econom);
}

