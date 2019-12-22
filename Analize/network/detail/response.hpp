//
//  Response.hpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#ifndef response_hpp
#define response_hpp

#include <string>


namespace network
{
  class Responce
  {
  public:
    Responce(std::string url, long code, std::string data);
    std::string getUrl() const;
    long getCode() const;
    std::string getData() const;
    
    void print(std::ostream &output) const;
    
  private:
    std::string url_;
    long code_;
    std::string data_;
  };
}


#endif /* response_hpp */
