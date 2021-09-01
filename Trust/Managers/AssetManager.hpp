//
//  AssetManager.hpp
//  Trust
//
//  Created by Lincoln Scheer on 8/31/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef AssetManager_hpp
#define AssetManager_hpp

#include "Manager.hpp"

class AssetManager: public Manager {
public:
    void startUp() override;
    void shutDown() override;
};

#endif /* AssetManager_hpp */
