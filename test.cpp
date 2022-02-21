#include <bits/stdc++.h>

using namespace std;

struct studentas
{
    string vard;
    string pavard;
    vector <int> nd;
    int egz;
    float gal;
    float galmed;
};

void ivestis(vector <studentas> &stud)
{
    int i=0;
    while (1>0)
    {
        stud.push_back(studentas());
        cout<<"Iveskite varda: ";
        cin>>stud[i].vard;
        cout<<"Iveskite pavarde: ";
        cin>>stud[i].pavard;
        char ar;
        cout<<"Ar sugeneruoti pazymius atsitiktinai? (T/N)";
        while (1>0)
        {
            cin>>ar;
            if (ar != 't' && ar != 'n' && ar != 'T' && ar != 'N')
                cout<<"Irasykite atitinkamai T arba N: ";
            else break;
        }
        if (ar== 't' || ar == 'T')
        {
            cout<<"Kiek norite sugeneruoti namu darbu pazymiu? ";
            int kiek;
            while (1>0)
            {
                cin>>kiek;
                if(kiek==0)
                    cout<<"Isveskite skaiciu didesni uz 0: ";
                else break;
            }
            float vid=0,med;
            for (int j=0;j<kiek;j++)
            {
                stud[i].nd.push_back(rand()%10+1);
                cout<<stud[i].nd[j]<<" ";
                vid=vid+stud[i].nd[j];
            }
            cout<<endl;
            sort(stud[i].nd.begin(), stud[i].nd.end());
            if (kiek%2==0)
            {
                med=(stud[i].nd[kiek/2]+stud[i].nd[kiek/2-1])/2.0;
            }
            else
            {
                med=stud[i].nd[kiek/2];
            }
            vid=vid/kiek;
            cout<<"Egzamino rezultatas: ";
            stud[i].egz=rand()%10+1;
            cout<<stud[i].egz<<endl;
            stud[i].gal=vid*0.4+stud[i].egz*0.6;
            stud[i].galmed=med*0.4+stud[i].egz*0.6;
        }
        else
        {
            cout<<"Iveskite studento pazymius, norint baigti iveskite 0: ";
            int a, kiekpaz=0;
            float vid=0, med;
            while (1>0)
            {
                cin >> a;
                while(!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                    {
                        cin.clear(); // istrina fail reiksme
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                        cout << "Iveskite skaiciu: ";
                        cin >> a;
                    }
                if (a!=0)
                {
                    while(a<0 || a>10)
                        {
                            cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                            cin >> a;
                        }
                    stud[i].nd.push_back(a);
                    kiekpaz++;
                    vid+=a;
                }
                else
                {
                    while(kiekpaz==0)
                    {
                        cout << "Prasome ivesti bent viena pazymi: ";
                        cin >> a;
                        while(!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                        {
                            cin.clear(); // istrina fail reiksme
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                            cout << "Iveskite skaiciu: ";
                            cin >> a;
                            while(a<0 || a>10)
                            {
                                cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                                cin >> a;
                            }
                        }
                        if (a>0 && a<=10)
                        {
                            stud[i].nd.push_back(a);
                            kiekpaz++;
                            vid+=a;
                        }
                        
                    }
                    if (kiekpaz!=0)
                        break;
                }
            }
            vid=vid/kiekpaz;
            sort(stud[i].nd.begin(), stud[i].nd.end());
            if (kiekpaz%2==0)
            {
                med=(stud[i].nd[kiekpaz/2]+stud[i].nd[kiekpaz/2-1])/2.0;
            }
            else
            {
                med=stud[i].nd[kiekpaz/2];
            }
            cout << "Iveskite egzamino rezultata: ";
            cin>>a;
            while(1>0)
            {
                while(!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                {
                    cin.clear(); // istrina fail reiksme
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                    cout << "Iveskite skaiciu: ";
                    cin >> a;
                }
                if (a<=0 || a>10)
                {
                    cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                    cin>>a;
                }
                else
                {
                    break;
                }
            }
            stud[i].egz = a;
            stud[i].gal=vid*0.4+stud[i].egz*0.6;
            stud[i].galmed=med*0.4+stud[i].egz*0.6;
        }
        i++;
        cout<<"Ar norite ivesti nauja studenta? (T/N)";
        while (1>0)
        {
            cin>>ar;
            if (ar != 't' && ar != 'n' && ar != 'T' && ar != 'N')
                cout<<"Irasykite atitinkamai T arba N: ";
            else break;
        }
        if (ar=='n' || ar=='N')
        break;
    }
    
}

void isvestis(vector <studentas> stud)
{
    cout << "|"<< left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)"<< "|" << left << setw(20) << "Galutinis (Med.)" << endl;
    for (int i=0;i<stud.size();i++)
    {
        cout << "|"<< left << setw(20) << stud[i].vard << "|" << left << setw(20) << stud[i].pavard << "|" << left << setw(20) << fixed << setprecision(2) << stud[i].gal<< "|" << left << setw(20) << fixed << setprecision(2) << stud[i].galmed<< endl;
    }
}

int main()
{
    srand(time(0));
    vector <studentas> stud; 
    ivestis(stud);
    isvestis(stud);
    return 0;
}
