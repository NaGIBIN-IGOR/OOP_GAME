//
// Created by igor on 17.11.2021.
//

#include "Watcher.h"
#include "Observe_inf.h"
#include "Subscriber_inf.h"
#include <sstream>

void Watcher::add_observer(Subscriber *new_sub) {
    Subscriber_inf inf{static_cast<int>(new_sub->get_health()), static_cast<int>(new_sub->get_damage()), static_cast<int>(new_sub->get_x_coordinate()), static_cast<int>(new_sub->get_y_coordinate())};
    observed_subs.push_back(std::pair(new_sub, inf));
}

std::vector<std::pair<Subscriber *, Observe_inf*>>* Watcher::check_subscribers() {
    auto* changed = new std::vector<std::pair<Subscriber*, Observe_inf*>>;

    int i = 0;
    for(auto& observed: observed_subs){
        auto* changed_inf = new Observe_inf;
        auto* sub = observed.first;
        auto inf = observed.second;
        bool sub_changed = false;

        if (sub->get_health() != inf.health){
            changed_inf->health_change = true;
            sub_changed = true;
        }
        if(sub->get_damage() != inf.damage){
            changed_inf->damage_change = true;
            sub_changed = true;
        }
        if(sub->get_x_coordinate() != inf.x_coordinate){
            changed_inf->x_coordinate_change = true;
            sub_changed = true;
        }
        if(sub->get_y_coordinate() != inf.y_coordinate) {
            changed_inf->y_coordinate_change = true;
            sub_changed = true;
        }

        if(sub_changed) changed->push_back(std::pair(sub, changed_inf));
        else delete changed_inf;

//        if(sub->get_health() == 0){
//            changed->erase(changed->begin()+i);
//        }
        ++i;
    }
    if(changed->size() != 0) {
        set_actual_inf();
        return changed;
    }
    return nullptr;
}

void Watcher::set_actual_inf() {
    int i = 0;
    for (auto& elem: observed_subs){
        Subscriber& sub = *elem.first;
        Subscriber_inf& inf = elem.second;
        if(sub.get_health() == 0){
            observed_subs.erase(observed_subs.end()+i);
            continue;
        }
        inf.health = sub.get_health();
        inf.damage = sub.get_damage();
        inf.x_coordinate = sub.get_x_coordinate();
        inf.y_coordinate = sub.get_y_coordinate();
        ++i;
    }

}

void Watcher::remove_dead_subs() {
    int i = 0;
    for(auto& elem: observed_subs){
        if(elem.first->get_health() == 0){
            std::stringstream ss;
            ss<<"\t"<<*elem.first << " помер" << std::endl;
            observed_subs.erase(observed_subs.begin()+i);
            continue;
        }
        ++i;
    }
}


