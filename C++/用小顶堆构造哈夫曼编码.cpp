#include<iostream>
#include<algorithm>

using namespace std;

class MinHeap
{
	int *number,length;
	public:
		MinHeap(int *array = NULL,int n = 0)
		{
			number = array;
			length = n;
			this->getMinHeaps();
		}
		int getLength()
		{
			return length;
		}
		void getMessage(int *array = NULL,int n = 0)
		{
			number = array;
			length = n;
			this->getMinHeaps();
		}
		void getMinHeaps() 
		{
			for(int i = length/2 - 1;i>=0;--i)
				siftup(i);
		}
		void siftup(int pos)
		{
			while(!isLeaf(pos))
			{
				int j = leftChild(pos);
				int rc = rightChild(pos);
				if(rc<length&&number[j]>number[rc])
					j = rc;
				if(number[pos]<number[j]) return;
				swap(pos,j);
				pos = j;
			}
		}
		bool isLeaf(int pos)
		{
			if(pos>=length/2&&pos<length)
				return true;
			return false;
		}
		int leftChild(int pos)
		{
			return 2*pos + 1;
		}
		int rightChild(int pos)
		{
			return 2*pos + 2;
		}
		void swap(int pos,int j)
		{
			int temp;
			temp = number[pos];
			number[pos] = number[j];
			number[j] = temp;
		}
		void display()
		{
			for(int i = 0;i<length;++ i)
				cout<<number[i];
		}
		int getMin()
		{
			return number[0];
		}
		bool removeMin(int & it)
		{
			if(length == 0) return false;
			swap(0,--length);
			if(length!=0) siftup(0);
			it = number[length];
			return true;
		}
		bool insert(const int val)
		{
			if(length>1000) return false;
			int curr = length++;
			number[curr] = val;
			while(curr!=0&&number[curr]<number[(curr-1)/2])
			{
				swap(curr,(curr-1)/2);
				curr = (curr-1)/2;
			}
			return true;
		}
}; 

int value[1000],father[1000],haffTree[10000];
int length,maxium = 0;
MinHeap minHeap;

bool isRoot(int temp,int& index)
{
	for(int i = 0;i<length;++ i)
	{
		if(temp == value[i])
			if(father[i] == -1)
			{	
				index = i;
				return true;
			}
	}
	return false;
}

void getValue()
{
	int temp = 0; 
	while(minHeap.getLength()>1)
	{
		int root_number = 2,index1 = -1,index2 = -1,min1,min2;
		minHeap.removeMin(min1);
		minHeap.removeMin(min2);
		if(isRoot(min1,index1))
			--root_number;
		if(isRoot(min2,index2)&&min1 != min2)
			--root_number;
		temp = temp + root_number;
		value[temp] = min1 + min2;
		father[temp] = -1;
		if(root_number == 0)
		{
			father[index1] = temp;
			father[index2] = temp;
		}
		if(root_number == 1)
		{
			if(index1 == -1)              //index1没被修改，所以是叶子
			{
				value[temp - 1] = min1;
				father[temp-1] = temp;
				father[index2] = temp;
			}
			else
			{
				value[temp - 1] = min2;
				father[temp-1] = temp;
				father[index1] = temp;
			}
		}
		if(root_number == 2)
		{
			value[temp - 1] = min2;
			value[temp - 2] = min1;
			father[temp-1] = temp;
			father[temp - 2] = temp;
		}
		minHeap.insert(value[temp]);
		temp = temp + 1;
	}
}

void getTree(int pos,int point)
{
	int switch1 = 0;
	maxium = maxium>pos? maxium:pos;
	for(int i = 0;i<length;++ i)
	{
		if(father[i] == point)
		{
			point = i;                   //记录下父亲的位置 
			father[i] = -1;
			switch1 = 1;
			break;
		}
	}
	if(switch1 == 0) return;                //当该节点没有儿子时返回上一级； 
	haffTree[pos] = value[point];
	getTree(2*pos + 1,point);                    //构建左子树； 
	getTree(2*pos + 2,point);
}

int main()
{
	int n,number[100];
	cin>>n;
	length = 2*n-1;
	for(int i = 0;i<n;++ i)
		cin>>number[i];
	minHeap.getMessage(number,n);                            //获取number的地址值及数组长度 
	getValue();
	for(int i = 0;i<length;++ i)
		cout<<value[i]<<"   "<<father[i]<<endl;
	getTree(0,-1);
	for(int i = 0;i<=maxium;++ i)
		if(haffTree[i] != 0) cout<<haffTree[i]<<" ";
}