//
//
//  Created by Kumar P Miskin on 19/04/18.
//  Copyright © 2018 Kumar P Miskin. All rights reserved.
//

#include <iostream>
using namespace std;

struct orb
{
    int p=0;
    int ball=0;
};

void print(orb o[9][6]);
void blowup(orb o[9][6]);
bool check(orb o[9][6]);

void input(orb o[9][6])
{
    int x,y,p=2,a=1;
    while(a==1)
    {
    while(p==2)
    {
        cout<<"Player no: "<<p<<" Enter your coordinates: ";
        cin>>x;
        if(x==-1)
            return;
        cin>>y;
        if(x<9 && y<6)
        {
            if(o[x][y].p==p || o[x][y].p==0)
            {
                o[x][y].ball++;
                o[x][y].p=p;
                p=0;
            }
            else
                cout<<"Illegal move"<<endl;
        }
        else
            cout<<"Illegal move"<<endl;
    }
    p=1;
    blowup(o);
    print(o);
    if(check(o))
      return;
    while(p==1)
    {
        cout<<"Player no: "<<p<<" Enter your coordinates: ";
        cin>>x;
        if(x==-1)
            return;
        cin>>y;
        if(x<9 && y<6)
        {
            if( o[x][y].p==p || o[x][y].p==0)
            {
                o[x][y].ball++;
                o[x][y].p=p;
                p=0;
            }
            else
                cout<<"Illegal move"<<endl;
        }
        else
            cout<<"Illegal move"<<endl;
    }
    blowup(o);
    print(o);
    if(check(o))
        return;
        p=2;
    }
}


void blowup(orb o[9][6])
{
    int k=1,m=1;
    while(k==1)
    {
        k=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<6;j++)
            {
                if (i==0 && j<5 && j>0 && o[i][j].ball==3)
                {
                    o[i+1][j].ball++; o[i+1][j].p=o[i][j].p;
                    o[i][j-1].ball++; o[i][j-1].p=o[i][j].p;
                    o[i][j+1].ball++; o[i][j+1].p=o[i][j].p;
                    o[i][j].ball=0; o[i][j].p=0; k=1;break;
                }
                if (i==8 && j<5 && j>0 && o[i][j].ball==3)
                {
                    o[i-1][j].ball++; o[i-1][j].p=o[i][j].p;
                    o[i][j+1].ball++; o[i][j+1].p=o[i][j].p;
                    o[i][j-1].ball++; o[i][j-1].p=o[i][j].p;
                    o[i][j].ball=0; o[i][j].p=0; k=1;break;
                }
                else if (j==5 && i<8 && i>0 && o[i][j].ball==3)
                {
                    o[i-1][j].ball++; o[i-1][j].p=o[i][j].p;
                    o[i][j-1].ball++; o[i][j-1].p=o[i][j].p;
                    o[i+1][j].ball++; o[i+1][j].p=o[i][j].p;
                    o[i][j].ball=0;  o[i][j].p=0; k=1;break;
                }
                if (j==0 && i<8 && i>0 && o[i][j].ball==3)
                {
                    o[i-1][j].ball++; o[i-1][j].p=o[i][j].p;
                    o[i][j+1].ball++; o[i][j+1].p=o[i][j].p;
                    o[i+1][j].ball++; o[i+1][j].p=o[i][j].p;
                    o[i][j].ball=0; o[i][j].p=0; k=1;break;
                }
                if (i!=0 && i!=8 && j!=5 && j!=0 && o[i][j].ball==4)
                {
                    o[i+1][j].ball++; o[i+1][j].p=o[i][j].p;
                    o[i-1][j].ball++; o[i-1][j].p=o[i][j].p;
                    o[i][j+1].ball++; o[i][j+1].p=o[i][j].p;
                    o[i][j-1].ball++; o[i][j-1].p=o[i][j].p;
                    o[i][j].ball=0; o[i][j].p=0; k=1;break;
                }
                if (i==0 && j==0 && o[i][j].ball==2)
                {
                    o[i+1][j].ball++; o[i+1][j].p=o[i][j].p;
                    o[i][j+1].ball++; o[i][j+1].p=o[i][j].p;
                    o[i][j].ball=0; o[i][j].p=0; k=1;break;
                }
                if (i==0 && j==5 && o[i][j].ball==2)
                {
                    o[i+1][j].ball++; o[i+1][j].p=o[i][j].p;
                    o[i][j-1].ball++; o[i][j-1].p=o[i][j].p;
                    o[i][j].ball=0; o[i][j].p=0; k=1;break;
                }
                if (i==8 && j==5 && o[i][j].ball==2)
                {
                    o[i-1][j].ball++; o[i-1][j].p=o[i][j].p;
                    o[i][j-1].ball++; o[i][j-1].p=o[i][j].p;
                    o[i][j].ball=0; o[i][j].p=0; k=1;break;
                }
                if (i==8 && j==0 && o[i][j].ball==2)
                {
                    o[i-1][j].ball++; o[i-1][j].p=o[i][j].p;
                    o[i][j+1].ball++; o[i][j+1].p=o[i][j].p;
                    o[i][j].ball=0; o[i][j].p=0; k=1;break;
                }
                
            }
            if(k==1)
                break;
        }
        if(m%10==0)
            if(check(o))
                return;
        
    }
}
bool check(orb o[9][6])
{
    int k=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<6;j++)
        {
            if (o[i][j].p==2)
                k=1;
        }
    }
    if(k==0)
    {
        cout<<"Player 1 wins!"<<endl;
        return 1;
    }
    k=2;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<6;j++)
        {
            if (o[i][j].p==1)
                k=1;
        }
    }
    if(k==2)
    {
        cout<<"Player 2 wins!"<<endl;
        return 1;
    }
    return 0;
}

void print(orb o[9][6])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(o[i][j].p==1 || o[i][j].p==0)
                cout<<o[i][j].ball<<" ";
            if(o[i][j].p==2)
                cout<<"-"<<o[i][j].ball<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int x,y,p=1,t=0;
    orb o[9][6];
    while(p==1)
    {
        cout<<"Player no: "<<p<<" Enter your coordinates: ";
        cin>>x;
        if(x==-1)
        {
            t=1;
            break;
        }
        cin>>y;
        if(x<9 && y<6)
        {
            if(o[x][y].p==p || o[x][y].p==0)
            {
                o[x][y].ball++;
                o[x][y].p=p;
                p=0;
            }
            else
                cout<<"Illegal move"<<endl;
        }
        else
            cout<<"Illegal move"<<endl;
    }
    if(t==0)
    {
    print(o);
    input(o);
    }
    cout<<"Game has Ended!";
}
