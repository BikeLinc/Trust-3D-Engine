//
//  GUIManager.hpp
//  Trust
//
//  Created by Lincoln Scheer on 8/31/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef GUIManager_hpp
#define GUIManager_hpp

#include "Manager.hpp"

class GUIManager: public Manager {
   public:
    void startUp() override;
    void shutDown() override;
};

#endif /* GUIManager_hpp */
