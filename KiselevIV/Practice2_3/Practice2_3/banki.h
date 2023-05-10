#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#include <string>
using namespace std;


class bankstruct {
private:
	string bankname;
	string banktype;
public:
	string getBankName();
	string getBankType();
	void setBankName(string bankname);
	void setBankType(string banktype);
};

class vkladstruct {
private:
	float saving;
	float debit;
	float cumulative;
	int saving_month;
	int debit_month;
	int cumulative_month;
public:
	float getSaving();
	float getDebit();
	float getCumulative();
	int getSaving_Month();
	int getDebit_Month();
	int getCumulative_Month();
	void setSaving(float saving);
	void setDebit(float debit);
	void setCumulative(float cumulative);
	void setSaving_Month(int Month);
	void setDebit_Month(int Month);
	void setCumulative_Month(int Month);
};

class bestbank {
private:
	bankstruct* banki;
	vkladstruct* vklads;
	string bestname[3];
	string besttype[3];
	float bestsum[3];
	int sumvkl;
	int your_month;

	int choosesaving(int stringcount);
	int choosedebit(int stringcount);
	int choosecumulative(int stringcount);
	void chooseprint(int n);
public:

	bestbank(int stringcount);
	~bestbank();
	void workfile(string path, int stringcount);

	void data_input();

	void chooseall(int stringcount);
};

int strcount(string path);
string getfile();
#endif