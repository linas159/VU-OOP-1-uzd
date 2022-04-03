#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream in("kursiokai.txt");


struct studentas
{
    string vard;
    string pavard;
    vector <int> nd;
    int egz;
    float gal;
    float galmed;
};

void exists_test(const string& name);
void skaicius(int& a);
void ivestisranka(vector <studentas>& stud);
int kiekpazymiu();
void ivestis(vector <studentas>& stud);
bool palyginimas(studentas& a, studentas& b);
void isvestis(vector <studentas> stud);
void failugeneracija(int kieknd);
void failgen(int kieknd, int kiekstud);

void greicioanalizevector(int kiekstud);
void rusiavimasvector(vector <studentas> stud, vector <studentas>& nend, vector <studentas>& kiet, int kiekstud);

void greicioanalizelist(int kiekstud);
void rusiavimaslist(list <studentas> stud, list <studentas>& nend, list <studentas>& kiet, int kiekstud);

void greicioanalizedeque(int kiekstud);
void rusiavimasdeque(deque <studentas> stud, deque <studentas>& nend, deque <studentas>& kiet, int kiekstud);

void nendartiolaiifaila(int kieknd, vector <studentas> nend, int kiekstud);
void kietiakaiifaila(int kieknd, vector <studentas> kiet, int kiekstud);