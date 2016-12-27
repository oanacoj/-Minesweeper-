#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("tabelScor.in");
ofstream out("tabelScor.out");


int main()
{
    char scor;
    int n;
    in >> n;
    for(int i=0; i<n; i++)
    {
        in >> scor;
        out<<scor<<"  ";

    }


}

