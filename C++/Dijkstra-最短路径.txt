#include<iostream>

using namespace std;

int *mark,**graph;

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

void getMark(int v)
{
	mark[v] = 1;
}

int minVertex(int *D,int len)
{
	int min = 0;
	for(int i = 1;i<len;++ i)
	{	if(D[i]<D[min] && mark[i] == 0)
			min = i;
	}
	return min;
}

int first(int v,int len)
{
	for(int i = 1;i<len;++ i)
		if(graph[v][i]<24564654)
			return i;
	return -1;
}

int next(int v,int w,int len)
{
	for(int i = w+1;i<len;++ i)
		if(graph[v][i]<24564654)
			return i;
	return -1;
}

void dijkstra(int **graph,int s,int *D,int len)
{
	int i,v,w;
	for(i = 0;i<len;++ i)
		D[i] = 24564654;
	D[s] = 0;
	for(i = 0;i<len;++ i)
	{	v = minVertex(D,len);
		getMark(v);
		for(w = first(v,len);w != -1;w = next(v,w,len))
		{
			if(D[v]+graph[v][w]<D[w])
				D[w] = D[v]+graph[v][w];
		}
	}
}

int main()
{
	int N,C,S,T;
	int Vi,Vj,dis;
	cin>>N>>C>>S>>T;
	int number = N + 1;
	int *path;
	graph = new int*[number];
	for(int i = 0;i<number;++ i)
	{
		graph[i] = new int[number];
	}
	path = new int[number];
	mark = new int[number];
	for(int i = 0;i<number;++ i)
		mark[i] = 0;
	for(int i = 0;i<number;++ i)
		for(int j = 0;j<number;++ j)
			graph[i][j] = 24564654;
	for(int i = 0;i<C;++ i)
	{
		cin>>Vi>>Vj>>dis;
		dis = min(dis,graph[Vi][Vj]);
		graph[Vi][Vj] = dis;
		graph[Vj][Vi] = dis;
	}
	dijkstra(graph,S,path,number);
	cout<<path[T]<<endl;
	delete path;
	delete mark;
	for(int i = 0;i<number;++ i)
		delete graph[i];
}