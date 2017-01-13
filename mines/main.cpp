#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

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
        }
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
    else
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
    return cover[10][10];
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


void afisare(int mapa[10][10],int cover[10][10], int n)
{
    unsigned int i, j;
    for(i=0; i<n; i++)
    {


        if(i==0){
            cout<<"_|";
            for(j=0;j<n;j++)
                cout<<j<<"|";
            cout<<endl<<endl;;
        }
        cout<<i<< " "   ;
        for(j=0; j<n; j++)
            if(cover[i][j]==1)
            {
                    if(mapa[i][j]==-1)
                        cout<<"*|";
                    else{
                        cout<<mapa[i][j]<<"|";
                    }
            }
            else{
                cout<<"?|";
            }
        cout<<endl;
    }
    cout<<endl<<"socurul tau este: "<<getScor(cover, n)<<endl;
}






int main ()
{
    int cover[10][10], mapa[10][10];
    unsigned int n, nrBombe;
    cout << "dati nr bombe:";
    cin >> nrBombe;
    cout<<"Dati n";
    cin>>n;
    matrix(nrBombe, mapa, n);
    int alive=1;
    int i, j, x, scor;
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
        while(i<0 || i>n || j<0 || j>n);
        x=selectC(i, j, mapa, cover, n);
        if(x==-1)
            alive=0;
        scor=getScor(cover, n);
        if(scor>=n*n-nrBombe){
            alive = 2;
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cover[i][j] = 1;
    scor=getScor(cover, n);
    afisare(mapa,cover, n);
    if(alive==0)
        cout<<"Ai murit";
    else
        cout<<"Ai castigat";
}
