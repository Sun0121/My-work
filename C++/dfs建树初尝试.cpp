#include<iostream>
#include<string>

using namespace std;

string s;
char tree[10000];
int root = 0,maxium,len;

void dfs(int p)
{
	maxium = maxium>p? maxium:p;
	tree[p] = s[root];                        //��������Сд��ĸ�ͽ���㣬ֱ�����ʵ�����ĵ��д��ĸ�� 
	if(s[root]<91)
	{
		return;
	}
	++ root;
	dfs(2*p+1);
	++ root;
	dfs(2*p+2);
}

int main()
{
	cin>>s;
	len = s.length();
	dfs(0);
	for(int j = 0;j<=maxium;++ j)
	{
		if(tree[j] != '\0')
		{
			cout<<tree[j];
		}
	}
} 