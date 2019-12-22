//
//  network.hpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#ifndef Network_hpp
#define Network_hpp

#include <string>
#include <ostream>

#include "Response.hpp"

namespace network {
  
  const long curlInitErrorCode = -1;


  Responce getRequest(const std::string &url);
}

#endif /* Network_hpp */
