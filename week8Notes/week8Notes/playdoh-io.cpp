#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Playdoh {
	char colour[30];
	int weight{ 0 };
public:
    Playdoh() {}
    ~Playdoh() {}
    Playdoh(const char* col, int wei) : weight(wei) {
        setColour(col);
    }
    ostream& display(ostream& os) const {
        os << "Playdoh Colour: " << colour << ", Weight: " << weight << endl;
        return os;
    }
    istream& read(istream& is) {
        is.ignore(1000, ':');
        is.ignore();
        //getline(is, colour, ',');
        is.getline(colour, 30, ',');
        is.ignore(1000, ':');
        is >> weight;
        return is;
    }
    void setColour(const char* col) {
        strncpy(colour, col, 30);
    }
    void setWeight(int wei) { weight = wei; }
    string getColour() const { return colour; }
    int getWeight() const { return weight; }
};
istream& operator>>(istream& is, Playdoh& p) {
    p.read(is);
    return is;
}
ostream& operator<<(ostream& os, Playdoh& p) {
    p.display(os);
    return os;
}

void checkRecord(int row, ifstream& fin) {
    int i;
    Playdoh p;
    fin.clear();
    fin.seekg(0);
    for (i = 0; i < row; i++) {
        fin >> p;
    }
    if (fin) {
        cout << i << ": " << p;
    }
    else {
        cout << "Record out of range???" << endl;
    }
}

#define ex1
#define ex2
#define ex3
#define ex4
#define ex5
#define ex6

int main() {
    vector<Playdoh> ps = {
    {"Red", 22},
    {"Red", 24},
    {"Blue", 29},
    {"Blue", 23},
    {"Blue", 25},
    {"Red", 21},
    {"White", 90},
    {"Yellow", 40},
    {"Green", 50}
    };
#ifdef ex1
    cout << endl << "outfile example" << endl;
    ofstream outfile("playdohs.txt");
    if (!outfile)
        return 1;
    for (auto& play : ps) {
        outfile << play;
    }
    outfile.close();
#endif // ex1

#ifdef ex2
    cout << endl << "Infile example" << endl;
    ifstream infile("playdohs.txt");
    if (infile) {
        Playdoh temp;
        while (infile >> temp) {
            cout << temp;
        }
    }
#endif // ex2

#ifdef ex3
    cout << endl << "Checking records in the playdoh file" << endl;
    checkRecord(5, infile);
    checkRecord(2, infile);
    checkRecord(9, infile);
    checkRecord(200, infile);
    infile.close();

#endif // ex3

#ifdef ex4
    cout << endl << "In and out file seeking" << endl;
    fstream inoutfile("playdohs.txt");
    inoutfile.seekp(0, ios::end);
    inoutfile << Playdoh("Gray", 20) << Playdoh("Brown", 30) << Playdoh("Gold", 10);
    inoutfile.seekp(0, ios::beg);
    inoutfile << Playdoh("Silver", 20) << Playdoh("Cyan", 30) << Playdoh("Pink", 10);
    inoutfile.close();
#endif // ex4

#ifdef ex5
    cout << endl << "Binary file out example" << endl;
    ofstream outbinfile("playdohs.dat", ios::binary);
    for (auto& play : ps) {
        outbinfile.write((const char*)&play, sizeof(Playdoh));
    }
    outbinfile.close();
#endif // ex5

#ifdef ex6
    cout << endl << "Binary file in example" << endl;
    ifstream inbinfile("playdohs.dat", ios::binary);
    Playdoh temp2;
    int counter = 0;
    while (!inbinfile.read((char*)&temp2, sizeof(Playdoh)).fail()) {
        cout << ++counter << ": " << temp2 << endl;
    }
    inbinfile.close();
#endif // ex6

    return 0;
}