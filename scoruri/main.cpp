#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct nodScor
{
	string nume;
	int scor;
	nodScor* next;
};


void addScor(nodScor*& L, string numeUser, int scorUser)
{
	nodScor * p = new nodScor;
	p->nume = numeUser;
	p->scor = scorUser;
	p->next = L;
	L = p;
}

void citesteListaSimpla(nodScor*&L) {
	ifstream file( "D:/facultate/anul1.1/ip/proiect/-Minesweeper-/scoruri/tabelScor.txt", ios::in );
    string part1;
    L = NULL;
    int num2;
    if( !file )
        cerr << "Cant open " << endl;

    while( file >> part1 >> num2 )
    {
        addScor(L, part1, num2);
    }

    file.close();
}

void afiseazaListaSimpla(nodScor* L)
{
	nodScor * p = L;
	while (p != NULL ) {
		cout << p->nume << "-" << p->scor << ", ";
		p = p->next;
	}
	cout << "\n";
}



int main()
{
	nodScor* primulNod;
	citesteListaSimpla(primulNod);
	afiseazaListaSimpla(primulNod);
	int n;

	cin >> n;
	return 0;
}
/*int main()
{
    ifstream file( "D:/facultate/anul1.1/ip/proiect/-Minesweeper-/scoruri/tabelScor.txt", ios::in );
    string part1, part2;
    int num2;

    if( !file )
        cerr << "Cant open " << endl;

    while( file >> part1 >> part2 >> num2 )
    {
        cout << part1 << " " << part2 << " " << num2 << endl;
    }

    file.close();
    return 0;
}
*/
