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

class bestbank {
private:
	bankstruct* banki;
	int stringcount;
	int sumvkl;
	int your_month;
	string your_type;
public:
	bestbank(int stringcount);
	~bestbank();
	void workfile(string path);

	void data_input();

	void choosebest();
};

int strcount(string path);
string getfile();
#endif