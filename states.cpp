#include "states.h"

states::states(vector<int> ls, string st) {
	original = ls;
	firstState = st;
	reset();
}

void states::reset() {
	setState(firstState);
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
	for (int i = 0; i < original.size(); i++) {
		update(original.at(i),state);	
	}
}

void states::update(int newI, string ste) {
	if (ste == "00") {
		if (newI == 0) {
			c0.push_back(0);
			c1.push_back(0);
			setState("00");
		} 
		else {
			c0.push_back(1);
			c1.push_back(1);
			setState("10");
		}
	}
	else if (ste == "01") {
		if (newI == 0) {
			c0.push_back(1);
			c1.push_back(1);
			setState("00");
		} 
		else {
			c0.push_back(0);
			c1.push_back(0);
			setState("10");
		}
	}
	else if (ste == "10") {
		if (newI == 0) {
			c0.push_back(0);
			c1.push_back(1);
			setState("01");
		} 
		else {
			c0.push_back(1);
			c1.push_back(0);
			setState("11");
		}
	}
	else {
		if (newI == 0) {
			c0.push_back(1);
			c1.push_back(0);
			setState("01");
		} 
		else {
			c0.push_back(0);
			c1.push_back(1);
			setState("11");
		}
	}
}

void states::print() {
	findPaths();
	cout << "Bit String | c_0 | c_1" << endl;
	for (int i = 0; i < original.size(); i++) {
	cout << "     " << original.at(i) << "    "
			<< " |  " << c0.at(i) << "  |  " 
			<< c1.at(i) << endl;
	} 
	cout << endl;	
}
