#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int tree[100000],maxium = 0;

void getTree(int p,int s1)
{
	if(tree[p] == 0)
	{
		maxium = maxium>p? maxium:p;
		tree[p] = s1;
		return;
	}
	if(s1 < tree[p])
		getTree(2*p + 1,s1);
	if(s1 >= tree[p])
		getTree(2*p + 2,s1);
}

int getHeight(int p)
{
	if(tree[p] == 0) return 0;
	else return getHeight(2*p + 1)>getHeight(2*p + 2)? getHeight(2*p + 1)+1:getHeight(2*p + 2)+1;
}

int main()
{
	int n,len;
	cin>>n;
	cin.get();
	stringstream ss;
	while(n>0)
	{
		string s;
		getline(cin,s);
		int right = 0,i = 0,num[100];
		while(right != -1)
		{
			right = s.find(' ');
			if(right == -1)
			{
				ss<<s;
				ss>>num[i++];
				s = "";
			}
			else
			{
				ss<<s.substr(0,right);
				ss>>num[i++];
				s.erase(0,right + 1);
			}
			ss.clear();
		}
		len = i;
		for(int j = 0;j<len;++ j)
		{
			getTree(0,num[j]);                
		}
		if(n == 1) cout<<getHeight(0);
		else cout<<getHeight(0)<<endl;
		for(int j = 0;j<=maxium;++ j)
		{
			if(tree[j] != 0)
			{
				tree[j] = 0;
			}
		}
		--n;
	}
}