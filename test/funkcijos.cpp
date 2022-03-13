#include "struct.h"

void exists_test(const string& name)
{
    ifstream file(name);
    if (!file)
    {
        file.close();
        throw "Failas neegzistuoja";
    }
    file.close();
}

void skaicius(int& a) //funkcija neleidzianti ivesti raides ten kur reikia skaiciaus
{
    cin >> a;
    while (!cin)
    {
        cin.clear(); // reset failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziame neteisinga ivesti
        cout << "Prasome ivesti skaiciu: ";
        cin >> a;
    }
}

void ivestisranka(vector <studentas>& stud)
{
    int i = 0;
    while (1 > 0)
    {
        stud.push_back(studentas());
        cout << "Iveskite varda: ";
        cin >> stud[i].vard;
        cout << "Iveskite pavarde: ";
        cin >> stud[i].pavard;
        char ar;
        cout << "Ar sugeneruoti pazymius atsitiktinai? (T/N)";
        while (1 > 0)
        {
            cin >> ar;
            if (ar != 't' && ar != 'n' && ar != 'T' && ar != 'N')
                cout << "Irasykite atitinkamai T arba N: ";
            else break;
        }
        if (ar == 't' || ar == 'T')
        {
            cout << "Kiek norite sugeneruoti namu darbu pazymiu? ";
            int kiek;
            cin >> kiek;
            while (!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
            {
                cin.clear(); // istrina fail reiksme
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                cout << "Iveskite skaiciu: ";
                cin >> kiek;
            }
            while (1 > 0)
            {
                if (kiek == 0)
                    cout << "Isveskite skaiciu didesni uz 0: ";
                else break;
                cin >> kiek;
            }
            float vid = 0, med;
            for (int j = 0; j < kiek; j++)
            {
                stud[i].nd.push_back(rand() % 10 + 1);
                cout << stud[i].nd[j] << " ";
                vid = vid + stud[i].nd[j];
            }
            cout << endl;
            sort(stud[i].nd.begin(), stud[i].nd.end());
            if (kiek % 2 == 0)
            {
                med = (stud[i].nd[kiek / 2] + stud[i].nd[kiek / 2 - 1]) / 2.0;
            }
            else
            {
                med = stud[i].nd[kiek / 2];
            }
            vid = vid / kiek;
            cout << "Egzamino rezultatas: ";
            stud[i].egz = rand() % 10 + 1;
            cout << stud[i].egz << endl;
            stud[i].gal = vid * 0.4 + stud[i].egz * 0.6;
            stud[i].galmed = med * 0.4 + stud[i].egz * 0.6;
        }
        else
        {
            cout << "Iveskite studento pazymius, norint baigti iveskite 0: ";
            int a, kiekpaz = 0;
            float vid = 0, med;
            while (1 > 0)
            {
                cin >> a;
                while (!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                {
                    cin.clear(); // istrina fail reiksme
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                    cout << "Iveskite skaiciu: ";
                    cin >> a;
                }
                if (a != 0)
                {
                    while (a < 0 || a>10)
                    {
                        cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                        cin >> a;
                    }
                    stud[i].nd.push_back(a);
                    kiekpaz++;
                    vid += a;
                }
                else
                {
                    while (kiekpaz == 0)
                    {
                        cout << "Prasome ivesti bent viena pazymi: ";
                        cin >> a;
                        while (!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                        {
                            cin.clear(); // istrina fail reiksme
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                            cout << "Iveskite skaiciu: ";
                            cin >> a;
                            while (a < 0 || a>10)
                            {
                                cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                                cin >> a;
                            }
                        }
                        if (a > 0 && a <= 10)
                        {
                            stud[i].nd.push_back(a);
                            kiekpaz++;
                            vid += a;
                        }

                    }
                    if (kiekpaz != 0)
                        break;
                }
            }
            vid = vid / kiekpaz;
            sort(stud[i].nd.begin(), stud[i].nd.end());
            if (kiekpaz % 2 == 0)
            {
                med = (stud[i].nd[kiekpaz / 2] + stud[i].nd[kiekpaz / 2 - 1]) / 2.0;
            }
            else
            {
                med = stud[i].nd[kiekpaz / 2];
            }
            cout << "Iveskite egzamino rezultata: ";
            cin >> a;
            while (1 > 0)
            {
                while (!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                {
                    cin.clear(); // istrina fail reiksme
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                    cout << "Iveskite skaiciu: ";
                    cin >> a;
                }
                if (a <= 0 || a > 10)
                {
                    cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                    cin >> a;
                }
                else
                {
                    break;
                }
            }
            stud[i].egz = a;
            stud[i].gal = vid * 0.4 + stud[i].egz * 0.6;
            stud[i].galmed = med * 0.4 + stud[i].egz * 0.6;
        }
        i++;
        cout << "Ar norite ivesti nauja studenta? (T/N)";
        while (1 > 0)
        {
            cin >> ar;
            if (ar != 't' && ar != 'n' && ar != 'T' && ar != 'N')
                cout << "Irasykite atitinkamai T arba N: ";
            else break;
        }
        if (ar == 'n' || ar == 'N')
            break;
    }

}

int kiekpazymiu()
{
    int i = 0;
    string a;
    while (true)
    {
        in >> a;
        i++;
        if (a == "Egz.")
        {
            break;
        }
    }
    return i - 3;
}

void ivestis(vector <studentas>& stud)
{
    int kieknd;
    kieknd = kiekpazymiu();
    int kiekstud = 0;
    while (!in.eof())
    {
        stud.push_back(studentas());
        in >> stud[kiekstud].vard;
        in >> stud[kiekstud].pavard;
        int a;
        float vid = 0, med;
        for (int i = 0; i < kieknd; i++)
        {
            in >> a;
            stud[kiekstud].nd.push_back(a);
            vid += a;
        }
        sort(stud[kiekstud].nd.begin(), stud[kiekstud].nd.end());
        if (kieknd % 2 == 0)
        {
            med = (stud[kiekstud].nd[kieknd / 2] + stud[kiekstud].nd[kieknd / 2 - 1]) / 2.0;
        }
        else
        {
            med = stud[kiekstud].nd[kieknd / 2];
        }
        stud[kiekstud].nd.clear();

        vid = vid / kieknd;
        in >> stud[kiekstud].egz;
        stud[kiekstud].gal = vid * 0.4 + stud[kiekstud].egz * 0.6;
        stud[kiekstud].galmed = med * 0.4 + stud[kiekstud].egz * 0.6;
        kiekstud++;

    }
    /*for (int i = 0; i < kiekstud; i++) //nuskaitytu duomenu isvedimas
    {
        cout << stud[i].vard << " " << stud[i].pavard << " ";
        for (int j = 0; j < kieknd; j++)
        {
            cout << stud[i].nd[j] << " ";
        }
        cout << stud[i].egz << endl;
    }*/
}

bool palyginimas(studentas& a, studentas& b)
{
    return a.vard < b.vard;
}

void isvestis(vector <studentas> stud)
{
    sort(stud.begin(), stud.end(), palyginimas);
    stringstream my_buffer;
    my_buffer << "|" << left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)" << "|" << left << setw(20) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < stud.size(); i++)
    {
        my_buffer << "|" << left << setw(20) << stud[i].vard << "|" << left << setw(20) << stud[i].pavard << "|" << left << setw(20) << fixed << setprecision(2) << stud[i].gal << "|" << left << setw(20) << fixed << setprecision(2) << stud[i].galmed << endl;
    }
    cout << my_buffer.str();
    my_buffer.clear();
}

void failugeneracija(int kieknd)
{
    string out1="kursiokai1000.txt";
    string out2="kursiokai10000.txt";
    string out3="kursiokai100000.txt";
    string out4="kursiokai1000000.txt";
    string out5="kursiokai10000000.txt";
    string nin, kin;

    auto pradzia = high_resolution_clock::now();
    failgen(out1, kieknd, 1000); //1000
    auto pradzianen = high_resolution_clock::now();
    nin="nendartiolai1000.txt";
    nendartiolaiifaila(out1,nin,kieknd,1000);
    kin="kietiakai1000.txt";
    kietiakaiifaila(out1,kin, kieknd, 1000);
    auto pabaigakiet = high_resolution_clock::now();
    duration<double> diff = pabaigakiet - pradzianen;
    cout<<"1000 irasimas i abu failus uztruko: " << diff.count() << endl;
    auto pabaiga = high_resolution_clock::now();
    diff = pabaiga - pradzia;
    cout << endl << "1000 isviso uztruko: " << diff.count() << endl << endl;
    system("Pause");

    pradzia = high_resolution_clock::now();
    failgen(out2, kieknd, 10000); //10000
    pradzianen = high_resolution_clock::now();
    nin="nendartiolai10000.txt";
    nendartiolaiifaila(out2, nin, kieknd, 10000);
    kin="kietiakai10000.txt";
    kietiakaiifaila(out2, kin, kieknd, 10000);
    pabaigakiet = high_resolution_clock::now();
    diff = pabaigakiet - pradzianen;
    cout << "10000 irasimas i abu failus uztruko: " << diff.count() << endl;
    pabaiga = high_resolution_clock::now();
    diff = pabaiga - pradzia;
    cout << endl << "10000 isviso uztruko: " << diff.count() << endl << endl;
    system("Pause");

    pradzia = high_resolution_clock::now();
    failgen(out3, kieknd, 100000);//100000
    pradzianen = high_resolution_clock::now();
    nin="nendartiolai100000.txt";
    nendartiolaiifaila(out3, nin, kieknd, 100000);
    kin="kietiakai100000.txt";
    kietiakaiifaila(out3, kin, kieknd, 100000);
    pabaigakiet = high_resolution_clock::now();
    diff = pabaigakiet - pradzianen;
    cout << "100000 irasimas i abu failus uztruko: " << diff.count() << endl;
    pabaiga = high_resolution_clock::now();
    diff = pabaiga - pradzia;
    cout << endl << "100000 isviso uztruko: " << diff.count() << endl << endl;
    system("Pause");

    pradzia = high_resolution_clock::now();
    failgen(out4, kieknd, 1000000);//1000000
    pradzianen = high_resolution_clock::now();
    nin="nendartiolai1000000.txt";
    nendartiolaiifaila(out4, nin, kieknd, 1000000);
    kin="kietiakai1000000.txt";
    kietiakaiifaila(out4, kin, kieknd, 1000000);
    pabaigakiet = high_resolution_clock::now();
    diff = pabaigakiet - pradzianen;
    cout << "1000000 irasimas i abu failus uztruko: " << diff.count() << endl;
    pabaiga = high_resolution_clock::now();
    diff = pabaiga - pradzia;
    cout <<endl<< "1000000 isviso uztruko: " << diff.count() << endl << endl;
    system("Pause");

    pradzia = high_resolution_clock::now();
    failgen(out5, kieknd, 10000000);//10000000
    pradzianen = high_resolution_clock::now();
    nin="nendartiolai10000000.txt";
    nendartiolaiifaila(out5, nin, kieknd, 10000000);
    kin="kietiakai10000000.txt";
    kietiakaiifaila(out5, kin, kieknd, 10000000);
    pabaigakiet = high_resolution_clock::now();
    diff = pabaigakiet - pradzianen;
    cout << "10000000 irasimas i abu failus uztruko: " << diff.count() << endl;
    pabaiga = high_resolution_clock::now();
    diff = pabaiga - pradzia;
    cout << endl << "10000000 isviso uztruko: " << diff.count() << endl << endl;
    system("Pause");
}

void failgen(string &out1,int kieknd, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out(out1.c_str());
    stringstream buffer;
    string vardas, pavarde;
    for (int i = 1; i <= kiekstud; i++)
    {
        vardas = "Vardas";
        pavarde = "Pavarde";
        vardas = vardas + std::to_string(i);
        pavarde = pavarde + std::to_string(i);
        buffer << left << setw(20) << vardas << " " << left << setw(20) << pavarde << " ";
        for (int j = 0; j < kieknd; j++)
        {
            buffer << left << setw(20) << rand() % 10 + 1 << " ";
        }
        buffer << left << setw(20) << rand() % 10 + 1 << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    auto pabaiga = high_resolution_clock::now();
    duration<double> diff = pabaiga - pradzia;
    cout << kiekstud << " generavimas i faila: " << diff.count() << endl;
}

void nendartiolaiifaila(string out1, string in1, int kieknd, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ifstream in (out1.c_str());
    ofstream out(in1.c_str());
    stringstream buffer;
    string vard, pavard;
    int vid = 0, nd, egz;
    float gal;
    for (int i = 0; i < kiekstud; i++)
    {
        in >> vard >> pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> nd;
            vid += nd;
        }
        in >> egz;
        gal = vid / kieknd * 0.4 + egz * 0.6;
        vid = 0;
        if (gal < 5.0)
        {
            buffer << left << setw(20) << vard << " " << left << setw(20) << pavard << " " << left << setw(20) << fixed << setprecision(2)<< gal << endl;
        }
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    in.close();
    auto pabaiga = high_resolution_clock::now();
    duration<double> diff = pabaiga - pradzia;
    cout <<kiekstud<< " nendartiolai i faila: " << diff.count() << endl;
}

void kietiakaiifaila(string out1, string in1, int kieknd, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ifstream in(out1.c_str());
    ofstream out(in1.c_str());
    stringstream buffer;
    string vard, pavard;
    int vid = 0, nd, egz;
    float gal;
    for (int i = 0; i < kiekstud; i++)
    {
        in >> vard >> pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> nd;
            vid += nd;
        }
        in >> egz;
        gal = vid / kieknd * 0.4 + egz * 0.6;
        vid = 0;
        if (gal >= 5.0)
        {
            buffer << left << setw(20) << vard << " " << left << setw(20) << pavard << " " << left << setw(20) << fixed << setprecision(2) << gal << endl;
        }
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    in.close();
    auto pabaiga = high_resolution_clock::now();
    duration<double> diff = pabaiga - pradzia;
    cout << kiekstud << " kietiakai i faila: " << diff.count() << endl;
}