#include<bits/stdc++.h>
using namespace std;

int searchmin(bool*arrvisit,int *totaldist1,int V);

int toInt (string s) 
{
    int numb = 0;
	int l = s.size();
	int j = 0,sign = 1;
	
    if (s[0]=='-')
    {
        sign = -1;
        j++;
    }

    while (   j<l )
    {
        numb = numb*10 + (s[j]-'0');
        j++;
    }
    return numb*sign;
}
void djikstraalgo(int graph[100][100],int V,int E,bool*arrvisit,int *parent,int start,int *totaldist1){

  for(int i=0;i<V;i++)
  {
    totaldist1[i]=INT_MAX;
      arrvisit[i]=false;
  }
totaldist1[0]=0;
  for(int i=0;i<V;i++)
  { int minvertex=searchmin(arrvisit,totaldist1,V);
   arrvisit[minvertex]=true;
   for(int k=0;k<V;k++)
   {
     if(graph[minvertex][k]!=0&&arrvisit[k]==false){
       int currentdist=totaldist1[minvertex]+graph[minvertex][k];
         if(currentdist<totaldist1[k]){
             parent[k]=minvertex;
           totaldist1[k]=currentdist;
         }
   }
  }
  }

}






int main(int argc,char **argv)
{
ifstream fo(argv[1]);
string b;
fo>>b;
int V=b[0]-48;
fo>>b;
int graph[100][100];
for(int i=0;i<V;i++)
{
    for(int j=0;j<V;j++)
    {
        graph[i][j]=0;
    }
}
int e=0;
int start;
while(!fo.eof())
{
    string b;
    fo>>b;
    int size=b.size();
    if(size>1){
    	
    	
    int start=b[0]-97;
    int ending=b[2]-97;
                int i=4;
    int x=b[i]-48;
   i+=1;
    while(b[i]!='\0')
    {
    	
        x=x*10+(b[i]-48);
        i+=1;
    }
   graph[start][ending]=x;
    e+=1;
    }
    else if(b[0]!=0)
	{
    	
    	
    start=b[0]-97;
    }
}
int *dist=new int[V];
ofstream fi(argv[2]);
bool*arrvisit=new bool[V];
    int *parent=new int[V];
  for(int i=0;i<V;i++)
    arrvisit[i]=false;
    int i=0;
    while(i<V)
    
    {
        parent[i]=i;
        i++;
    }
  djikstraalgo(graph,V,e,arrvisit,parent,start,dist);


 i=1;
     while(i<V)
   
    {vector<int>v1;
     int j=i;
     v1.push_back(i);
     j=parent[j];
       while(parent[j]!=j)
       {
           v1.push_back(j);
           j=parent[j];
       }
     v1.push_back(j);
     fi<<char(start+97)<<"-"<<char(i+97)<<":";
        for(int k=v1.size()-1;k>=0;k--)
        {
            if(k!=0)
            fi<<char(v1[k]+97)<<",";
            else if(k==0)
            
                fi<<char(v1[k]+97);
        }
        fi<<":"<<dist[i]<<endl;
i++;
    }
 }

int searchmin(bool*arrvisit,int *totaldist1,int V){
  int minvertex=-1;
  for(int i=0;i<V;i++)
  {
    if(arrvisit[i]==false&&(minvertex==-1||totaldist1[i]<totaldist1[minvertex])){
      minvertex=i;
    }
  }
  return minvertex;
}

