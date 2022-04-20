#include "struct2.h"

bool palyginimas(studentas& a, studentas& b)
{
    return a.gal < b.gal;
}

void greicioanalizevector(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a, vid = 0;
    vector <studentas> stud;
    for (int i = 0; i < kiekstud; i++)
    {
        stud.push_back(studentas());
        in >> stud[i].vard >> stud[i].pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> stud[i].egz;
        stud[i].gal = vid / kieknd * 0.4 + stud[i].egz * 0.6;
        vid = 0;
    }
    stud.shrink_to_fit();
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nuskaitymas uztruko: " << diff.count() << endl;

    vector <studentas> nend;
    auto rus = high_resolution_clock::now();
    rusiavimasvector(stud, nend);
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;

    nendartiolaiifaila(kieknd, nend, kiekstud);
    kietiakaiifaila(kieknd, stud, kiekstud);

    diff = high_resolution_clock::now() - pradzia;
    cout << endl << kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimasvector(vector <studentas>& stud, vector <studentas>& nend)
{
    sort(stud.begin(), stud.end(), palyginimas);
    int i = 0;
    for (int i = 0; i < stud.size(); i++)//(auto &temp:stud)
    {
        if (stud[i].gal < 5.0)
        {
            nend.push_back(stud[i]);
            stud.erase(stud.begin() + i);
            i--;
        }
    }
    stud.shrink_to_fit();
    nend.shrink_to_fit();
}

void nendartiolaiifaila(int kieknd, vector <studentas> nend, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("nendartiolai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < nend.size(); i++)
    {
        buffer << left << setw(20) << nend[i].vard << " " << left << setw(20) << nend[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << nend[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    nend.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nendartiolu isvedimas i faila: " << diff.count() << endl;
}

void kietiakaiifaila(int kieknd, vector <studentas> stud, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("kietiakai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < stud.size(); i++)
    {
        buffer << left << setw(20) << stud[i].vard << " " << left << setw(20) << stud[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << stud[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    stud.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " kietiakai isvedimas i faila: " << diff.count() << endl;
}


void greicioanalizelist(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a;
    float vid = 0;
    list <studentas> stud;
    studentas s;
    for (int i = 0; i < kiekstud; i++)
    {
        in >> s.vard >> s.pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> s.egz;
        s.gal = vid / kieknd * 0.4 + s.egz * 0.6;
        vid = 0;
        stud.push_back(s);
    }
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nuskaitymas uztruko: " << diff.count() << endl;

    list <studentas> nend;
    auto rus = high_resolution_clock::now();
    rusiavimaslist(stud, nend);
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;

    nendartiolaiifailalist(kieknd, nend, kiekstud);
    kietiakaiifailalist(kieknd, stud, kiekstud);

    diff = high_resolution_clock::now() - pradzia;
    cout << endl << kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimaslist(list <studentas>& stud, list <studentas>& nend)
{
    stud.sort(palyginimas);
    list<studentas>::iterator it = stud.begin();
    while (it->gal < 5.0)
    {
        nend.push_back(*it);
        stud.pop_front();
        it = stud.begin();
    }
    //int i = 0;
    /*for (auto& s : stud)//(auto &temp:stud)
    {
        it = stud.begin();
        advance(it, i);
        if (s.gal < 5.0)
        {
            nend.splice(nend.begin(), stud, it);
            i--;
        }
        i++;
    }*/
}

void nendartiolaiifailalist(int kieknd, list <studentas> nend, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("nendartiolai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (list<studentas>::iterator it = nend.begin(); it != nend.end(); it++)
    {
        buffer << left << setw(20) << it->vard << " " << left << setw(20) << it->pavard << " " << left << setw(20) << fixed << setprecision(2) << it->gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    nend.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nendartiolu isvedimas i faila: " << diff.count() << endl;
}

void kietiakaiifailalist(int kieknd, list <studentas> stud, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("kietiakai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (list<studentas>::iterator it = stud.begin(); it != stud.end(); it++)
    {
        buffer << left << setw(20) << it->vard << " " << left << setw(20) << it->pavard << " " << left << setw(20) << fixed << setprecision(2) << it->gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    stud.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " kietiakai isvedimas i faila: " << diff.count() << endl;
}

void greicioanalizedeque(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a, vid = 0;
    deque <studentas> stud;
    for (int i = 0; i < kiekstud; i++)
    {
        stud.push_back(studentas());
        in >> stud[i].vard >> stud[i].pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> stud[i].egz;
        stud[i].gal = vid / kieknd * 0.4 + stud[i].egz * 0.6;
        vid = 0;
    }
    stud.shrink_to_fit();
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nuskaitymas uztruko: " << diff.count() << endl;

    deque <studentas> nend, kiet;
    auto rus = high_resolution_clock::now();
    rusiavimasdeque(stud, nend);
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;

    nendartiolaiifailadeque(kieknd, nend, kiekstud);
    kietiakaiifailadeque(kieknd, stud, kiekstud);

    diff = high_resolution_clock::now() - pradzia;
    cout << endl << kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimasdeque(deque <studentas>& stud, deque <studentas>& nend)
{
    sort(stud.begin(), stud.end(), palyginimas);
    int i = 0;
    for (int i = 0; i < stud.size(); i++)//(auto &temp:stud)
    {
        if (stud[i].gal < 5.0)
        {
            nend.push_back(stud[i]);
            stud.erase(stud.begin() + i);
            i--;
        }
    }
    stud.shrink_to_fit();
    nend.shrink_to_fit();
}

void nendartiolaiifailadeque(int kieknd, deque <studentas> nend, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("nendartiolai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < nend.size(); i++)
    {
        buffer << left << setw(20) << nend[i].vard << " " << left << setw(20) << nend[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << nend[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    nend.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nendartiolu isvedimas i faila: " << diff.count() << endl;
}

void kietiakaiifailadeque(int kieknd, deque <studentas> stud, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("kietiakai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < stud.size(); i++)
    {
        buffer << left << setw(20) << stud[i].vard << " " << left << setw(20) << stud[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << stud[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    stud.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " kietiakai isvedimas i faila: " << diff.count() << endl;
}
