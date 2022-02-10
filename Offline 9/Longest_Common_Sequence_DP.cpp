#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void mattrix_printer(int**mat,int m,int n)
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<mat[i][j]<<"    ";
        }
        cout<<'\n';
    }
}
int lcs_counter(string x,string y,int **lcs_count,int **lcs_state,int m,int n)
{
    for(int i=0;i<=m;i++)
    {
        lcs_count[i][0]=0;
        lcs_state[i][0]=0;
    }
    for(int i=0;i<=n;i++)
    {
        lcs_count[0][i]=0;
        lcs_state[0][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                lcs_count[i][j]=lcs_count[i-1][j-1]+1;
                lcs_state[i][j]=1;
            }
            else
            {
                if(lcs_count[i-1][j]>lcs_count[i][j-1])
                {
                    lcs_count[i][j]=lcs_count[i-1][j];
                    lcs_state[i][j]=2;
                }
                else
                {
                    lcs_count[i][j]=lcs_count[i][j-1];
                    lcs_state[i][j]=3;
                }
            }
        }
    }
    return lcs_count[m][n];
}
void lcs_builder(string x,string y,int **lcs_count,int **lcs_state,int m,int n,char *res)
{   int lcs_size=lcs_count[m][n];
    while((m!=0)&&(n!=0))
    {
        if(lcs_state[m][n]==1)
        {
           res[lcs_size-1]=x[m-1];
           lcs_size--;
           m--;
           n--;
        }
        else if(lcs_state[m][n]==2)
        {
            m--;
        }
        else
        {
            n--;
        }
    }
}
int main()
{
    string str1,str2;
    cin>>str1;
    cin>>str2;
    int len1,len2,reslen;
    len1=str1.length();
    len2=str2.length();
    int **lcs_count,**lcs_state;
    lcs_count=new int* [len1+1];
    lcs_state= new int* [len1+1];
    for(int i=0;i<=len1;i++)
    {
        lcs_count[i]=new int [len2+1];
        lcs_state[i]=new int [len2+1];
    }
    reslen=lcs_counter(str1,str2,lcs_count,lcs_state,len1,len2);
    char * res = new char[reslen];
   // lcs_builder(str1,str2,lcs_count,lcs_state,len1,len2,res);
    cout<<reslen<<'\n';
    //cout<<res;
    mattrix_printer(lcs_count,len1,len2);
    return 0;
}
