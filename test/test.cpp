#include "funkcijos.cpp"

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
            greicioanalize(1000);
            greicioanalize(10000);
            greicioanalize(100000);
            greicioanalize(1000000);
            greicioanalize(10000000);
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