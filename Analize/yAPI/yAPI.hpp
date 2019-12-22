//
//  YApi.hpp
//  Yandex2
//
//  Created by Andrei Soprachev on 22.11.2019.
//  Copyright © 2019 Andrei Soprachev. All rights reserved.
//

#ifndef YApi_hpp
#define YApi_hpp

#include <string>
#include "location.h"
#include "HTTPDownloader.hpp"
#include "taxiInfo.hpp"

namespace yAPI {
  
  std::string createRequestURL(const location &locStart, const location &locEnd, taxiClass taxi_class);
  
  yAPI::taxiInfo checkTaxi(const location &locStart, const location &locEnd);
  
}


#endif /* yApi_hpp */
