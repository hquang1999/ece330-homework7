#include "states.h"

states::states(const initializer_list<int> &ls, string &st) {
	copy(ls.begin(),ls.end(),original.begin());
	
	firstState = st;
	reset();
}

void states::reset() {
	setState(firstState);
//	setI(0);
	out.clear();
	c0.clear();
	c1.clear();
}

void states::setState(string nxt) {
	state = nxt;
}

string states::getState() const {
	return state;
}
/*
void states::setI(int i) {
	I = i;
}

int states::getI() const {
	return I;
}
*/
vector<int> states::getOrg() const {
	return original;
}

vector<int> states::getBitStr() const {
	return out;
}

vector<int> states::getC0() const {
	return c0;
}

vector<int> states::getC1() const {
	return c1;
}

void states::findPaths() {
	reset();
	for (int i = 0; i < orginal.size(); i++) {
		update(original.at(i),state);	
	}
}

void states::update(int newI, string &ste) {
	switch(ste) {
		case "00": 
			if (newI == 0) {
				c0.push_back(0);
				c1.push_back(0);
				setState("00");
			} 
			else {
				c0.push_back(1);
				c1.Push_back(1);
				setState("10");
			}
			break;
		case "01":
			if (newI == 0) {
				c0.push_back(1);
				c1.push_back(1);
				setState("00");
			} 
			else {
				c0.push_back(0);
				c1.Push_back(0);
				setState("10");
			}
			break;
		case "10":
			if (newI == 0) {
				c0.push_back(0);
				c1.push_back(1);
				setState("01");
			} 
			else {
				c0.push_back(1);
				c1.Push_back(0);
				setState("11");
			}
			break;
		case "11":
			if (newI == 0) {
				c0.push_back(1);
				c1.push_back(0);
				setState("01");
			} 
			else {
				c0.push_back(0);
				c1.Push_back(1);
				setState("11");
			}
			break;
		
	}
}
void states::print() {

}
