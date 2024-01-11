#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

int board[30],count=0;

void queen(int);
int placeQueen(int);
void printSolution(int);

int main()
{
    int i,n;
    cout<<"Queen Implemention\n";
    // cin>>n;
    cout<<"Enter the number of Queen\n";
    cin>>n;
    queen(n);
    cout<<"\nTotal Solution ="<<count;
    getch();

    return 0;
}
int placeQueen(int pos)
{
    int i;
    for(i=1;i<pos;i++)
    {
        if((board[i]==board[pos])||((abs(board[i]-board[pos])==abs(i-pos))))
        return 0;
    }
    return 1;
}
void printSolution(int n)
{
    int i,j;
    count++;
    cout<<"\n\nSolution ["<<count<<"] :\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(board[i]==j)
            cout<<"Q\t";
            else
            cout<<"*\t";
        }
        cout<<endl;
    }
    
}

void queen(int n)
{
    int k=1;
    board[k]=0;
    while(k!=0)
    {
        board[k]=board[k]+1;
        while((board[k]<=n)&&!placeQueen(k))
        board[k]++;
        if(board[k]<=n)
        {
            if(k==n)
            printSolution(n);
            else
            {
                k++;
                board[k]=0;
            }
        }
        else
        k--;
    }
}
