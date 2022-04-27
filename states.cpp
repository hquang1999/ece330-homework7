#include "states.h"

states::states(initializer_list<int> &ls) {
	copy(original.begin(),original.end(),ls.begin()),
	reset();
}

void states::reset() {
	vector<int> temp = {0,0};
	setState(temp);
	setI(0);
	out.clear();
	c0.clear();
	c1.clear();
}

void states::setState(vector<int> nxt) {
	state = nxt;
}

vector<int> states::getState() const {
	return state;
}

void states::setI(int i) {
	I = i;
}

int states::getI() const {
	return I;
}
/*
void states::setOrg(int arr[]) {
	int max = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < max; i++) {
		original.push_back(arr[i]);
	}	
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
}
void states::print() {

}
