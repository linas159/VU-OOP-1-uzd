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

void ivestis(int &k, vector <studentas> &stud, bool &ar)
{
    cout<<"Kiek bus mokiniu?"<<endl;
    cin>>k;
    if (k==0)
    {
        cout<<"Ivesta klaidingai"<<endl;
        ar=false;
    }
    else
    {
        for (int i=0;i<k;i++)
        {
            stud.push_back(studentas());
            cout<<"Iveskite varda: ";
            cin>>stud[i].vard;
            if (stud[i].vard[0]<64)
            {
                cout<<"Ivesta klaidingai"<<endl;
                ar=false;
                break;
            }
            cout<<"Iveskite pavarde: ";
            cin>>stud[i].pavard;
            if (stud[i].pavard[0]<64)
            {
                cout<<"Ivesta klaidingai"<<endl;
                ar=false;
                break;
            }
            cout<<"Kiek norite sugeneruoti namu darbu pazymiu? ";
            int kiek;
            cin>>kiek;
            float vid=0,med;
            if (kiek==0)
            {
                cout<<"Ivesta klaidingai"<<endl;
                ar=false;
                break;
            }
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
            if (stud[i].egz==0)
            {
                cout<<"Ivesta klaidingai"<<endl;
                ar=false;
                break;
            }
            stud[i].gal=vid*0.4+stud[i].egz*0.6;
            stud[i].galmed=med*0.4+stud[i].egz*0.6;

    }
    }
    
}

void isvestis(int k, vector <studentas> &stud)
{
    cout << "|"<< left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)"<< "|" << left << setw(20) << "Galutinis (Med.)" << endl;
    for (int i=0;i<k;i++)
    {
        cout << "|"<< left << setw(20) << stud[i].vard << "|" << left << setw(20) << stud[i].pavard << "|" << left << setw(20) << fixed << setprecision(2) << stud[i].gal<< "|" << left << setw(20) << fixed << setprecision(2) << stud[i].galmed<< endl;
    }
}

int main()
{
    srand(time(0));
    int k;
    vector <studentas> stud; 
    bool ar=true;
    ivestis(k,stud,ar);
    if (ar==true)
    isvestis(k,stud);
    return 0;
}
