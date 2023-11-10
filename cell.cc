#include "subject.h"
#include "observer.h"
#include "cell.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
	isOn = true;
	notifyObservers(SubscriptionType::All);
}

void Cell::toggle() {
	if (isOn == true){
		isOn = false;
	}else{
		isOn = true;
	}
	notifyObservers(subType());
}

void Cell::setCoords(int r, int c) { 
	this->r = r; 
	this->c = c; 
}

void Cell::notify(Cell & whoNotified) {
	isOn = !isOn;
	notifyObservers(SubscriptionType::All);
}

void Cell::notifyObservers(SubscriptionType t) {
	if (t == SubscriptionType::SwitchOnly){
		for (size_t i = 0; i <= observers.size() - 1; i++){
			observers[i]->notify(*this);
		}
	}else if (t == SubscriptionType::All) {
		observers[observers.size()-1]->notify(*this);
	}
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}

std::string Cell::getName() const {
  std::string name = "(" + std::to_string(r) + "," + std::to_string(c) + ")";
  return name;
}
