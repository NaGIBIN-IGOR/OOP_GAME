//
// Created by igor on 16.11.2021.
//

#ifndef OOP_GAME_OBSERVER_H
#define OOP_GAME_OBSERVER_H

#include <vector>

struct Observe_inf;class Subscriber; class Subscriber_inf;

class Observer {
public:
    void add_observer(Subscriber* new_sub);
    std::vector<std::pair<Subscriber*, Observe_inf>>& check_subscribers();
private:
    std::vector<std::pair<Subscriber*, Subscriber_inf>> observed_subs;
};



#endif //OOP_GAME_OBSERVER_H
