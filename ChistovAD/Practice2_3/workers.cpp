#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "workers.h";
#define N 100

string get_path() {
	string path;
	do {
		cout << "Enter the file path:";
		cin >> path;
		ifstream in(path);
		if (!in.is_open()) {
			cout << "Ooops.....Something went wrong......" << endl;
		}
		else {
			in.close();
			return path;
		}
	} while (true);
}

worker::worker() {
	id=" ";
	profession = " ";
	 education = " ";
	last_job = " ";
	 rsn_dismiss = " ";
	 family_status = " ";
	contact_info = 0;
}

worker::worker(const string  id, const string  profession, const string  education, const string  last_job, const string  rsn_dismiss, const string  family_status, int  contact_info) {
	this->id = id;
	this->profession = profession;
	this->education = education;
	this->last_job = last_job;
	this->rsn_dismiss = rsn_dismiss;
	this->family_status = family_status;
	this->contact_info = contact_info;
}

void worker::adding(string _id, string _profession, string _education, string _last_job, string _rsn_dismiss, string  _family_status, int _contact_info)
{
	id = _id;
	profession = _profession;
	education = _education;
	last_job = last_job;
	rsn_dismiss = _rsn_dismiss;
	family_status = _family_status;
	contact_info = _contact_info;
}

int labor::amount(const string& path)
{
	fstream file;
	file.open(path);
	string line;
	int count{ 0 };
	ifstream in(path);
	while (getline(in, line))
	{
		if (line != "\0") {
			count++;
		}
	}
	in.close();
	return count;
}

labor::labor(const string& path) {
	this->n = amount(path);
	this->w = new worker[n];
	fstream file;
	string   id, profession, education, last_job, rsn_dismiss, family_status;
	int  contact_info;
	file.open(path);
	int i = 0, j = 0;
	string line, s;
	ifstream in(path);
	while (getline(in, line))
	{
		if (line == "\0") {
			continue;
		}
		stringstream ss(line);
		while (getline(ss, s, ';')) {
			switch (i) {
			case 0:
				id = s;
				break;
			case 1:
				profession = s;
				break;
			case 2:
				education = s;
				break;
			case 3:
				last_job = s;
				break;
			case 4:
				rsn_dismiss = s;
				break;
			case 5:
				family_status = s;
				break;
			case 6:
				contact_info = stoi(s);
				w[j].adding(id, profession, education, last_job, rsn_dismiss, family_status, contact_info);
				j++;
				i = -1;
				break;
			}
			i++;
		}
	}
	in.close();
}


string worker::get_education()
{
	return education;
}
float labor::higher_education() {
	float counter = 0;
	int i;
	cout << "All employees with higher education from the database:" << endl;
	for (i = 0; i < n; i++) {
		if ((w[i].get_education()) != "no") {
			cout << w[i];
			counter++;
		}
	}
	return (counter / n) * 100;
}

labor::~labor() {
	delete[] this->w;
}

ostream& operator<<(ostream& out, const worker& w)
{
	out << w.id << " " << w.education << endl;
	return out;
}



