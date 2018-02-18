#include<iostream>

using namespace std;

template<typename T>
class Node
{
	public:
		Node(T t = 0,Node<T>* p = NULL)
		{
			element = t;
			next = p;
		}
		T element;
		Node<T>* next;
}; 

int main ()
{
	Node<int> *head,*p,*rear;
	for(int i = 1;i<=8;++ i)
	{
		if(i == 1)
		{
			rear = new Node<int>(i);
			head = p = rear;
		}
		else
		{
			rear = new Node<int>(i);
			p->next = rear;
			p = rear;
		}
	}
	Node<int> *temp = head;
	do
	{
		cout<<temp->element<<endl;
		temp = temp->next;
	}while(temp->next!=NULL);
	cout<<temp->element<<endl;
	Node<int>  *tmp = head,*q;
	while(tmp->next != NULL)
	{
		q = tmp->next;
		tmp->next = q->next;
		q->next = head;
		head = q;
	}
	do
	{
		cout<<q->element<<endl;
		q = q->next;
	}while(q->next!=NULL);
	cout<<q->element<<endl;
}