#include <iostream>
#include <fstream>

using namespace std;

bool sprawdz (string s)
{
    int dl=s.size();
    for (int i=0; i<dl/2;i++)
        if (s[i]!=s[dl-i-1]) return false;
    return true;
}
bool sprawdz2 (string s1, string s2)
{
    int dl=s1.size();
    if (dl!=s2.size()) return false;
    else
    {
        int T1[2]={0, 0}, T2[2]={0, 0};
        for (int i=0;i<dl;i++)
        {
            if (s1[i]=='X') T1[0]++;
            else T1[1]++;
            if (s2[i]=='X') T2[0]++;
            else T2[1]++;
        }
        for (int i=0;i<2;i++)
            if (T1[i]!=T2[i]) return false;
    }
    return true;
}
string s, s1, s2;

int main()
{
    fstream plik;
    plik.open("odpowiedz.txt",ios::out);
    cout << "1) Wprowadz lancuch znakow" << endl;
    cin>>s;
    if(sprawdz(s)==true) {cout<<"Jest to palindrom"<<endl; plik<<"Jest to palindrom"<<endl;}
    else {cout<<"To nie jest palindrom!"<<endl; plik <<"To nie jest palindrom!"<<endl;}
    cout<<"2) Wprowadz pierwszy ciag znakow"<<endl;
    cin>>s1;
    cout<<"Wprowadz drugi ciag znakow"<<endl;
    cin>>s2;
    if(sprawdz2(s1, s2)==true) {cout<<"Jest to anagram"; plik<<"Jest to anagram";}
    else {cout<<"Nie jest to anagram"; plik<<"Nie jest to anagram";}
    plik.close();
    return 0;
}
