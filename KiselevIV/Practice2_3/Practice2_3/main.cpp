#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "banki.h"

using namespace std;


int main() {

	string path = getfile();//C:\Users\abobi\banki2.txt
	bestbank bank(strcount(path));

	bank.workfile(path);

	bank.data_input();

	bank.choosebest();
	return 0;

}