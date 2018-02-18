#include<iostream>
#include<fstream> 
#include<string>
#include<algorithm>
#include<iomanip>         
#include<sstream>

using namespace std;

static int project = 1;

class Studentdates                                    //��һ���࣬����ѧ������ 
{
	protected:
		string name,id;
		double Chinese,math,English,total;
		int rank;
	public:
		static int count;
		Studentdates(string a = "0",string b = "0",double c = 0,double d = 0,double e = 0);
		//virtual ~Studentdates () { ; }
		void displayrank(int n)
		{
			rank = n;
		} 
};
int Studentdates::count = 0;
Studentdates::Studentdates(string a,string b,double c,double d,double e)
{
	id = a;name = b;Chinese = c;math = d;English = e;
	rank = -1;
	total =c+d+e;
}

class Student:public Studentdates                             
{
	public:
		Student(string a = "0",string b = "0",double c = 0,double d = 0,double e = 0):Studentdates(a,b,c,d,e) {}
		Student & operator = (Student &A);
		friend bool cmp1(Student , Student);
		friend bool cmp2(Student , Student);
		friend bool cmp3(Student , Student);
		friend bool cmp4(Student , Student);
		friend bool cmp5(Student , Student);
		friend bool cmp6(Student , Student);
		friend void fileOutput(Student A[],string filename);         //��ȡ�ļ� 
		friend void fileInput(Student A[],string filename);          //�����ļ� 
		friend void seekstudent();                                  //����ѧ�� 
		friend void deletedate();                                   //ɾ����¼ 
		friend void Changedate();                                  //�޸ļ�¼ 
		friend void Combinefiles();                                //�ϲ��ļ� 
		friend istream & operator>>(istream &Input ,Student &);
		friend ostream & operator<<(ostream &Output ,Student &);
};
bool cmp1(Student a,Student b)                            //���Բ�ͬ���������� 
{
	return a.total>b.total;
}
bool cmp2(Student a,Student b)
{
	return a.Chinese>b.Chinese;
}
bool cmp3(Student a,Student b)
{
	return a.math>b.math;
}
bool cmp4(Student a,Student b)
{
	return a.English>b.English;
}
bool cmp5(Student a,Student b)
{
	return a.id>b.id;
}
bool cmp6(Student a,Student b)
{
	return a.name>b.name;
}
Student & Student::operator = (Student &A)
{
	id = A.id;
	name = A.name;
	Chinese = A.Chinese;
	math = A.math;
	English = A.English;
	total = A.total;
	rank = A.rank;
	return *this;
}
istream & operator>>(istream &Input ,Student &A)
{
	Input>>A.id>>A.name>>A.Chinese>>A.math>>A.English;
	A.total = A.Chinese+A.English+A.math;
	return Input;
}
ostream &operator<<(ostream &Output ,Student &A)
{
	Output<<setw(15)<<A.id<<setw(15)<<A.name<<setw(10)<<A.Chinese<<setw(10)<<
		  A.math<<setw(10)<<A.English<<setw(10)<<A.total<<setw(10)<<A.rank<<endl;
	return Output;
}
void fileOutput(Student A[],string filename)
{
	char s[100];
	int i = 0;
	ifstream instuf;
	instuf.open(filename.c_str(),ios::in);
	if(!instuf)
	{
		cerr<<"�ļ������ڻ��ļ��򿪳���"<<endl; 
		exit(0);
	}
	instuf.seekg(0,ios::beg);
	instuf.getline(s,100);
	while(instuf>>A[i].id>>A[i].name>>A[i].Chinese>>A[i].math>>A[i].English>>A[i].total>>A[i].rank)
	{
		++ i;
	}
	A[0].count = i;
	instuf.close();
}
void fileInput(Student A[],string filename)
{	int i = 0;
	ofstream outstuf;
	outstuf.open(filename.c_str(),ios::out);
	if(!outstuf)
	{
		cerr<<"�ļ��򿪳�������ֹͣ���С�"<<endl;
		abort(); 
	}
	outstuf<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		   <<"Ӣ��"<<setw(10)<<"�ܷ�"<<setw(10)<<"����"<<setiosflags(ios::left)<<endl;
	for(i = 0;i<A[0].count;++ i) 
	{
		outstuf<<A[i];
	}
	outstuf.close();
}

void menu();                           //�˵�
void Creat();                          //�½��ļ�
void show();                           //��ʾ���м�¼ 
void addend();                         //��Ӽ�¼ 
void Sortstudent();                    //���������� 
void Deletefiles();                    //ɾ�������ļ���Ϣ 

void menu()
{	cout << "===============================\n";
	cout<<"              ��ӭ����"<<endl; 
	cout<<"------------ѧ���ɼ�����ϵͳ------------"<<endl;
	cout<<"              1���½�ѧ���ļ�"<<endl;
	cout<<"              2����ʾȫ��ѧ����Ϣ"<<endl;
	cout<<"              3����ѯ�����"<<endl;
	cout<<"              4������ѧ����Ϣ"<<endl;
	cout<<"              5��ɾ��ѧ����Ϣ"<<endl;
	cout<<"              6������"<<endl;
	cout<<"              7���ϲ�����ļ�"<<endl;
	cout<<"              8���޸�ѧ����Ϣ"<<endl;
	cout<<"              9��ɾ��������Ϣ"<<endl;
	cout<<"              0���˳�ϵͳ"<<endl;
	cout<<"***С��ʾ����ϵͳ�������ġ���ѧ��Ӣ�����ųɼ��������ֺܷ�����" <<endl;
	cout<<"-----------(�����Ӧ�����ʵ�ֶ�Ӧ�Ĺ���)------"<<endl; 
}
void Creat()
{
	cout<<"-----------�����������½��ļ�����---------"<<endl<<endl;
	string filename,a = "e:\\File",c = ".txt",b,file;
	stringstream sout;
	sout<<project;
	b = sout.str();
	file = a + b + c; 
	char ch;
	Student A[10000];
	cout<<"ȷ��Ҫʹ��Ĭ���ļ���"<<file<<"�� ��Y   or    N��         ";
	cout<<"������ѡ��";
	cin>>ch;
	if(ch == 'Y'||ch == 'y')
	{
		filename = file;
		++ project;
	}
	if(ch =='N'||ch == 'n')
	{	cout<<endl;
		cout<<"������Ҫ�½����ļ����ļ�����������ʽ�����ļ��洢·��������d:\\student.txt����ʽ��:";
		cin>>filename;
	}
	int i = 0,number;
	cout<<"������ѧ��������";
	cin>>number;
	cout<<endl;
	cout<<"������"<<number<<"ѧ���������Ϣ��"<<endl;	 
	cout<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		<<"Ӣ��"<<setw(10)<<endl;
	for(i = 0;i<number;++ i)
	{
		cin>>A[i];
	}
	A[0].count = number;
	sort(A,A+number,cmp1);
		for(i = 0;i<A[0].count;++ i)
	{
		A[i].displayrank(i+1);                          
	}
	fileInput(A,filename);
	cout<<"�ļ�"<<filename<<"�Գɹ����������а���"<<number<<"��ѧ��"<<endl<<endl;
	cout<<"-------���˳��½�����������к�������-------"<<endl<<endl; 
}

void show()
{	cout<<"-----------������ִ����ʾ�����ļ���Ϣ�Ĳ���----------"<<endl<<endl; 
	cout<<"������Ҫ���ʵ��ļ���(������ʽ)���ļ�����λ�ã�����d:\\student.txt����ʽ��"<<endl;
	string filename;
	Student A[10000];
	int n = 1;
	cout<<"�������"<<n<<"���ļ����ļ���������0�˳��ù��̣���";
	while(cin>>filename)
	{	if(filename == "0")
		{
			cout<<endl;
			break;
		}
		fileOutput(A,filename);
		cout<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
			   <<"Ӣ��"<<setw(10)<<"�ܷ�"<<setw(10)<<"����"<<setiosflags(ios::left)<<endl;
		for(int i = 0;i<A[0].count;++ i)
		{
			cout<<A[i];
		}
		cout<<endl; 
		++ n;
		cout<<"�������"<<n<<"���ļ����ļ���������0�˳��ù��̣���";
	}
	cout<<"-------���˳���ʾ����������к�������-------"<<endl<<endl; 
}

void seekstudent()
{
	cout<<"-----------������ִ�в�ѯ������Ĳ���----------"<<endl<<endl; 
	cout<<"������Ҫ���ʵ��ļ���(������ʽ)���ļ�����λ�ã�����d:\\student.txt����ʽ����";
	string filename;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"�����������ֲ��ҷ�ʽ��1����ѧ��   2��������    3��������     0���˳����ι���"<<endl;
	int type,rank,i,symbol = -1; 
	string id,name;
	char ch,choice; 
	cout<<"��������ҷ�ʽ����Ӧ��Ŷ�Ӧ��Ӧ��ʽ����";
	while(cin>>type)
	{	if(type == 0)  
		{
			cout<<"-------���˳���������������к�������-------"<<endl<<endl;
			break;  
		}
		if(type == 1)
		{
			cout<<"������Ҫ����ѧ����ѧ�ţ�";
			cin>>id;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].id == id)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					break; 
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		if(type == 2)
		{
			cout<<"������Ҫ����ѧ����������";
			cin>>name;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].name == name)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					break;
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		if(type == 3)
		{
			cout<<"������Ҫ����ѧ�������Σ�";
			cin>>rank;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].rank == rank)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					break;	
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		cout<<"��������ҷ�ʽ������0�˳��ù��̣�  ��";
	}
}

void addend()
{
	cout<<"-----------������ִ����Ӽ�¼�Ĳ���----------"<<endl<<endl; 
	cout<<"������Ҫ���ʵ��ļ���(������ʽ)���ļ�����λ�ã�����d:\\student.txt����ʽ����";
	string filename;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"������Ҫ��ӵļ�¼����Ŀ��";
	int i = A[0].count,number;
	cin>>number;
	cout<<endl; 
	cout<<"������Ҫ��ӵļ�¼��Ϣ��"<<endl;
	cout<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		<<"Ӣ��"<<setw(10)<<endl;
	for(i = A[0].count;i<A[0].count+number;++ i)
	{
		cin>>A[i];
	} 
	A[0].count = i;
	sort(A,A+A[0].count,cmp1);
	for(i = 0;i<A[0].count;++ i)
	{
		A[i].displayrank(i+1);
	}
	fileInput(A,filename);
	cout<<number<<"���µ���Ϣ�������"<<filename<<"�У��ָ��ļ���һ����"<<A[0].count<<"����¼"<<endl<<endl; 
	cout<<"-------���˳���Ӳ���������к�������-------"<<endl<<endl;
} 

void deletedate()
{
	cout<<"-----------������ִ��ɾ����¼�Ĳ���----------"<<endl<<endl; 
	cout<<"������Ҫ���ʵ��ļ���(������ʽ)���ļ�����λ�ã�����d:\\student.txt����ʽ����";
	string filename;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"�����������ֲ���ɾ����ʽ��1����ѧ��   2��������    3��������     0���˳����ι���"<<endl<<endl;
	int type,rank,i,symbol = -1,j = A[0].count;
	string id,name;
	char ch,choice; 
	cout<<"��������ҷ�ʽ����Ӧ��Ŷ�Ӧ��Ӧ��ʽ����";
	while(cin>>type)
	{	if(type == 0)  
		{
			cout<<"���˳����ҹ���"<<endl<<endl;
			break;  
		}
		if(type == 1)
		{
			cout<<"������Ҫ����ѧ����ѧ�ţ�";
			cin>>id;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].id == id)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"ȷ��Ҫɾ����ѧ����Ϣ��(Y or N)       ������ѡ��";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						A[i].total = -1;
						j = j - 1;
						cout<<"ɾ���ɹ���   ���������"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						cout<<"ɾ��ʧ�ܣ�   ���������"<<endl<<endl;
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		if(type == 2)
		{
			cout<<"������Ҫ����ѧ����������";
			cin>>name;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].name == name)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"ȷ��Ҫɾ����ѧ����Ϣ��(Y or N)       ������ѡ��";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						A[i].total = -1;
						j = j - 1;
						cout<<"ɾ���ɹ���   ���������"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						cout<<"ɾ��ʧ�ܣ�   ���������"<<endl<<endl;
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		if(type == 3)
		{
			cout<<"������Ҫ����ѧ�������Σ�";
			cin>>rank;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].rank == rank)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"ȷ��Ҫɾ����ѧ����Ϣ��(Y or N)       ������ѡ��";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						A[i].total = -1;
						j = j - 1;
						cout<<"ɾ���ɹ���   ���������"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						cout<<"ɾ��ʧ�ܣ�   ���������"<<endl<<endl;
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		cout<<"��������ҷ�ʽ������0�˳��ù��̣�  ��";
	}
	sort(A,A+A[0].count,cmp1);
	for(i = 0;i<A[0].count;++ i)
	{
		A[i].displayrank(i+1);                         
	}
	A[0].count = j;
	if(symbol == -1) 
	{
		cout<<"����ɾ�������ѽ�����   �������������" <<endl<<endl; 
	}
	else
	{	
		fileInput(A,filename);
		cout<<"����ִ�гɹ���"<<endl<<endl; 
		cout<<"-------���˳�ɾ������������к�������-------"<<endl<<endl;
	} 
}

void Sortstudent() 
{
	cout<<"----------��ִ���������------------"<<endl<<endl;
	cout<<"������Ҫ������ļ���(������ʽ)���ļ�����λ�ã�����d:\\student.txt����ʽ����";
	string filename;
	int i = 0;
	char ch;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"��������6������ʽ��1���ܷ�  2������   3����ѧ   4��Ӣ��    5��ѧ��    6������"<<endl;
	cout<<"�����ξ�Ϊ��ÿ���������������γɵ�����,������Ӧ���Ŷ�Ӧ��Ӧ������ʽ��"<<endl;
	cout<<"����������ʽ��"; 
	int type;
	cin>>type;
	switch(type)
	{
		case 1:sort(A,A+A[0].count,cmp1);break;
		case 2:sort(A,A+A[0].count,cmp2);break;
		case 3:sort(A,A+A[0].count,cmp3);break;
		case 4:sort(A,A+A[0].count,cmp4);break;
		case 5:sort(A,A+A[0].count,cmp5);break;
		case 6:sort(A,A+A[0].count,cmp6);break;
	}
	for(i = 0;i<A[0].count;++ i)                                 
	{
		A[i].displayrank(i+1);
	}
	ofstream outstuf;
	outstuf.open(filename.c_str(),ios::out);
	switch(type)
	{
		case 1:outstuf<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		   			<<"Ӣ��"<<setw(10)<<"�ܷ�"<<setw(10)<<"����"<<setiosflags(ios::left)<<"�����ܷ�����"<<endl;break;
		case 2:outstuf<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		   			<<"Ӣ��"<<setw(10)<<"�ܷ�"<<setw(10)<<"����"<<setiosflags(ios::left)<<"������������"<<endl;break;
		case 3:outstuf<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		   			<<"Ӣ��"<<setw(10)<<"�ܷ�"<<setw(10)<<"����"<<setiosflags(ios::left)<<"������ѧ����"<<endl;break;
		case 4:outstuf<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		   			<<"Ӣ��"<<setw(10)<<"�ܷ�"<<setw(10)<<"����"<<setiosflags(ios::left)<<"����Ӣ������"<<endl;break;
		case 5:outstuf<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		   			<<"Ӣ��"<<setw(10)<<"�ܷ�"<<setw(10)<<"����"<<setiosflags(ios::left)<<"����ѧ������"<<endl;break;
		case 6:outstuf<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
		   			<<"Ӣ��"<<setw(10)<<"�ܷ�"<<setw(10)<<"����"<<setiosflags(ios::left)<<"������������"<<endl;break;
	}
	for(i = 0;i<A[0].count;++ i) 
	{
		outstuf<<A[i];
	}
	cout<<"-------������ϣ�   ���Ƴ�������--------"<<endl<<endl; 
	outstuf.close();
}

void  Changedate()
{	cout<<"-----------������ִ���޸ļ�¼�Ĳ���----------"<<endl<<endl; 
	cout<<"������Ҫ���ʵ��ļ���(������ʽ)���ļ�����λ�ã�����d:\\student.txt����ʽ����";
	string filename;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"�����������ֲ����޸ķ�ʽ��1����ѧ��   2��������    3��������     0���˳����ι���"<<endl<<endl;
	int type,rank,i,symbol = -1; 
	string id,name;
	char ch,choice; 
	cout<<"��������ҷ�ʽ����Ӧ��Ŷ�Ӧ��Ӧ��ʽ����";
	while(cin>>type)
	{	if(type == 0)  
		{
			cout<<"���˳����ҹ���"<<endl<<endl;
			break;  
		}
		if(type == 1)
		{
			cout<<"������Ҫ����ѧ����ѧ�ţ�";
			cin>>id;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].id == id)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"ȷ��Ҫ�޸ĸ�ѧ����Ϣ��(Y or N)       ������ѡ��";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						cout<<"�����������޸ĺ��ѧ����Ϣ��"<<endl;
						cout<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
							<<"Ӣ��"<<setw(10)<<endl; 
						cin>>A[i];
						cout<<"�޸ĳɹ���   ���������"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		if(type == 2)
		{
			cout<<"������Ҫ����ѧ����������";
			cin>>name;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].name == name)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"ȷ��Ҫ�޸ĸ�ѧ����Ϣ��(Y or N)       ������ѡ��";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						cout<<"�����������޸ĺ��ѧ����Ϣ��"<<endl;
						cout<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
							<<"Ӣ��"<<setw(10)<<endl; 
						cin>>A[i];
						cout<<"�޸ĳɹ���   ���������"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		if(type == 3)
		{
			cout<<"������Ҫ����ѧ�������Σ�";
			cin>>rank;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].rank == rank)
				{	symbol = 1;
					cout<<"��ѧ���ǣ�"<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"ȷ��Ҫ�޸ĸ�ѧ����Ϣ��(Y or N)       ������ѡ��";
					cin>>ch;
					cout<<endl;
					if(ch == 'Y'||ch == 'y')
					{
						cout<<"�����������޸ĺ��ѧ����Ϣ��"<<endl;
						cout<<"ѧ��"<<setw(15)<<"����"<<setw(15)<<"����"<<setw(10)<<"��ѧ"<<setw(10)
							<<"Ӣ��"<<setw(10)<<endl; 
						cin>>A[i];
						cout<<"�޸ĳɹ���   ���������"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						break;
					}
					
				}
			}
			if(symbol == -1) 
			{
				cout<<"���ļ�Ϊ���ļ����ѧ����Ϣ�����ڣ����ٴγ��ԡ�"<<endl; 
			}
		}
		cout<<"��������ҷ�ʽ������0�˳��ù��̣�  ��";
	}
	sort(A,A+A[0].count,cmp1);
	for(i = 0;i<A[0].count;++ i)
	{
		A[i].displayrank(i+1);                         
	}
	if(symbol == -1) 
	{
		cout<<"�����޸Ĺ����ѽ�����   �������������" <<endl<<endl; 
	}
	else
	{
		cout<<"ȷ��Ҫ�����޸ĺ���ĵ��𣿣�Y  or  N��"<<endl;
		cout<<"��ѡ��";
		cin>>choice;
		cout<<endl; 
		if(choice == 'y'||choice == 'Y')
		{
			fileInput(A,filename);
			cout<<"�ļ��ѱ��棡"<<endl; 
		}
		if(choice == 'N'||choice == 'n')
		{
			
			cout<<"�޸���Ч���ļ�δ���棡"<<endl; 
		}
		cout<<"-------���˳��޸Ĳ���������к�������-------"<<endl<<endl;
	} 
}

void Combinefiles() 
{
	cout<<"-----------������ִ�кϲ��ļ��Ĳ���----------"<<endl<<endl; 
	cout<<"������Ҫ�ϲ����ļ���(������ʽ)���ļ�����λ�ã�����d:\\student.txt����ʽ��"<<endl;
	int n = 1,i = 0,choice; 
	string filename;
	char ch;
	Student A[10000]; 
	cout<<"�������"<<n<<"���ļ�������0�˳��ù��̣���";
    while(cin>>filename)
    {	if(filename == "0")
    	{
    		if(n!=1)   cout<<"�����ļ���ȡ��ϣ�"<<endl<<endl;
			break; 
		}
    	char s[100];
		ifstream instuf;
		instuf.open(filename.c_str(),ios::in);
		if(!instuf)
		{
			cerr<<"�ļ������ڻ��ļ��򿪳�������������һ���ļ�"<<endl<<endl; 
			cout<<"�������"<<n<<"���ļ�������0�˳��ù��̣���"; 
			continue;
		}
		instuf.seekg(0,ios::beg);
		instuf.getline(s,100);
		while(instuf>>A[i].id>>A[i].name>>A[i].Chinese>>A[i].math>>A[i].English>>A[i].total>>A[i].rank)
		{
			++ i;
		}
		A[0].count = i;
		instuf.close();
		++ n;
		cout<<"�������"<<n<<"���ļ�������0�˳��ù��̣���"; 
	}
	sort(A,A+A[0].count,cmp1);
	for(i = 0;i<A[0].count;++ i)
	{
		A[i].displayrank(i+1);                          
	}
	if(n!=1)
	{
		cout<<"ȷ��Ҫ�ϲ������ļ��� ��Y   or   N��"<<endl;
		cout<<"������ѡ��";
		cin>>ch;
		if(ch == 'Y'||ch == 'y')
		{
			cout<<"������Ҫ�ϲ������ļ����ļ���������d:\\student.txt����ʽ��ԭ�ļ����½��ļ����ɣ���"<<endl;
			cin>>filename;
			fileInput(A,filename) ;
			cout<<"�ļ��ѳɹ��ϲ���"<<filename<<endl<<endl;
			cout<<"----------���˳��ϲ���������ִ�к�������-----------"<<filename<<endl<<endl;
		}
		if(ch == 'N'||ch == 'n')
		{
			cout<<"-------�ϲ�ʧ�ܣ�  �ϲ����ܽ������������������----------"<<endl<<endl; 
		}
	}
	else
	{
		cout<<"---------�ϲ����ܽ������������������----------"<<endl<<endl; 
	}
} 

void Deletefiles()
{
	cout<<"-----------������ִ��ɾ���ļ��Ĳ���----------"<<endl<<endl; 
	cout<<"������Ҫɾ�����ļ����ļ���(������ʽ)���ļ�����λ�ã�����d:\\student.txt����ʽ��"<<endl;
	string filename;
	char ch;
	ofstream outstuf;
	int n = 1;
	cout<<"�������"<<n<<"���ļ�������0�˳��ù��̣���";
	while(cin>>filename)
	{
		if(filename == "0")
    	{
    		if(n!=1)   cout<<"------------�����ļ�����ɾ������ִ�к�������------------"<<endl<<endl;
    		else  cout<<"--------����ɾ�����ܣ���ִ�к�������------------"<<endl<<endl; 
			break; 
		}
		cout<<"ȷ��Ҫɾ��"<<filename<<"��ȫ����Ϣ��  ��Y   or  N��"<<endl;
		cout<<"������ѡ��";
		cin>>ch;
		if(ch == 'Y'||ch == 'y')
		{
			outstuf.open(filename.c_str(),ios::trunc);
			if(!outstuf)
			{
				cerr<<"�ļ������ڻ��ļ��򿪳����ļ�ɾ��ʧ��,����������һ���ļ�"<<endl<<endl;
				cout<<"�������"<<n<<"���ļ�������0�˳��ù��̣���";
				continue; 
			}
			outstuf.close();
			cout<<"�ļ�"<<filename<<"�ѳɹ�ɾ��"<<endl<<endl; 
		}
		if(ch == 'N'||ch == 'n')
		{
			cout<<"�ļ�"<<filename<<"��ȡ��ɾ�������������"<<endl<<endl;
		}
		++ n; 
		cout<<"�������"<<n<<"���ļ�������0�˳��ù��̣���";
	}  
} 

int main ()
{
	int choice;
	menu();
	cout<<"������Ҫ���еĲ�������Ӧ���ִ����Ӧ��������";
	while(cin>>choice)
	{	cout<<endl<<endl;
		if(choice == 0)
		{
			cout<<"***************���˳�ϵͳ***************"<<endl<<endl;
			exit(0); 
		}
		switch(choice)
		{
			case 1:Creat();break;
			case 2:show();break;
			case 3:seekstudent();break;
			case 4:addend();break;
			case 5:deletedate();break;
			case 6:Sortstudent();break;
			case 7:Combinefiles();break;
			case 8:Changedate();break;
			case 9:Deletefiles();break;
		}
		cout<<"������Ҫ���еĲ�������Ӧ���ִ����Ӧ��������";
	}
}