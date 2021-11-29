//
// Created by igor on 22.11.2021.
//

#include "Subscriber.h"

std::ostream &operator<<(std::ostream &out,  Subscriber &sub) {
    sub.print(out);
    return out;
}