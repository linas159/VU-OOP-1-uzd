#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;


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
void rusiavimasvector(vector <studentas> &stud, vector <studentas>& nend, vector <studentas>& kiet);

void greicioanalizelist(int kiekstud);
void rusiavimaslist(list <studentas> &stud, list <studentas>& nend, list <studentas>& kiet);

void greicioanalizedeque(int kiekstud);
void rusiavimasdeque(deque <studentas> &stud, deque <studentas>& nend, deque <studentas>& kiet);

void nendartiolaiifaila(int kieknd, vector <studentas> nend, int kiekstud);
void kietiakaiifaila(int kieknd, vector <studentas> kiet, int kiekstud);

//antra strategija

void greicioanalizevector2(int kiekstud);
void rusiavimasvector2(vector <studentas>& stud, vector <studentas>& nend);
void nendartiolaiifaila2(int kieknd, vector <studentas> nend, int kiekstud);
void kietiakaiifaila2(int kieknd, vector <studentas> stud, int kiekstud);

void greicioanalizelist2(int kiekstud);
void rusiavimaslist2(list <studentas>& stud, list <studentas>& nend);
void nendartiolaiifailalist2(int kieknd, list <studentas> nend, int kiekstud);
void kietiakaiifailalist2(int kieknd, list <studentas> stud, int kiekstud);

void greicioanalizedeque2(int kiekstud);
void rusiavimasdeque2(deque <studentas>& stud, deque <studentas>& nend);
void nendartiolaiifailadeque2(int kieknd, deque <studentas> nend, int kiekstud);
void kietiakaiifailadeque2(int kieknd, deque <studentas> stud, int kiekstud);
