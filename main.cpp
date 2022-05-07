#include "states.h"
#include "viterbi.h"

using namespace std;
int main () {
	states x({1,0,0,0,1,1,1,0,1},"00");
	x.print();
	
	viterbi y("000101110010");
	y.print();
	return 0;
}
