//
// Created by igor on 16.11.2021.
//

#pragma once

#include <vector>
#include "Observe_inf.h"
#include "Subscriber_inf.h"
#include "../On_cell_objects/Subscriber.h"

//struct Observe_inf;class Subscriber; class Subscriber_inf;

class Observer {
public:
    void add_observer(Subscriber* new_sub);
    void remove_dead_subs();
    void check_subscribers();
private:
    void set_actual_inf();
    std::vector<std::pair<Subscriber*, Subscriber_inf>> observed_subs;
};



