#pragma once
#ifndef _BANKI_H
#define _BANKI_H
#include <string>
using namespace std;


class vkladstruct {
private:
	string vkladname;
	float rate;
	int times;
public:
	string getVkladName();
	float getRate();
	int getTimes();

	void setVkladName(string vkladname);
	void setRate(float rate);
	void setTimes(int times);

	friend ostream& operator<<(ostream& os, const vkladstruct& our_vklad);
};


class bankstruct {
private:
	int count;
	string bankname;
	string banktype;
	vkladstruct* our_vklad;
public:
	bankstruct();
	~bankstruct();

	int getCount();
	string getBankName();
	string getBankType();
	vkladstruct* getOur_Vklad();

	void setCount(int count);
	void setOur_Vklad(int count);
	void setBankName(string bankname);
	void setBankType(string banktype);

	friend ostream& operator<<(ostream& os, const bankstruct& banki);
};
class banklib {
private:
	bankstruct* banki;
	int count;
public:
	banklib();
	banklib(const string& path);
	~banklib();

	banklib& search(float sum, int kMonths, string vkladType);
	banklib(const banklib& banks);
	//banklib& operator=(const banklib& banks);//

	friend ostream& operator << (ostream& out, const banklib& banks);
};

int strcount(string path);
string getfile();
#endif