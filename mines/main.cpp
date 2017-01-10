#include <iostream>
#include <time.h>


using namespace std;


int matrix (unsigned int nrBombe,int mapa[10][10])
{
    unsigned int i, j;
    for( i=0; i<10; i++)
    {
        for( j=0; j<10; j++)
            mapa[i][j]=0;
    }
    int bombeAdd=0;
    while(bombeAdd<nrBombe)
    {
        i=random(0, 10);
        j=random(0,10);
        if(mapa[i][j]==0)
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
}

int fcSelect(unsigned int i,unsigned int j, int mapa[10][10],int cover[10][10])
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
    return cover;
}



int selectC(unsigned int i,unsigned int j, int mapa[10][10],int cover[10][10])
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
            selectC(i-1, j, mapa, cover);
        if(j>0 && cover[i][j-1] != 1 && mapa[i][j-1]!= -1)
            selectC(i, j-1, mapa, cover);
        if(i<9 && cover[i+1][j] != 1 && mapa[i+1][j]!=-1)
            selectC(i+1, j, mapa, cover);
        if(j<9 && cover[i][j+1]!=1 && mapa[i][j+1]!=-1)
            selectC(i, j+1, mapa, cover);
    }
    return cover[10][10];
}



void afisare(int mapa[10][10],int cover[10][10])
{
    unsigned int i, j;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
            if(cover[i][j]==1)
        {
            cout<<mapa[i][j];
        }
            else
                cout<<" ";
            cout<<endl;
    }
}



int getScor(int cover[10][10])
{
    unsigned int i, j;
    int scor=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
            if(cover[i][j]==1)
            scor++;
    }
    return scor;
}


int main
{
    int mapa[][];
    mapa=matrix(n, nrBombe, mapa[10][10]);
    int alive=1;
    while(alive)
    {
        afisare(mapa, cover);
        do
        {
            cout<<"i=";
            cin>>i;
            cout<<"j=";
            cin>>j;
        }
        while(i<0 || i>n || j<0 || j>n);
        x=selectC(i, j, mapa, cover)
        if(x==-1)
            alive=0;
    }
    scor=getScor(cover, n);
    cout<<scor;
}
