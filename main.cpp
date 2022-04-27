#include "states.h"

using namespace std;
int main () {
	vector<int> ex = {1,0,0,0,1,1,1,0,1};
	states x(ex,"00");
	x.print();
	return 0;
}
