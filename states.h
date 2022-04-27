#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class states {
	private:
		vector<int> state;
		int I;
		vector<int> original;

		vector<int> out;
		vector<int> c0;
		vector<int> c1;

	public:
		states(initializer_list<int> &ls);
		
		void reset();

		void setState(vector<int>);
		vector<int> getState() const;

		void setI(int);
		int getI() const;

		//void setOrg(int[]);
		vector<int> getOrg() const;

		vector<int> getBitStr() const;

		vector<int> getC0() const;
		vector<int> getC1() const;

		void findPaths();
		void print();
};
