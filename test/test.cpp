#include "struct.h"

int main()
{
    srand(time(0));
    vector <studentas> stud;
    char ar;
    cout << "Ar norite sugeneruoti naujus studento failus? (T/N)" << endl;
    cin >> ar;
    if (ar == 't' || ar == 'T')
    {
        cout << "Kiek studentas tures pazymiu" << endl;
        int kieknd;
        skaicius(kieknd);
        failugeneracija(kieknd);
    }
    else
    {
        cout << "Ar turite jau sugeneruotus studentu failus? (T/N)" << endl;
        cin >> ar;
        if (ar == 't' || ar == 'T')
        {
            cout << "Ar norite naudoti 1 strategija?"<<endl;
            cin >> ar;
            if (ar == 't' || ar == 'T')
            {
                cout << "Ar norite analizuoti su vector konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        greicioanalizevector(i);
                    }
                }
                cout << "Ar norite analizuoti su list konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        greicioanalizelist(i);
                    }
                }
                cout << "Ar norite analizuoti su deque konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        greicioanalizedeque(i);
                    }
                }
            }
            cout << "Ar norite naudoti 2 strategija?" << endl;
            cin >> ar;
            if (ar == 't' || ar == 'T')
            {
                cout << "Ar norite analizuoti su vector konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        greicioanalizevector2(i);
                    }
                }
                cout << "Ar norite analizuoti su list konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        greicioanalizelist2(i);
                    }
                }
                cout << "Ar norite analizuoti su deque konteineriu? (T/N)" << endl;
                cin >> ar;
                if (ar == 't' || ar == 'T')
                {
                    for (int i = 1000; i <= 10000000; i = i * 10)
                    {
                        greicioanalizedeque2(i);
                    }
                }
            }
            
        }
        else
        {
            cout << "Ar norite duomenis ivesti ranka? (T/N)" << endl;
            cin >> ar;
            if (ar == 't' || ar == 'T')
            {
                ivestisranka(stud);
                isvestis(stud);
            }
            else
            {
                try {
                    exists_test("kursiokai.txt");
                    ivestis(stud);
                    isvestis(stud);
                }
                catch (const char* msg) {
                    cout << msg << endl;
                }
            }
        }
    }
    return 0;
}