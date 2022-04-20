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

bool palyginimas(studentas& a, studentas& b);

void greicioanalizevector(int kiekstud);
void rusiavimasvector(vector <studentas>& stud, vector <studentas>& nend);
void nendartiolaiifaila(int kieknd, vector <studentas> nend, int kiekstud);
void kietiakaiifaila(int kieknd, vector <studentas> stud, int kiekstud);

void greicioanalizelist(int kiekstud);
void rusiavimaslist(list <studentas>& stud, list <studentas>& nend);
void nendartiolaiifailalist(int kieknd, list <studentas> nend, int kiekstud);
void kietiakaiifailalist(int kieknd, list <studentas> stud, int kiekstud);

void greicioanalizedeque(int kiekstud);
void rusiavimasdeque(deque <studentas>& stud, deque <studentas>& nend);
void nendartiolaiifailadeque(int kieknd, deque <studentas> nend, int kiekstud);
void kietiakaiifailadeque(int kieknd, deque <studentas> stud, int kiekstud);
