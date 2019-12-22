//
//  taxiInfo.hpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#ifndef taxiInfo_hpp
#define taxiInfo_hpp

#include <string>

namespace yAPI
{
  
  enum taxiClass
  {
    econom,
    vip
  };

  class taxiInfo
  {
  public:
    taxiInfo(int price, double waitingTime, double time, double distance, taxiClass taxi_class);
    taxiInfo(std::time_t snapTime, int price, double waitingTime, double time, double distance, taxiClass taxi_class);
    
    void print(std::ostream &output) const;
    
    void save(std::string path);
    static taxiInfo load(std::string path);
    
    
    std::time_t snapTime_;
    int price_;
    double waitingTime_;
    double time_;
    double distance_;
    taxiClass class_;
  };
  
  taxiInfo fromJSON(std::string JSON);
}



#endif /* taxiInfo_hpp */
