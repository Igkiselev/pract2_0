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


bestbank::bestbank(int stringcount) {
    this->banki = new bankstruct[stringcount];
    this->vklads = new vkladstruct[stringcount];
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

void bestbank::workfile(string path, int stringcount) {
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
                    banki[j].bankname = token;
                    break;
                case 1:
                    banki[j].banktype = token;
                    break;
                case 2:
                    vklads[j].saving = stoi(token);
                    break;
                case 3:
                    vklads[j].debit = stoi(token);
                    break;
                case 4:
                    vklads[j].cumulative = stoi(token);
                    break;
                case 5:
                    vklads[j].saving_month = stoi(token);
                    break;
                case 6:
                    vklads[j].debit_month = stoi(token);
                    break;
                case 7:
                    vklads[j].cumulative_month = stoi(token);
                    i = -1;
                    j++;
                    break;
                }
                i++;
            }
        }
    }
}

void bestbank::data_input() {
    cout << "Enter count of money" << endl;
    cin >> sumvkl;
    cout << "For how long is the contribution made" << endl;
    cin >> your_month;
}

int bestbank::choosesaving(int stringcount) {
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < vklads[j].saving_month || vklads[j].saving_month == 0) {
            k += 1;
        }
    }
    if (k != stringcount) {
        int maxI = 0;
        int i;
        float maxproc = vklads[0].saving;
        int koef = 0;
        for (i = 1; i < stringcount; i++) {
            if (vklads[i].saving > maxproc && your_month >= vklads[i].saving_month) {
                koef = (int)your_month / vklads[i].saving_month;
                maxproc = vklads[i].saving;
                maxI = i;
            }
        }


        double summa = sumvkl;
        int a = 0;
        for (a = 0; a < koef; a++) {
            summa *= (double)(1.00 + maxproc / 100);
        }
        this->bestname[0] = banki[maxI].bankname;
        this->besttype[0] = "saving";
        this->bestsum[0] = summa;
        //cout<<("Best saving invest: BANK- %s, in the next year you will receive %.2lf \n", banki[maxI]->bankname, summa);
        return 0;
    }
    else if (k == stringcount) {
        cout << "The saving invest is not suitable for the terms" << endl;
        return 1;
    }
}
int bestbank::choosedebit(int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].debit;
    int koef = 0;
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < vklads[j].saving_month || vklads[j].saving_month == 0) {
            k += 1;
        }
    }
    if (k != stringcount) {
        for (i = 1; i < stringcount; i++) {
            if (vklads[i].debit > maxproc && your_month >= vklads[i].debit_month) {
                koef = (int)your_month / vklads[i].debit_month;
                maxproc = vklads[i].debit;
                maxI = i;
            }
        }


        double summa = sumvkl;
        for (j = 0; j < koef; j++) {
            summa *= (double)(1.00 + maxproc / 100);
        }
        this->bestname[1] = banki[maxI].bankname;
        this->besttype[1] = "debit";
        this->bestsum[1] = summa;
        //cout << ("Best debit invest: BANK- banki[maxI]->bankname, in the next year you will receive summa" )<<endl;
        return 0;
    }
    else if (k == stringcount) {
        cout << "The debit invest is not suitable for the terms" << endl;
        return 1;
    }
}
int bestbank::choosecumulative(int stringcount) {
    int maxI = 0;
    int i;
    float maxproc = vklads[0].cumulative;
    int koef = 0;
    int j = 0;
    int k = 0;
    for (j = 0; j < stringcount; j++) {
        if (your_month < vklads[j].saving_month || vklads[j].saving_month == 0) {
            k += 1;
        }
    }
    if (k != stringcount) {
        for (i = 1; i < stringcount; i++) {
            if (vklads[i].cumulative > maxproc && your_month >= vklads[i].cumulative_month) {
                koef = (int)your_month / vklads[i].cumulative_month;
                maxproc = vklads[i].cumulative;
                maxI = i;
            }
        }
        double summa = sumvkl;
        for (j = 0; j < koef; j++) {
            summa *= (double)(1.00 + maxproc / 100);
        }
        this->bestname[2] = banki[maxI].bankname;
        this->besttype[2] ="cumulative";
        this->bestsum[2] = summa;//cout << ("Best cumulative invest: BANK- banki[maxI]->bankname, in the next year you will receive summa")<< endl;
        return 0;
    }
    else if (k == stringcount) {
        cout << "The debit invest is not suitable for the terms" << endl;
        return 1;
    }
}

void bestbank::chooseall(int stringcount) {
    int n = 3;
    int sav = choosesaving(stringcount);
    int deb = choosedebit(stringcount);
    int cum = choosecumulative(stringcount);
    if ((sav + deb + cum) == 3) {
        cout<<"It is impossible to make a profit because the selected period is less than the minimum" << endl;
    }
    else {
        chooseprint(n);
    }
}



void bestbank::chooseprint(int n) {
    int i = 0;
    int k = 0;
    double maxsum = this->bestsum[0];
    for (i = 0; i < n; i++) {
        if (this->bestsum[i] > maxsum) {
            maxsum = this->bestsum[i];
            k = i;
        }
    }
    cout << "The best invest: BANK " << this->bestname[k] << ", his type -" << this->besttype[k] << ". The amount after receiving the deposit will be " << maxsum << endl;
}




bestbank::~bestbank() {
    delete[] banki;
    delete[] vklads;
}