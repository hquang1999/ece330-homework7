#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class states {
	private:
		// These are the initial states. They should not be touched
		string firstState;
		// These are the current states. They can have setters and getters
		string state;
		// User inputted bit string
		vector<int> original;
		
		vector<int> out;
		vector<int> c0;
		vector<int> c1;

	public:
		states(vector<int> ls, string);
		
		void reset();

		void setState(string);
		string getState() const;

		vector<int> getOrg() const;

		vector<int> getBitStr() const;

		vector<int> getC0() const;
		vector<int> getC1() const;

		void findPaths();
		void update(int, string);
		void print();
};
