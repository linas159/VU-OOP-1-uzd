#include <bits/stdc++.h>

using namespace std;

struct studentas
{
    string vard;
    string pavard;
    int kieknd=0;
    int* nd = new int[2];
    int egz;
    float gal;
    float galmed;
};

void resize(studentas* stud, int &size) {
    studentas* resize_arr = new studentas[size + 1];
    for(int i = 0; i < size; i++)
        resize_arr[i] = stud[i];
    size++;
    stud = resize_arr;
    delete[] resize_arr;
}

void resize_nd(int* stud, int &size) {
    int* resize_arr = new int[size + 1];
    for(int i = 0; i < size; i++)
        resize_arr[i] = stud[i];
    size++;
    stud = resize_arr;
    delete[] resize_arr;
}

void ivestis(studentas* stud, int &i)
{
    i=0;
    while (1>0)
    {
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
            cin>>stud[i].kieknd;
            while(!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
            {
                cin.clear(); // istrina fail reiksme
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                cout << "Iveskite skaiciu: ";
                cin >> stud[i].kieknd;
            }
            while (1>0)
            {
                if(stud[i].kieknd==0)
                    cout<<"Isveskite skaiciu didesni uz 0: ";
                else break;
                cin>>stud[i].kieknd;
            }
            int* resize_arr = new int[stud[i].kieknd];
            stud[i].nd = resize_arr;
            float vid=0,med;
            for (int j=0;j<stud[i].kieknd;j++)
            {
                stud[i].nd[j] = rand()%10+1;
                cout<<stud[i].nd[j]<<" ";
                vid=vid+stud[i].nd[j];
            }
            cout<<endl;
            sort(stud[i].nd, stud[i].nd+stud[i].kieknd);
            if (stud[i].kieknd%2==0)
            {
                med=(stud[i].nd[stud[i].kieknd/2]+stud[i].nd[stud[i].kieknd/2-1])/2.0;
            }
            else
            {
                med=stud[i].nd[stud[i].kieknd/2];
            }
            vid=vid/stud[i].kieknd;
            cout<<"Egzamino rezultatas: ";
            stud[i].egz=rand()%10+1;
            cout<<stud[i].egz<<endl;
            stud[i].gal=vid*0.4+stud[i].egz*0.6;
            stud[i].galmed=med*0.4+stud[i].egz*0.6;
        }
        else
        {
            cout<<"Iveskite studento pazymius, norint baigti iveskite 0: ";
            int a;
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
                    stud[i].nd[stud[i].kieknd]=a;
                    resize_nd(stud[i].nd, stud[i].kieknd);
                    vid+=a;
                }
                else
                {
                    while(stud[i].kieknd==0)
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
                            stud[i].nd[stud[i].kieknd]=a;
                            resize_nd(stud[i].nd, stud[i].kieknd);
                            vid+=a;
                        }
                        
                    }
                    if (stud[i].kieknd!=0)
                        break;
                }
            }
            vid=vid/stud[i].kieknd;
            sort(stud[i].nd, stud[i].nd+stud[i].kieknd);
            if (stud[i].kieknd%2==0)
            {
                med=(stud[i].nd[stud[i].kieknd/2]+stud[i].nd[stud[i].kieknd/2-1])/2.0;
            }
            else
            {
                med=stud[i].nd[stud[i].kieknd/2];
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
        
        cout<<"Ar norite ivesti nauja studenta? (T/N)";
        while (1>0)
        {
            cin>>ar;
            if (ar != 't' && ar != 'n' && ar != 'T' && ar != 'N')
                cout<<"Irasykite atitinkamai T arba N: ";
            else break;
        }
        resize(stud,i);
        if (ar=='n' || ar=='N')
        break;
        
        
    }
    
}

void isvestis(studentas* stud, int i)
{
    cout << "|"<< left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)"<< "|" << left << setw(20) << "Galutinis (Med.)" << endl;
    for (int j=0;j<i;j++)
    {
        cout << "|"<< left << setw(20) << stud[j].vard << "|" << left << setw(20) << stud[j].pavard << "|" << left << setw(20) << fixed << setprecision(2) << stud[j].gal<< "|" << left << setw(20) << fixed << setprecision(2) << stud[j].galmed<< endl;
    }
}

int main()
{
    srand(time(0));
    studentas *stud = new studentas[2];
    int i=0;
    ivestis(stud, i);
    isvestis(stud, i);
    return 0;
}
