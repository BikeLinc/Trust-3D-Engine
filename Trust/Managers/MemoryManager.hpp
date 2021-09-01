//
//  MemoryManager.hpp
//  Trust
//
//  Created by Lincoln Scheer on 8/31/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef MemoryManager_hpp
#define MemoryManager_hpp

#include "Manager.hpp"

class MemoryManager: public Manager {
    public:
    void startUp() override;
    void shutDown() override;
};

#endif /* MemoryManager_hpp */
