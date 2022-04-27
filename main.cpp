#include "states.h"

using namespace std;
int main () {
	states x({1,0,0,0,1,1,1,0,1},"00");
	x.print();
	
	states y({1,0,1,0,1,0,1,0,1,0,1,1,1,0,0},"00");
	y.print();
	return 0;
}
