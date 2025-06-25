#include "complex.h"

complex A,B,C,D,E,F;

int main(){
	
	initializeVariable();
	
	mainFaction();
	
	return 0;
}


void initializeVariable(){

	read_comp(&A, 0, 0);
	read_comp(&B, 0, 0);
	read_comp(&C, 0, 0);
	read_comp(&D, 0, 0);
	read_comp(&E, 0, 0);
	read_comp(&F, 0, 0);
}
