//
//  infoCollecter.cpp
//  Yandex2
//
//  Created by Andrei Soprachev on 25.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#include <stdio.h>
#include <sstream>
#include <string>
#include <iostream>
#include <filesystem>

#include "location.h"
#include <thread>

#include "yAPI.hpp"

const location homePoint{30.245756, 60.002271};
const location polyPoint{30.370144, 60.007077};

std::string getCurrentInfo(int i, std::string path, location startPoint, location endPoint)
{
  try
  {
    auto c = yAPI::checkTaxi(startPoint, endPoint);
    std::string dateTime = std::asctime(std::localtime(&c.snapTime_));
    dateTime.pop_back();
    std::string p = path + "/t" + std::to_string(c.snapTime_) + "&" + dateTime + ".txt";
    c.save(p);
    
  } catch (const std::exception &e)
  {
    std::cout << "error" << e.what() <<"\n";
  }
  return "";
}

void collectInfo(std::string path, location startPoint, location endPoint)
{
  path += "/snapShot";
  std::__fs::filesystem::create_directory(path);
  int i = 0;
  while (true)
  {
    getCurrentInfo(i, path, startPoint, endPoint);
    std::this_thread::sleep_for(std::chrono::seconds(60));
    std::cout << "take snapshot " << i << "\n";
    i++;
  }
}

void collectInfo()
{
  collectInfo(std::__fs::filesystem::current_path(), homePoint, polyPoint);
}
