#include "viterbi.h"

viterbi::viterbi(string str) {
	setBtStr(str);	
}

void viterbi::setBtStr(string in) {
	state = "00";
	input = in;
	errors = 0;
	if (in.size() % 2 == 0) {
		string x;
		string y;
		string z;
		for (int i = 0; i < in.size(); i += 2) {
			x = in.at(i);
			y = in.at(i + 1);
			z = x + y;
			btStr.push_back(z);
		}
	}
	else {
		throw invalid_argument("Invalid input length, must be even length");
	}
}

vector<string> viterbi::getBtStr() const {
	return btStr;
}

vector<string> viterbi::getOut() {
	if (out.empty()) {
		doViterbi();
	}
	return out;
}

void viterbi::doViterbi() {
	state = "00";
	for (int i = 0; i < btStr.size(); i++) {
		out.push_back(matching(btStr.at(i)));	
	}
}

string viterbi::matching(string in) {
	if (state == "00") {
		return findPath("00","10",in);	
	}
	else if (state == "01") {
		return findPath("00","10",in);
	}
	else if (state == "10") {
		return findPath("01","11",in);
	} 
	else {
		return findPath("01","11",in);
	}
}

string viterbi::findPath(string p1, string p2, string comp) {
	int error1 = 0;
	int error2 = 0;
	
	if (p1.at(0) != comp.at(0)) {
		error1++;
	}
	if (p1.at(1) != comp.at(1)) {
		error1++;
	}

	if (p2.at(0) != comp.at(0)) {
		error2++;
	}
	if (p2.at(1) != comp.at(1)) {
		error2++;
	}

	if (error1 < error2) {
		state = p1;
		errors += error1;
		return p1;
	} 
	else if (error1 > error2) {
		state = p2;
		errors += error2;
		return p2;
	}
	else {
		srand(time(0));
		int t = rand() % 100;
		if (t >= 49) {
			state = p1;
			errors += error1;
			return p1;
		}
		else {
			state = p2; 
			errors += error2;
			return p2;
		} 
	}
}

void viterbi::print() {
	if (out.empty()) {
		doViterbi();
	}
	
	cout << "   Input String: " << input << endl;
	cout << "Viterbi Decoded: ";
	
	for (int i = 0; i < out.size(); i++) {
		cout << out.at(i);
	}

	cout << endl;
	cout << "         Errors: " << errors << endl;
	float accuracy = 100 - (((float) errors / (float) input.size()) * 100);
	cout << "       Accuracy: " << accuracy << "%" << endl;
}
