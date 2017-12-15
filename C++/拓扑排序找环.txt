#include<iostream>
#include<queue>

using namespace std;

bool isCircle(int** graph,int* indegrees,int number)
{
	queue<int> M;
	for(int i = 1;i<number;++ i)
	{
		if(indegrees[i] == 0)
			M.push(i);
	}
	while(!M.empty())
	{
		int n = M.front();
		for(int i = 1;i<number;++ i)
			if(graph[n][i] == 1)                                  
			{
				indegrees[i]--;                    
				if(indegrees[i] == 0)
					M.push(i);
			}
		M.pop();
	}
	for(int i = 1;i<number;++ i)
	{
		if(indegrees[i] != 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	while(n>0)
	{
 		int** graph;
		int* indegrees;
		int number_vertices,number_edges,p,q;
		cin>>number_vertices>>number_edges;
		graph = new int*[number_vertices+1];
		for(int i = 0;i<number_vertices+1;++ i)
			graph[i] = new int[number_vertices+1];
		for(int i = 0;i<number_vertices+1;++ i)
			for(int k = 0;k<number_vertices+1;++ k)
				graph[i][k] = 0;
		indegrees = new int[number_vertices+1];
		for(int i = 0;i<number_vertices+1;++ i)
			indegrees[i] = 0;
		for(int i = 0;i<number_edges;++ i)
		{
			cin>>p>>q;
			graph[p][q] = 1;
			indegrees[q]++;
		}
		if(isCircle(graph,indegrees,number_vertices+1)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		delete[] indegrees;
		for(int i = 0;i<number_vertices+1;++ i)
			delete[] graph[i];
		--n;
	}
}