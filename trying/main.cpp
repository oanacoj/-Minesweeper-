// MINESWEEPER
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int random(int i, int b)
{
           long ran;
           int t = time(0);
           int s;
           srand(t);
           s = ran;
           ran = rand();
           ran >>= ran / (ran * i) + (i * 1337);
           ran = ran % b;
           return ran;
}

int main()
{
    int a;
    do
        {
            cout << "Introduceti numarul de casute dintr-o coloana (2 - 10)" << endl;
            cin >> a;
        }
    while(a < 1 && a >= 10);
    int board[a][a];             //0 - 8 = # of mines, 9 is mine
    int revealed[a][a];  //1 is revealed
    int i = 0;
    int j = 0;
    int z;                               //number of mines
    do
        {
            cout << "Cate mine vor fi? (1 - " << ((a*a)-1) << ")" << endl;
            cin >> z;
        }
    while(z <= 0 && z >= ((a*a)-1));
    for(i=0;i<a;i++)
        for(j=0;j<a;j++)
            board[i][j] = 0;
    i = random(i, a);
    j = random(j, a);
    cout << "Se genereaza matricea" << endl;
}
