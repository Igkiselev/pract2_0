#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "banki.h"

using namespace std;


int main() {

	string path = getfile();//C:\Users\abobi\banki2.txt
	banklib banks(path);
	cout << banks;

	float sum;
	int kMonths;
	string vkladType;
	cout << "Enter count of money" << endl;
	cin >> sum;
	cout << "For how long is the contribution made" << endl;
	cin >> kMonths;
	cout << "Enter type of vklad(saving, debit or cumulative)." << endl;
	cin >> vkladType;
	if (vkladType != "saving" && vkladType != "debit" && vkladType != "cumulative") {
		printf("ERROR!This type of vklad does not exist\n");
	}
	banklib mybank = banks.search(sum, kMonths, vkladType);//1 стр. -конструктор копирования, 2- опер. присваивания
	cout << mybank;
	return 0;

}