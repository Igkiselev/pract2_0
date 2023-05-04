#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "banki.h"

using namespace std;


int main() {

	string path = getfile();//C:\Users\abobi\banki2.txt
	int stringcount = strcount(path);
	bestbank bank(stringcount);
	
	bank.workfile(path, stringcount);

	bank.data_input();

	bank.chooseall(stringcount);
	return 0;

}
