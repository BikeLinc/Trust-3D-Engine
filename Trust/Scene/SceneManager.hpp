//
//  SceneManager.hpp
//  Trust
//
//  Created by Lincoln Scheer on 9/1/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include "Manager.hpp"

class SceneManager: public Manager {
    void startUp() override;
    void shutDown() override;
    
};

#endif /* SceneManager_hpp */
