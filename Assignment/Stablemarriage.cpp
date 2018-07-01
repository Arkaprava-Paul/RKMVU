#include <bits/stdc++.h>
using namespace std;

int ranking(map<char,vector<char>>pref,char a,char t)
{
	for(int i=0;i<pref[a].size();i++)
	{
		if(pref[a][i]==t)
		return i;
	}		
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
	cout<<"Enter number of elements\n";
	int n,r1,r2;
	queue<char>q;
	char temp;
	char t2;
	int t1;
	char in;
	cin>>n;
	map<char,char>matching;
	map<char,int>current;
	map<char,bool>status;
	map<char,vector<char>>preference;
	vector<char>m(n,0);
	vector<char>w(n,0);
cout<<"Enter the men characters\n";
for(int i=0;i<n;i++)
{
cin>>m[i];
q.push(m[i]);
status[m[i]]=false;
current[m[i]]=0;		
}
cout<<"Enter the women characters\n";
for(int i=0;i<n;i++)
{
cin>>w[i];
status[w[i]]=false;
current[w[i]]=0;		
}
for(int i=0;i<n;i++)
{
cout<<"Enter preference list for "<<m[i]<<"\n";	
for(int j=0;j<n;j++)
{
	cin>>temp;
	preference[m[i]].push_back(temp);
}	
}	
for(int i=0;i<n;i++)
{
cout<<"Enter preference list for "<<w[i]<<"\n";	
for(int j=0;j<n;j++)
{
	cin>>temp;
	preference[w[i]].push_back(temp);
}	
}	
for(int i=0;i<n;i++)
{
cout<<"Preference list of "<<m[i]<<" is------------->";	
for(int j=0;j<preference[m[i]].size();j++)
cout<<preference[m[i]][j]<<" ";	
cout<<"\n";		
}




while(not q.empty())
{
temp=q.front();
if(status[temp]==false)
{
	t2=preference[temp][current[temp]++];
	if(status[t2]==false)
	{
		status[temp]=true;
		status[t2]=true;
		matching[t2]=temp;
		q.pop();
	}
	else
	{
		r1=ranking(preference,t2,matching[t2]);
		r2=ranking(preference,t2,temp);
		if(r2<r1)
		{
		in=matching[t2];
		status[in]=false;
		matching[t2]=temp;
		status[temp]=true;
		q.pop();
		q.push(in);
		}
	}
}
}
cout<<"A Stable Matching is\n";	
for(int i=0;i<n;i++)
cout<<matching[w[i]]<<" "<<w[i]<<"\n"; 
	return 0;
}
