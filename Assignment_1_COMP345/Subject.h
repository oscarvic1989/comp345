/**
 *Wan Lan He - 29469419 
 * Project Dungeons and Dragons
 * Implementation of the observer pattern
 * Subject.h
 */
 
#pragma once
#include "Observer.h"
#include <list>
using namespace std;
 
class Observer;
 
class Subject {
public:
    virtual void attach(Observer* obs);
    virtual void detach(Observer* obs);
    virtual void notifyObs();
    Subject();
    virtual ~Subject();
     
private:
    list<Observer*> *mObserver;
};