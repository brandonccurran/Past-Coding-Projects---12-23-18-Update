#include "inverter.h"

int main (int argc, char * argv []){
	if (argc != 2){
		cerr << "Wrong number of inputs, need two." << endl;
		exit (-1);
	}

	cout << build_inverted_index(argv[1]);

	return 0;
}
