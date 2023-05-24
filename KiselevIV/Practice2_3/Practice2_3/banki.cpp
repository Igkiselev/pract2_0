#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "banki.h"
#define LENGTH 512
#define LEN 30

using namespace std;

int strcount(string path) {
    int stringcount = 0;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "ERROR: Could not open file!" << endl;
    }
    else {
        string line;
        while (getline(file, line))
        {
            if (line != "\0") {
                stringcount++;
            }
        }
        file.close();
    }
    return stringcount;
}

bankstruct::bankstruct() {
}
bankstruct::~bankstruct(){
}
string vkladstruct::getVkladName(){
    return this->vkladname;
}
float vkladstruct::getRate(){
    return this->rate;
}
int vkladstruct::getTimes(){
    return this->times;
}
void vkladstruct::setVkladName(string vkladname) {
    this->vkladname = vkladname;
}
void vkladstruct::setRate(float rate){
    this->rate= rate;
}
void vkladstruct::setTimes(int times){
    this->times = times;
}
int bankstruct::getCount() {
    return this->count;
}
string bankstruct::getBankName() {
    return this->bankname;
}
string bankstruct::getBankType() {
    return this->banktype;
}
vkladstruct* bankstruct::getOur_Vklad() {
    return this->our_vklad;
}
void bankstruct::setBankName(string bankname) {
    this->bankname = bankname;
}
void bankstruct::setCount(int count) {
    this->count = count;
}
void bankstruct::setOur_Vklad(int count) {
    this->our_vklad = new vkladstruct[count];
}
void bankstruct::setBankType(string banktype) {
    this->banktype = banktype;
}

string getfile() {
    string path;
    while (true) {
        cout << "Enter the full location of the file" << endl;
        getline(cin, path);
        ifstream file(path);
        if (file.good()) {
            file.close();
            return path;
        }
        else {
            cout << "ERROR: Could not open file!\n" << endl;
        }
    }
}

banklib::banklib(const string& path) {
    int stringcount = strcount(path);
    this->banki = new bankstruct[stringcount];
    this->count = stringcount;
    int i = 0;
    int j = 0;
    ifstream file(path);
    if (!file.is_open()) {
        cout << "ERROR: Could not open file!" << endl;
    }
    else {
        string str;
        string line;
        string token;
        ifstream file(path);
        while (getline(file, line))
        {
            if (line == "\0") {
                continue;
            }
            stringstream ss(line);
            while (getline(ss, token, ',')) {
                switch (i) {
                case 0:
                    banki[j].setBankName(token);
                    break;
                case 1:
                    banki[j].setBankType(token);
                    break;
                case 2:
                    banki[j].setCount(stoi(token));
                    banki[j].setOur_Vklad(banki[j].getCount());//
                    break;
                case 3:
                    banki[j].getOur_Vklad()[0].setVkladName(token);
                    break;
                case 4:
                    banki[j].getOur_Vklad()[0].setRate(stoi(token));
                    break;
                case 5:
                    banki[j].getOur_Vklad()[0].setTimes(stoi(token));
                    if (banki[j].getCount() == 1) {
                        i = -1;
                        j++;
                    }
                    break;
                case 6:
                    banki[j].getOur_Vklad()[1].setVkladName(token);
                    break;
                case 7:
                    banki[j].getOur_Vklad()[1].setRate(stoi(token));
                    break;
                case 8:
                    banki[j].getOur_Vklad()[1].setTimes(stoi(token));
                    if (banki[j].getCount() == 2) {
                        i = -1;
                        j++;
                    }
                    break;
                case 9:
                    banki[j].getOur_Vklad()[2].setVkladName(token);
                    break;
                case 10:
                    banki[j].getOur_Vklad()[2].setRate(stoi(token));
                    break;
                case 11:
                    banki[j].getOur_Vklad()[2].setTimes(stoi(token));
                    if (banki[j].getCount() == 3) {
                        i = -1;
                        j++;
                    }
                    break;
                }
                i++;
            }
        }
    }
    file.close();

}

banklib& banklib::search(float sum, int kMonths, string vkladType) {
    int a = -1;
    if (vkladType == "saving") {
        a = 0;
    }
    else if (vkladType == "debit") {
        a = 1;
    }
    else if (vkladType == "cumulative") {
        a = 2;
    }
    if (a != -1) {
        int maxI = 0;
        int i;
        float maxproc = -1;
        int koef = 0;
        int j = 0;
        for (i = 1; i < this->count; i++) {
            if (banki[i].getCount() >= (a + 1)) {
                if (banki[i].getOur_Vklad()[a].getRate() > maxproc && kMonths >= banki[i].getOur_Vklad()[a].getTimes()) {
                    koef = (int)kMonths / banki[i].getOur_Vklad()[a].getTimes();
                    maxproc = banki[i].getOur_Vklad()[a].getRate();
                    maxI = i;
                }
            }
        }
        double final_sum = sum;
        double s = (double)banki[maxI].getOur_Vklad()[a].getTimes() / 12;
        for (j = 0; j < koef; j++) {
            final_sum *= (double)(1.00 + maxproc * s / 100);
        }
        if (maxproc == -1) {
            cout << "The debit invest is not suitable for the terms" << endl;
        }
        else {
            cout << banki[maxI];
            cout << banki[maxI].getOur_Vklad()[a];
            cout << "If your invest " << sum << ", you will receive " << final_sum << endl;
        }
    }
    return *this;
}

banklib::banklib(const banklib& banks) {
    count = banks.count;
    banki = new bankstruct[count];

    for (int i = 0; i < count; i++) {
        banki[i].setBankName(banks.banki[i].getBankName());
        banki[i].setBankType(banks.banki[i].getBankType());
        banki[i].setCount(banks.banki[i].getCount());
        banki[i].setOur_Vklad(banki[i].getCount());
        for (int j = 0; j < banki[i].getCount(); j++) {
            banki[i].getOur_Vklad()[j].setRate(banks.banki[i].getOur_Vklad()[j].getRate());
            banki[i].getOur_Vklad()[j].setTimes(banks.banki[i].getOur_Vklad()[j].getTimes());
            banki[i].getOur_Vklad()[j].setVkladName(banks.banki[i].getOur_Vklad()[j].getVkladName());
        }
    }
    //return *this;//
}


ostream& operator<<(ostream& os, const banklib& banks) {
    os << "-----------------------" << endl;
    for (int i = 0; i < banks.count; i++) {
        os << banks.banki[i];
        for (int j = 0; j < banks.banki[i].getCount(); j++) {
            os << banks.banki[i].getOur_Vklad()[j] << " ";
        }
        os << endl;
    }
    os << "-----------------------" << endl;
    return os;
}
ostream& operator<<(ostream& os, const bankstruct& banki) {
    os << "Name of bank - " << banki.bankname << " ";
    os << "Type of  bank - " << banki.banktype << endl;
    return os;
}
ostream& operator<<(ostream& os, const vkladstruct& our_vklad) {
    os << "    Name of vklad - " << our_vklad.vkladname << " ";
    os << "    Rate  of vklad - " << our_vklad.rate << " ";
    os << "    Minimum times of  vklad - " << our_vklad.times << endl;
    return os;
}

banklib::banklib() {}

banklib::~banklib() {
    for (int i = 0; i < this->count; i++) {
        delete[] banki[i].getOur_Vklad();
    }
    delete[] banki;
}
