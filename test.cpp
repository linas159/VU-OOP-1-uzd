#include <bits/stdc++.h>

using namespace std;

struct studentas
{
    string vard;
    string pavard;
    int n;
    vector <int> nd;
    int egz;
    float gal;
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
            cout<<"Kiek studentas turi pazymiu: ";
            cin>>stud[i].n;
            if (stud[i].n==0)
            {
                cout<<"Ivesta klaidingai"<<endl;
                ar=false;
                break;
            }
            cout<<"Pazymiai: ";
            int a;
            float vid=0;
            for (int j=0;j<stud[i].n;j++)
            {
                cin>>a;
                if (a==0)
                {
                    cout<<"Ivesta klaidingai"<<endl;
                    ar=false;
                    break;
                }
                stud[i].nd.push_back(a);
                vid=vid+a;
            }
            if (a==0)
            {
                break;
            }
            vid=vid/stud[i].n;
            cout<<"Egzamino rezultatas: ";
            cin>>stud[i].egz;
            if (stud[i].egz==0)
            {
                cout<<"Ivesta klaidingai"<<endl;
                ar=false;
                break;
            }
            stud[i].gal=vid*0.4+stud[i].egz*0.6;
    }
    }
    
}

void isvestis(int k, vector <studentas> &stud)
{
    cout << "|"<< left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)" << endl;
    for (int i=0;i<k;i++)
    {
        cout << "|"<< left << setw(20) << stud[i].vard << "|" << left << setw(20) << stud[i].pavard << "|" << left << setw(20) << stud[i].gal<< endl;
    }
}

int main()
{
    int k;
    vector <studentas> stud; 
    bool ar=true;
    ivestis(k,stud,ar);
    if (ar==true)
    isvestis(k,stud);
    return 0;
}
