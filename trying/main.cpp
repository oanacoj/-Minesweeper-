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

void reveal(int x)
{
    if(x == 0)
        cout << "o|";
    else if(x == 9)
        cout << "x|";
    else
        cout << x << "|";
}

void replay()
{
    char a;
    cout << "1) Replay 2) Quit" << endl;
    cin >> a;
    switch(a)
        {
            case '1':
                main();
                break;
            case '2':
                cout << "Quit" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                replay();
                break;
        }
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
