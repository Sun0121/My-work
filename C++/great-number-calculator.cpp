#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//��������������������� 

int PointMove,Len;				//����ȫ�ֱ�����¼С������Ϣ�����ݳ��� 

struct Num
{	
	int n;
	Num *next;
}; 

void GetNum();
void Simplify(string &,string &);
void BuildList(string &,Num *&);
void Operate(Num *&,Num *&,char,string ,string);
void OutPut(int a[],int );
void Delete(Num *&);
void Deal(string &,string &,char &);

int main ()
{	
	while(1)
	{	
		cout<<"�����������������Ӽ���"<<endl; 
		GetNum();
	}
	return 0;
}
void GetNum()
{	
	string num1,num2;
	Num *number1,*number2;
	char c; 
	cout<<"�����������Ϣ(������ȷ����)\n��һ������";
	cin>>num1;
	cout<<"������������:";
	cin>>c;
	cout<<"�ڶ�������";
	cin>>num2;
	Deal(num1,num2,c);
	Simplify(num1,num2);
	BuildList(num1,number1);
	BuildList(num2,number2);
	Operate(number1,number2,c,num1,num2);
	
		 
}
void Simplify(string &str1,string &str2)    //�ô˺������������Ϣ��������ȥ���ţ�ȷ��С��λ����0ʹ����ʽ��ͬ 
{	
	str1.erase(remove(str1.begin(), str1.end(), ','), str1.end());
	str2.erase(remove(str2.begin(), str2.end(), ','), str2.end());      //��һ�����Ƴ����� 
	
	int point1,point2;
	if (string::npos == str1.find('.')) point1 = 0;     //string::npos�ж��ַ����еġ�.�������� 
		else {
			point1 = str1.length() - str1.find('.') - 1;
			str1 = str1.replace(str1.find('.'), 1, "");     //�Ƴ��ַ����е�С���� 
		}

	if (string::npos == str2.find('.')) point2 = 0;
		else {
			point2 = str2.length() - str2.find('.') - 1;
			str2 = str2.replace(str2.find('.'), 1, "");
		}
		if (point1 > point2) {
			str2.append(point1 - point2, '0');
			PointMove = point1;
		}
		if (point1 < point2) {
			str1.append(point2 - point1, '0');            
			PointMove = point2;
		}
		if (point1 == point2) {                          //ȷ��С����λ��������С��λ��������ͬ 
			PointMove = point1;
		}
	int Len1 = str1.length(),Len2 = str2.length();
	if (Len1>Len2)
	{	Len = Len1;
		string s;
		s.assign(Len-Len2,'0');
		str2.insert(0,s);
	}
	if (Len1<Len2)
	{	Len = Len2;
		string s;
		s.assign(Len-Len1,'0');
		str1.insert(0,s);
	}
	if (Len1 == Len2) Len = Len1;						//ȷ�����ݳ�����ͬ 
}

void Deal(string &s1,string &s2,char &f)                //������ķ��Ž��д��� ��ʹ�Ӽ������븺��֮����ͳһ��ʽ 
{	
	if(s1[0] != '-'&&s2[0] == '-'&&f == '-')
	{	
		s2.erase(0,1);
		f = '+';
	}
	if(s1[0] != '-'&&s2[0] == '-'&&f == '+')
	{	s2.erase(0,1);
		f = '-';
	}
	if(s2[0] != '-'&&s1[0] == '-'&&f == '-')
	{	
		s1.erase(0,1);
		f = '+';
		cout<<"-";
	}
	if(s2[0] != '-'&&s1[0] == '-'&&f == '+')
	{	
		s1.erase(0,1);
		string s3;
		s3 = s2;
		s2 = s1;
		s1 = s3;
		f = '-';
	}
	if(s2[0] == '-'&&s1[0] == '-'&&f == '+')
	{	
		s1.erase(0,1);
		s2.erase(0,1);
		cout<<"-";
	}
	if(s2[0] == '-'&&s1[0] == '-'&&f == '-')
	{	
		s1.erase(0,1);
		s2.erase(0,1);
		string s3;
		s3 = s2;
		s2 = s1;
		s1 = s3;
	}
}
void BuildList(string &str,Num *&number)
{	
	int L = Len-1;                                    //�����ݷ����������� 
	Num *s,*p;
	number = NULL;
	s = new Num;
	s->n = str[L] - 48;
	number = s,p = s;
	while(L-1>=0)
	{	
		s = new Num;
		s->n = str[L-1] - 48;
		p->next = s;
		p = s;
		L--;
	}
	s = new Num;
	s->n = 0;
	p->next = s;
	p = s;
	p->next = NULL;
}

void Operate(Num *&number1,Num *&number2,char c,string str1,string str2)
{	Num *&head1 = number1,*&head2 = number2;
	int *a = new int[10000],i = 0;
	if(c == '+')
	{	
		while(number1)
		{	
			a[i] = number1->n + number2->n;
			number1 = number1->next;
			number2 = number2->next;
			if (a[i]>=10)
			{	a[i] = a[i] - 10;
				number1->n = number1->n + 1;
			}
			++ i;
		}
		OutPut(a,i-1);
		delete []a;
	}
	if (c == '-')
	{	if(str1>=str2)
		{
				while(number1)
			{	
				a[i] = number1->n - number2->n;
				number1 = number1->next;
				number2 = number2->next;
				if(i == Len-1)                            //�����㵽���һλʱ�������ݵ����λʱ�������ٿ��ǽ�λ 
				{	
					++ i;
					continue;                        
				}
				else if(a[i]<0)
					{ 
						a[i] = a[i] + 10;
						number1->n = number1->n - 1;
					}
				++ i;
			}
			OutPut(a,i-1);
			delete []a;
			
		}
		else 
		{	
				while(number1)
			{	
				a[i] = number2->n - number1->n;
				number1 = number1->next;
				number2 = number2->next;
				if(i == Len-1) 
				{	
					++ i;
					continue;
				}
				else if(a[i]<0)
					{ 
						a[i] = a[i] + 10;
						number2->n = number2->n - 1;
					}
				++ i;
			}
			cout<<"-";
			OutPut(a,i-1);
			delete []a;
		}
		
	}
	Delete(head1);
	Delete(head2);
	
}
void OutPut(int a[],int i)
{	
	while(a[i] == 0&&i>PointMove)                               //�Ƴ�����ǰ������0���ڸ�λ֮ǰ�Ķ����0�� 
	{	
		--i;
	}
	int k = i - PointMove,m = 0;
	while(a[m] == 0&&m<PointMove)                  //�Ƴ���������0��ͬ���ڸ�λ֮���0�� 
	{	
		++m;
	}
	while(i>=m)
	{	
		cout<<a[i];
		if(i == PointMove&&PointMove != 0)
		{	
			int t = i-1,sum = 0;
			while(t>=0)
			{	
				sum += a[t];
				--t;
			}
			if(sum == 0) break;
			else cout<<".";
		}
		if(k>=2&&k%3 == 0)
			cout<<",";
		--k;--i;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
}

void Delete(Num *&node)
{	
	Num *p;
	while(node)
	{	
		p = node;
		node = node->next;
		delete p;
	}
	delete node;
}