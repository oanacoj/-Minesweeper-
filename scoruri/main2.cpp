#include <iostream>
#include <string>


using namespace std;
struct nodScor
{
	string nume;
	int scor;
	nodScor* next;
};


/*void citesteListaSimpla(nodScor*&L) {
	unsigned int nrUseri;
	cout << "Dati numarul de useri: ";
	cin >> nrUseri;
	L = NULL;
	nodScor *p;
	string numeUser;
	int scorUser;
	for (unsigned int i = 1; i <= nrUseri; i++)
	{
		cout << "Nume user:";
		cin >> numeUser;
		cout << "Scor:";
 		cin >> scorUser;
		p = new nodScor;
		p->nume = numeUser;
		p->scor = scorUser;
		p->next = L;
		L = p;
	}
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
*/
