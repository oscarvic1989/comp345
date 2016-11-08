/**
 *Wan Lan He - 29469419 
 * Project Dungeons and Dragons
 * Implementation of the observer pattern
 * Observer.h
 */
  
  
#ifndef OBSERVER_H
#define OBSERVER_H
#include "PlayerCharacter.h"
  
class Subject;
  
class Observer {
public: 
    virtual ~Observer(); //destructor
    virtual void notify(Subject* subject){};
    virtual void update()=0;
protected:
    Observer();
};
  
#endif /* OBSERVER_H */