#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;
void dfsearch(int V,int matrix[1000][1000],int Vstarting,int fvertex,int check[1000],int high,vector<char>&v1);

int main(int argc,char **argv)
{
 char* ifile = argv[1];
    char* ofile = argv[2];
   
    ifstream fo;
    ofstream fi;
    fo.open (ifile);
    fi.open (ofile);
string c="";
while(!fo.eof())
{
    string b;
    fo>>b;
    c=c+b;
}
int n=c.size();
int V=c[0]-48;

int Vstarting=c[3]-97;

int index=3+(2*V);
index-=1;
int high=Vstarting;
for(int i=3;i<index;i=i+2)
{
    int final=c[i]-97;
    if(final>high)
        high=final;
}
int matrix[1000][1000];
for(int i=0;i<=high;i++)
{
for(int j=0;j<=high;j++)
{
    matrix[i][j]=0;
}
}
vector<char>v1;

 for(int i=index;i<n;i=i+3)
 {
     int x=c[i]-97;
     
     int y=c[i+2]-97;
     
     matrix[y][x]=1;
     matrix[x][y]=1;
     
 }
 int check[10000];
 for(int i=Vstarting;i<=high;i++)
 {
     check[i]=0;
 }
dfsearch(V,matrix,Vstarting,Vstarting,check,high,v1);
int x=v1.size();

int i=0;
while(i<x)

{
    if(i!=x-1)
    fi<<v1[i]<<",";
    else
        fi<<v1[i];
        
        i+=1;
}
}

void dfsearch(int V,int matrix[1000][1000],int Vstarting,int fvertex,int check[1000],int high,vector<char>&v1)

{
char x=Vstarting+97;
v1.push_back(x);
check[Vstarting]=1;
for(int i=fvertex;i<=high;i++)
{
    if(matrix[Vstarting][i]==1&&check[i]==0)
        dfsearch(V,matrix,i,fvertex,check,high,v1);
}
return;
}
