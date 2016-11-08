/**
 *Wan Lan He - 29469419 
 * Project Dungeons and Dragons
 * Implementation of the observer pattern
 * Subject.cpp
 */
  
#include "Observer.h"
#include <list>
  
   
Subject::Subject(){
    mObserver = new list<Observer*>;
}
  
Subject::~Subject(){
    delete mObserver;
}
  
void Subject::attach(Observer* obs){
    mObserver->push_back(obs);
};
  
void Subject::detach(Observer* obs){
    mObserver->remove(obs);
};
  
void Subject::notifyObs(){
    list<Observer *>::iterator i = mObserver->begin();
    for(; i!=mObserver->end(); ++i)
        (*i)->update();
};