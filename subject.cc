#include "subject.h"
#include "observer.h"

void Subject::attach(Observer *o){
    observers.emplace_back(o);
}

std::string Subject::getObserverNames() const{
    std::string name = "";
    int i = 0;
    for (auto &&ob : observers){
        if (i != 0){
            name += ", ";
        }
        name += ob->getName();
        i = 1;
    }
    return name;
}
