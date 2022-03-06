#include "funkcijos.h"

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
    }
    else
    {
        ivestis(stud);
    }
    isvestis(stud);
    return 0;
}