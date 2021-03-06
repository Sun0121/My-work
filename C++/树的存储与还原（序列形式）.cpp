#include<iostream>
#include<string>

using namespace std;

struct Tree
{
	char value;
	int parent;
};

Tree tree[1000];
string str;
int fence = 0,length,temp_father,pos = 0;

int getFather()
{
	int i = 0,temp,temp_pos;
	temp_pos = pos;
	while(str[fence+1] == ')'&&fence<length-2)
	{
		++ i;
		++ fence;
	}
	while(i>0)
	{
		temp = tree[temp_pos].parent;
		temp_pos = temp;
		-- i;
	}
	return temp;
}

void getTree()
{                     //pos随着指到tree当前位置
	tree[pos].value = str[fence++];
	tree[pos].parent = -1;
	temp_father = pos++;
	while(fence<length-1)
	{
		if(str[fence+1] != ')')
		{
			tree[pos].value = str[fence];
			tree[pos].parent = temp_father;
			temp_father = pos;
		}
		else
		{
			tree[pos].value = str[fence];
			tree[pos].parent = temp_father;
			temp_father = getFather();
		}
		++ fence;
		++ pos;
	}
}

int getNumber(int i)
{
	int number = 1,temp;
	int father1 = tree[i].parent,father2 = tree[i+1].parent;
	while(father1 != father2)
	{
		father1 = tree[father1].parent;
		++ number;
	}
	return number;
}

void printTree()
{
	int i = 0,number,temp;
	while(i<pos-1)
	{
		cout<<tree[i].value;
		if(tree[i+1].parent != i)
		{
			number = getNumber(i);
			while(number>0)
			{
				cout<<')';
				number--;
			}
		}
		++ i;
	}
	cout<<tree[i].value;
	number = 0;
	temp = tree[i].parent;
	while(temp!=-1)
	{
		temp = tree[temp].parent;
		++ number;
	}
	while(number>=0)
	{
		cout<<')';
		-- number;
	}
	cout<<endl;
}

int main()
{
	cin>>str;
	length = str.size();
	getTree();
	for(int i = 0;i<pos;++ i)
	{
		cout<<tree[i].value<<" "<<tree[i].parent<<endl;
	}
	printTree();
}