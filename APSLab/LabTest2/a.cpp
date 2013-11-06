#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;


int main()
{
	int m,k;
	cin>>m>>k;//k-hours
	int d[m+1];//distance (i --> i+1)
	int s[m+1];//fuel supply s[i] denote the i-th
	for(int i=1;i<=m;i++)
		cin>>d[i];
	for(int i=1;i<=m;i++)
		cin>>s[i];
    	int sup_max=-1;
	int fuel=0;
	int ans=0,temp,time,factor;

	/* i-th city ----> (i+1)-th city */
	for(int i=1;i<=m;i++)
	{
	     sup_max=max(sup_max,s[i]);
	     fuel=fuel+s[i];
	     if(fuel>=d[i])
		 {
			   fuel=fuel-d[i];
			   ans+=d[i];
		 }
		 else{
		 		temp=d[i]-fuel;
				time=0;
				factor=0;
				if(temp<sup_max)factor=1;
				else if(temp%sup_max==0)
					factor=temp/sup_max;
				else	
					factor=temp/sup_max+1;
				time=factor*k;
				ans=ans+d[i]+time;
		 		fuel=fuel+factor*sup_max-d[i];
		 	}
	}
	cout<<ans<<endl;
return 0;
}

