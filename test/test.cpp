#include "funkcijos.cpp"

int main()
{
    srand(time(0));
    vector <studentas> stud;
    cout << "Ar norite duomenis ivesti ranka? (T/N)" << endl;
    char ar;
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
    
    return 0;
}