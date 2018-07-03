//ARKA
//PRAVA


#include <bits/stdc++.h>
using namespace std;

int ranking(vector<int>pref[],int t2,int a)
{
	for(int i=0;i<pref[t2].size();i++)
	{
		if(pref[t2][i]==a)
		return i;
	}		
}

//PAUL
int main()
{
queue<int>q;	
int k,in;	
int n;
int t2;
int r1,r2;
int temp;
cout<<"Enter cardinality of men (or women)\n";
cin>>n;
string s;
vector<int>current(n,0);
vector<bool>status(n<<1,false);
map<string,int>rmap;
vector<int>matching(n<<1,0);
vector<string>name(n<<1,"");
cout<<"Enter the names of the men\n";
for(int i=0;i<n;i++)
{
cin>>s;
name[i]=s;
rmap[s]=i;
}
//WU-TANG-CLAN AIN'T
cout<<"Enter the names of the women\n";
for(int i=n;i<n<<1;i++)
{
cin>>s;
name[i]=s;
rmap[s]=i;		
}
vector<int>pref[n<<1];
for(int i=0;i<n<<1;i++)
{
cout<<"Enter preference list for "<<name[i]<<"\n";
k=n; 	
while(k)
{
cin>>s;	
pref[i].push_back(rmap[s]);
k--;	
}		
}
for(int i=0;i<n<<1;i++)
{
cout<<"Preference list for "<<name[i]<<" is:----";
for(int j=0;j<n;j++)
cout<<name[pref[i][j]]<<" ";	
cout<<"\n";	
}
//Main-Function Starts Here FAAAAAAAAAAAAAAAAAAAM
for(int i=n-1;i>=0;i--)
q.push(i);

while(not q.empty())
{
	temp=q.front();
	if(status[temp]==false)
	{
		t2=pref[temp][current[temp]++];
		if(status[t2]==false)
		{
			status[temp]=true;
			status[t2]=true;
			matching[temp]=t2;
			matching[t2]=temp;
			q.pop();
		}
		
	
	else
	{
		r1=ranking(pref,t2,temp);
		r2=ranking(pref,t2,matching[t2]);
		if(r1<r2)
		{
			in=matching[t2];
			status[in]=false;
			matching[t2]=temp;
			matching[temp]=t2;
			q.pop();
			q.push(in);
		}	
	}
	}
	
}	
cout<<"A Man Optimal Stable Matching Solution is\n";
cout<<"Man                   Woman\n"; 
for(int i=0;i<n;i++)
{
cout<<"  "<<name[i]<<"--------------------"<<name[matching[i]]<<"\n";		
}		
return 0;
}
