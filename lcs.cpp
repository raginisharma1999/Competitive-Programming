#include<iostream>
#include<cstring>
#include<vector>
#include<climits>

using namespace std;
int toin(string s)
{
	int l=s.length();
	int num=0,ans=1,i=0;
	if(s[0]=='-')
	{
	
	ans=-1;
	i++;
}
	while(i<l)
	{
		num=num*10 + (s[i]-'0');
		i++;
	}
	
	return ans*num;
}
int main(int argc,char *argv[])
{
	int i=0,j,k;
	char *vx=argv[2];
	char *vy=argv[1]; 
	
	int lvx=strlen(vx);
	int lvy=strlen(vy);
	
		string x,y;
	for(i=0;i<lvx;i+=2)
   {

		x[k++]=vx[i];
		
		
	}
	
	int lx=k;
	k=0;
	for(i=0;i<lvy;i+=2)
   {


		y[k++]=vy[i];
		
		
	}	


int ly=k;

	int l[lx+1][ly+1];
	
	for(i=0;i<=lx;i++)
	{
		
		for(j=0;j<=ly;j++)
		{
			if(i==0 || j==0)
			l[i][j]=0;
			
			else if(x[i-1]==y[j-1])
			l[i][j]=l[i-1][j-1]+1;
			
			else 
			l[i][j]=max(l[i-1][j],l[i][j-1]);
			
			
		}
		
		
	}
	
	int fc=l[lx][ly];
	
	char final[fc+1];
	
i=lx;
j=ly;
k=fc-1;
		while(i>0 && j>0)
		{
				
		if(x[i-1]==y[j-1])
		{
			final[k--]=x[i-1];
			i--;
			j--;
		}
		
		else
		if(l[i-1][j]>l[i][j-1])
		{
			i--;
	
		}
		
		else 
		j--;
		
}

for(i=0;i<fc-1;i++)
{
	cout<<final[i]<<" ";
} 

cout<<final[fc-1];	

	

return 0;

}
