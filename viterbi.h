#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class viterbi {
	private:
		vector<string> btStr;
		vector<string> out;
		string state;
		string input;
		int errors;

	public:
		viterbi(string);

		void setBtStr(string);
		vector<string> getBtStr() const;
		vector<string> getOut(); 

		void doViterbi();
		string matching(string);
		string findPath(string, string, string);
		void print(); 
};
