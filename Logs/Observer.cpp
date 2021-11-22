//
// Created by igor on 17.11.2021.
//

#include "Observer.h"
#include "Observe_inf.h"
#include "Subscriber_inf.h"
#include "Logger.h"

void Observer::add_observer(Subscriber *new_sub) {
    observed_subs.push_back(std::pair(new_sub, Subscriber_inf{static_cast<int>(new_sub->get_health()), static_cast<int>(new_sub->get_damage()), static_cast<int>(new_sub->get_x_coordinate()), static_cast<int>(new_sub->get_y_coordinate())}));
}

std::vector<std::pair<Subscriber*, Observe_inf>> &Observer::check_subscribers() {
    std::vector<std::pair<Subscriber*, Observe_inf>> changed;

    int i = 0;
    for(auto observed: observed_subs){
        Observe_inf changed_inf;
        auto* sub = observed.first;
        auto inf = observed.second;
        bool sub_changed = false;

        if (sub->get_health() != inf.health){
            changed_inf.health_change = true;
            sub_changed = true;
        }
        else if(sub->get_damage() != inf.health){
            changed_inf.damage_change = true;
            sub_changed = true;
        }
        else if(sub->get_x_coordinate() != inf.x_coordinate){
            changed_inf.x_coordinate_change = true;
            sub_changed = true;
        }
        else if(sub->get_y_coordinate() != inf.y_coordinate) {
            changed_inf.y_coordinate_change = true;
            sub_changed = true;
        }

        if(sub_changed) changed.push_back(std::pair(sub, changed_inf));

        if(sub->get_health() == 0){
            changed.erase(changed.begin()+i);
        }
        ++i;

    }
}
