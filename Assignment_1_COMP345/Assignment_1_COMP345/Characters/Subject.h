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
    //! Attach an Observer
    virtual void attach(Observer* obs);
    
    //! Remove an Observer
    virtual void detach(Observer* obs);
    
    //! Notify Observer that there is a modification
    virtual void notifyObs();
    Subject();
    virtual ~Subject();
      
private:
    //! List of Observers from the Subject
    list<Observer*> *mObserver;
};
