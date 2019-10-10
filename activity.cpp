#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

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

int bsearch(int a[],int lb,int ub,int d,int& comp)
{
	if(lb>ub)
	return 0;
		int mid=(ub+lb)/2;
		comp++;
		if(d==a[mid])
		{
		
		return mid+1;
		
	     }
		
		
		if(d<a[mid])
		return bsearch(a,lb,mid-1,d,comp);
		
		
		return bsearch(a,mid+1,ub,d,comp);
		

}


void isort(int a[],int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		int j=i-1;
		int t=a[i];
		
		while(j>=0 && a[j]>t)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}
}


struct activity
{
	int start,end,id;
	
};

bool comp(activity a1,activity a2)
{
	return (a1.end<a2.end);
}

int main (int argc,char* argv[]) {
    char* ifile = argv[1];
    char* ofile = argv[2];
    
    fstream fo;
    ofstream fi;
    fo.open(ifile);
    fi.open(ofile);
    int arr[100],n,count,k,j;
    n = 0;
   count = 0,k=0,j=0;
   
   activity act[100];
   
    while (!fo.eof())
    {
        string s;
        count=0;
        getline (fo,s);
        
        int len = s.length();
        for (int i=0;i<len;i++)
        {
            string num;
        
            while (i<len &&  s[i]!=' ' &&  s[i]!=','  )
            {
                num += s[i++];
            }
            count++;
            if(count==1)
            act[j].id=toInt(num);
            
            else if(count==2)
            act[j].start=toInt(num);
            
            else
            act[j].end=toInt(num);
              
            
        }
        j++;
        
    }
    
    n=j;
                        //isort(arr,n);
                        
                        for(j=0;j<n;j++)
                        {
                        	fi<<act[j].id<<" "<<act[j].start<<" "<<act[j].end<<endl;
						}
						/*
                        sort(act,act+n,comp); 
                        
                        //fi<<act[0].id<<",";
                        int finish=act[0].end;
                        for(j=1;j<n;j++)
                        {
                        	if (act[j].start>=finish);
                        	{
                        		//fi<<act[j].id<<",";
                        		finish=act[j].end;
							}
						}
						
					*/	
                        
       fo.close();
    
             fi.close();

}
