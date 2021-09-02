//
//  EventHandler.hpp
//  Trust
//
//  Created by Lincoln Scheer on 9/1/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef EventHandler_hpp
#define EventHandler_hpp

#include <queue>

#include "Event.h"

class EventHandler {
private:
    std::queue<Event> m_queue;
public:
    EventHandler();
    void addEventToQueue(Event event);
    void addEventToTopOfQueue(Event event);
private:
    void dispatchNextEvent();
    bool isEventCompleted(Event event);
    void clearEventFromQueue();
};

#endif /* EventHandler_hpp */

// ALL_MANAGERS, MEMORY_MANAGER, ASSET_MANAGER, GUI_MANAGER, RENDERER_MANAGER, DISPLAY_MANAGER
