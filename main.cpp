#include "states.h"
#include "viterbi.h"

using namespace std;
int main () {
	// INPUTS: Vector<int> {}, starting state, "00"
	states x({1,0,0,0,1,1,1,0,1},"00");
	x.print();
	
	// INPUTS: bit string (MUST BE EVEN and 0's and 1's ONLY) 
	viterbi y("000101110010");
	y.print();
	return 0;
}
