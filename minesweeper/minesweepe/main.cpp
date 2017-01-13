#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
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
	ifstream file( "scoruri.txt", ios::in );
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
		cout << p->nume << ": " << p->scor << endl;
		p = p->next;
	}
	cout << "\n";
}

int scriereScor (nodScor*&L)
{
    ofstream myfile;
    myfile.open ("scoruri.txt");
    nodScor * p = L;
    if( !myfile )
        cerr << "Cant open " << endl;
    while( p != NULL )
    {
        myfile<< p->nume <<endl;
        myfile<< p->scor<<endl;
        p=p->next;
    }
    myfile.close();
    return 0;
}


int matrix (unsigned int nrBombe,int mapa[10][10], int n)
{
    srand(time(NULL));
    unsigned int i, j;
    for( i=0; i<n; i++)
    {
        for( j=0; j<n; j++)
            mapa[i][j]=0;
    }
    unsigned int bombeAdd=0;
    while(bombeAdd<nrBombe)
    {
        i=rand() % n;
        j=rand() % n;
        if(mapa[i][j] != -1)
        {
            mapa[i][j]=-1;
            bombeAdd++;

            if(i>0)
            {
                if(mapa[i-1][j]>=0)
                    mapa[i-1][j]++;
            }
            if(j>0)
            {
                if(mapa[i][j-1]>=0)
                    mapa[i][j-1]++;
            }
            if(i<9)
            {
                if(mapa[i+1][j]>=0)
                    mapa[i+1][j]++;
            }
            if(j<9)
            {
                if(mapa[i][j+1]>=0)
                    mapa[i][j+1]++;
            }
            if(i>0 && j>0)
                {
                    if(mapa[i-1][j-1]>=0)
                        mapa[i-1][j-1]++;
                }
            if(i>0 && j<9)
                {
                    if(mapa[i-1][j+1]>=0)
                        mapa[i-1][j+1]++;
                }
            if(i<9 && j>0)
            {
                if(mapa[i+1][j-1]>=0)
                    mapa[i+1][j-1]++;
            }
            if(i<9 && j<9)
            {
                if(mapa[i+1][j+1]>=0)
                    mapa[i+1][j+1]++;
            }
        }
    }
    return mapa[10][10];
}

int fcSelect(unsigned int i,unsigned int j, int mapa[10][10],int cover[10][10], int n)
{
    if(mapa[i][j]== -1)
        return -1;
    if(i>0)
    {
        if(mapa[i-1][j]!= -1)
            cover[i-1][j]=1;
    }
    if(j>0)
    {
        if(mapa[i][j-1] != -1)
            cover[i][j-1] = 1;
    }
    if(i<9)
    {
        if(mapa[i+1][j] != -1)
            cover[i+1][j]=1;
    }
    if(j<9)
    {
        if(mapa[i][j+1] != -1)
            cover[i][j+1]=1;
    }
    return cover[10][10];
}



int selectC(unsigned int i,unsigned int j, int mapa[10][10],int cover[10][10], int n)
{
    if(mapa[i][j]==-1)
        return -1;
    if(mapa[i][j] > 0)
    {
        cover[i][j]=1;
        return 1;
    }
    if(mapa[i][j] == 0)
    {
        cover[i][j]=1;
        if(i>0 && cover[i-1][j] != 1 && mapa[i-1][j]!=-1)
            selectC(i-1, j, mapa, cover, n);
        if(j>0 && cover[i][j-1] != 1 && mapa[i][j-1]!= -1)
            selectC(i, j-1, mapa, cover, n);
        if(i<9 && cover[i+1][j] != 1 && mapa[i+1][j]!=-1)
            selectC(i+1, j, mapa, cover, n);
        if(j<9 && cover[i][j+1]!=1 && mapa[i][j+1]!=-1)
            selectC(i, j+1, mapa, cover, n);
    }
    return 1;
}


int getScor(int cover[10][10],int n)
{
    unsigned int i, j;
    int scor=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            if(cover[i][j]==1)
                scor++;
    }
    return scor;
}


unsigned char GetColorCode ( unsigned char colorBackground,
                             unsigned char colorForeground )
{
    //0 negru, 4 rosu inchis, 8 gri, 9 albastru, 12 rosu, 14 galben, 15 alb
      //return most signifigant bit of colorBackground and
      //least signifigant bit of colorForground as one byte
      return (colorBackground << 4) + colorForeground;
}

void afisare(int mapa[10][10],int cover[10][10], int n)
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    unsigned int i, j;
    for(i=0; i<n; i++)
    {

        SetConsoleTextAttribute(hConsole, GetColorCode(15, 0));
        if(i==0){
            cout<<"_|";
            for(j=0;j<n;j++)
                cout<<j<<"|";
            cout<<endl;
        }
        cout<<i<< " "   ;
        for(j=0; j<n; j++)
            if(cover[i][j]==1)
            {
                    if(mapa[i][j]==-1){
                        SetConsoleTextAttribute(hConsole, GetColorCode(12, 14));
                        cout<<"*";
                        SetConsoleTextAttribute(hConsole, GetColorCode(8, 15));
                        cout<<"|";
                    }
                    else{
                        if(mapa[i][j]==0){
                            SetConsoleTextAttribute(hConsole, GetColorCode(8, 0));
                            cout<<" ";
                            SetConsoleTextAttribute(hConsole, GetColorCode(8, 15));
                            cout<<"|";
                        }
                        else{
                            if(mapa[i][j]==1){
                                SetConsoleTextAttribute(hConsole, GetColorCode(8, 9));
                            }
                            if(mapa[i][j]==2){
                                SetConsoleTextAttribute(hConsole, GetColorCode(8, 14));
                            }
                            if(mapa[i][j]>2){
                                SetConsoleTextAttribute(hConsole, GetColorCode(8, 4));
                            }
                            cout<<mapa[i][j];
                            SetConsoleTextAttribute(hConsole, GetColorCode(8, 15));
                            cout<<"|";
                        }

                    }
            }
            else{
                SetConsoleTextAttribute(hConsole, GetColorCode(8, 15));
                cout<<"?|";
            }
        SetConsoleTextAttribute(hConsole, GetColorCode(0, 15));
        cout<<endl;
    }

}



int loopJoc(){
    int cover[10][10]={0}, mapa[10][10];
    unsigned int n, nrBombe;
    cout << "Dati nr bombe  : ";
    cin >> nrBombe;
    do{
        cout<<"Dati n: ";
        cin>>n;
    }while(n*n<=nrBombe);

    matrix(nrBombe, mapa, n);
    int alive=1;
    int i, j, x, scor=0;
    while(alive==1)
    {
        afisare(mapa, cover, n);
        do
        {
            cout<<"i=";
            cin>>i;
            cout<<"j=";
            cin>>j;
        }
        while(i<0 || i>=n || j<0 || j>=n);

        x=selectC(i, j, mapa, cover, n);
        if(x==-1){
            alive=0;
        }
        else{
            scor=getScor(cover, n );
            if(alive==1 && scor>=n*n-nrBombe){
                alive = 2;
                scor=getScor(cover, n);
            }
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cover[i][j] = 1;
    afisare(mapa,cover, n);
    if(alive==0)
        cout<<"Ai murit";
    if(alive==2)
        cout<<"Ai castigat";


    cout<<endl<<"socurul tau este: "<<scor<<endl;
    return scor;
}


int main ()
{
    nodScor* primulNod;
	citesteListaSimpla(primulNod);

    int scor = 0;
    while(1){
        int optineSelectata = 0;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, GetColorCode(0, 15));
        do{
            cout<<"1. Joc nou"<<endl;
            cout<<"2. Top scoruri"<<endl;
            cout<<"0. Exit"<<endl;
            cin>>optineSelectata;
        } while(optineSelectata<0 || optineSelectata > 2);

        system("cls");

        if(optineSelectata == 1){
            scor = loopJoc();
            cout<<endl<<"Dati numele: ";
            string nume;
            cin>>nume;
            addScor(primulNod, nume, scor);
            scriereScor(primulNod);
            afiseazaListaSimpla(primulNod);
        }
        if (optineSelectata==2){
            citesteListaSimpla(primulNod);
            afiseazaListaSimpla(primulNod);
        }
        if(optineSelectata == 0){
            return 0;
        }
        optineSelectata = 0;

    }

}
