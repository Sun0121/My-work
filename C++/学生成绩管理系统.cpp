#include<iostream>
#include<fstream> 
#include<string>
#include<algorithm>
#include<iomanip>         
#include<sstream>

using namespace std;

static int project = 1;

class Studentdates                                    //第一个类，定义学生属性 
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
		friend void fileOutput(Student A[],string filename);         //读取文件 
		friend void fileInput(Student A[],string filename);          //保存文件 
		friend void seekstudent();                                  //查找学生 
		friend void deletedate();                                   //删除记录 
		friend void Changedate();                                  //修改记录 
		friend void Combinefiles();                                //合并文件 
		friend istream & operator>>(istream &Input ,Student &);
		friend ostream & operator<<(ostream &Output ,Student &);
};
bool cmp1(Student a,Student b)                            //中以不同的属性排序 
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
		cerr<<"文件不存在或文件打开出错"<<endl; 
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
		cerr<<"文件打开出错，程序停止运行。"<<endl;
		abort(); 
	}
	outstuf<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		   <<"英语"<<setw(10)<<"总分"<<setw(10)<<"名次"<<setiosflags(ios::left)<<endl;
	for(i = 0;i<A[0].count;++ i) 
	{
		outstuf<<A[i];
	}
	outstuf.close();
}

void menu();                           //菜单
void Creat();                          //新建文件
void show();                           //显示所有记录 
void addend();                         //添加记录 
void Sortstudent();                    //多属性排序 
void Deletefiles();                    //删除所有文件信息 

void menu()
{	cout << "===============================\n";
	cout<<"              欢迎进入"<<endl; 
	cout<<"------------学生成绩管理系统------------"<<endl;
	cout<<"              1、新建学生文件"<<endl;
	cout<<"              2、显示全部学生信息"<<endl;
	cout<<"              3、查询与检索"<<endl;
	cout<<"              4、增加学生信息"<<endl;
	cout<<"              5、删除学生信息"<<endl;
	cout<<"              6、排序"<<endl;
	cout<<"              7、合并多个文件"<<endl;
	cout<<"              8、修改学生信息"<<endl;
	cout<<"              9、删除所有信息"<<endl;
	cout<<"              0、退出系统"<<endl;
	cout<<"***小提示：本系统包含语文、数学、英语三门成绩，还有总分和名次" <<endl;
	cout<<"-----------(输入对应的序号实现对应的功能)------"<<endl; 
}
void Creat()
{
	cout<<"-----------现在正进行新建文件操作---------"<<endl<<endl;
	string filename,a = "e:\\File",c = ".txt",b,file;
	stringstream sout;
	sout<<project;
	b = sout.str();
	file = a + b + c; 
	char ch;
	Student A[10000];
	cout<<"确定要使用默认文件名"<<file<<"吗？ （Y   or    N）         ";
	cout<<"请输入选择：";
	cin>>ch;
	if(ch == 'Y'||ch == 'y')
	{
		filename = file;
		++ project;
	}
	if(ch =='N'||ch == 'n')
	{	cout<<endl;
		cout<<"请输入要新建的文件的文件名（包括格式）与文件存储路径（形如d:\\student.txt的形式）:";
		cin>>filename;
	}
	int i = 0,number;
	cout<<"请输入学生人数：";
	cin>>number;
	cout<<endl;
	cout<<"请输入"<<number<<"学生的相关信息："<<endl;	 
	cout<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		<<"英语"<<setw(10)<<endl;
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
	cout<<"文件"<<filename<<"以成功建立，其中包含"<<number<<"个学生"<<endl<<endl;
	cout<<"-------已退出新建操作，请进行后续操作-------"<<endl<<endl; 
}

void show()
{	cout<<"-----------现在正执行显示所有文件信息的操作----------"<<endl<<endl; 
	cout<<"请输入要访问的文件名(包括格式)及文件所在位置（形如d:\\student.txt的形式）"<<endl;
	string filename;
	Student A[10000];
	int n = 1;
	cout<<"请输入第"<<n<<"个文件的文件名（输入0退出该过程）：";
	while(cin>>filename)
	{	if(filename == "0")
		{
			cout<<endl;
			break;
		}
		fileOutput(A,filename);
		cout<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
			   <<"英语"<<setw(10)<<"总分"<<setw(10)<<"名次"<<setiosflags(ios::left)<<endl;
		for(int i = 0;i<A[0].count;++ i)
		{
			cout<<A[i];
		}
		cout<<endl; 
		++ n;
		cout<<"请输入第"<<n<<"个文件的文件名（输入0退出该过程）：";
	}
	cout<<"-------已退出显示操作，请进行后续操作-------"<<endl<<endl; 
}

void seekstudent()
{
	cout<<"-----------现在正执行查询与检索的操作----------"<<endl<<endl; 
	cout<<"请输入要访问的文件名(包括格式)及文件所在位置（形如d:\\student.txt的形式）：";
	string filename;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"本程序有三种查找方式：1、按学号   2、按姓名    3、按名次     0、退出本次过程"<<endl;
	int type,rank,i,symbol = -1; 
	string id,name;
	char ch,choice; 
	cout<<"请输入查找方式（相应序号对应相应方式）：";
	while(cin>>type)
	{	if(type == 0)  
		{
			cout<<"-------已退出检索操作，请进行后续操作-------"<<endl<<endl;
			break;  
		}
		if(type == 1)
		{
			cout<<"请输入要查找学生的学号：";
			cin>>id;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].id == id)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					break; 
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		if(type == 2)
		{
			cout<<"请输入要查找学生的姓名：";
			cin>>name;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].name == name)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					break;
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		if(type == 3)
		{
			cout<<"请输入要查找学生的名次：";
			cin>>rank;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].rank == rank)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					break;	
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		cout<<"请输入查找方式（输入0退出该过程）  ：";
	}
}

void addend()
{
	cout<<"-----------现在正执行添加纪录的操作----------"<<endl<<endl; 
	cout<<"请输入要访问的文件名(包括格式)及文件所在位置（形如d:\\student.txt的形式）：";
	string filename;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"请输入要添加的记录的数目：";
	int i = A[0].count,number;
	cin>>number;
	cout<<endl; 
	cout<<"请输入要添加的记录信息："<<endl;
	cout<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		<<"英语"<<setw(10)<<endl;
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
	cout<<number<<"条新的信息已添加至"<<filename<<"中，现该文件中一共有"<<A[0].count<<"条记录"<<endl<<endl; 
	cout<<"-------已退出添加操作，请进行后续操作-------"<<endl<<endl;
} 

void deletedate()
{
	cout<<"-----------现在正执行删除纪录的操作----------"<<endl<<endl; 
	cout<<"请输入要访问的文件名(包括格式)及文件所在位置（形如d:\\student.txt的形式）：";
	string filename;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"本程序有三种查找删除方式：1、按学号   2、按姓名    3、按名次     0、退出本次过程"<<endl<<endl;
	int type,rank,i,symbol = -1,j = A[0].count;
	string id,name;
	char ch,choice; 
	cout<<"请输入查找方式（相应序号对应相应方式）：";
	while(cin>>type)
	{	if(type == 0)  
		{
			cout<<"已退出查找过程"<<endl<<endl;
			break;  
		}
		if(type == 1)
		{
			cout<<"请输入要查找学生的学号：";
			cin>>id;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].id == id)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"确定要删除该学生信息吗？(Y or N)       请输入选择：";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						A[i].total = -1;
						j = j - 1;
						cout<<"删除成功！   请继续查找"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						cout<<"删除失败！   请继续查找"<<endl<<endl;
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		if(type == 2)
		{
			cout<<"请输入要查找学生的姓名：";
			cin>>name;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].name == name)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"确定要删除该学生信息吗？(Y or N)       请输入选择：";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						A[i].total = -1;
						j = j - 1;
						cout<<"删除成功！   请继续查找"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						cout<<"删除失败！   请继续查找"<<endl<<endl;
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		if(type == 3)
		{
			cout<<"请输入要查找学生的名次：";
			cin>>rank;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].rank == rank)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"确定要删除该学生信息吗？(Y or N)       请输入选择：";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						A[i].total = -1;
						j = j - 1;
						cout<<"删除成功！   请继续查找"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						cout<<"删除失败！   请继续查找"<<endl<<endl;
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		cout<<"请输入查找方式（输入0退出该过程）  ：";
	}
	sort(A,A+A[0].count,cmp1);
	for(i = 0;i<A[0].count;++ i)
	{
		A[i].displayrank(i+1);                         
	}
	A[0].count = j;
	if(symbol == -1) 
	{
		cout<<"本次删除过程已结束！   请继续后续操作" <<endl<<endl; 
	}
	else
	{	
		fileInput(A,filename);
		cout<<"操作执行成功！"<<endl<<endl; 
		cout<<"-------已退出删除操作，请进行后续操作-------"<<endl<<endl;
	} 
}

void Sortstudent() 
{
	cout<<"----------现执行排序操作------------"<<endl<<endl;
	cout<<"请输入要排序的文件名(包括格式)及文件所在位置（形如d:\\student.txt的形式）：";
	string filename;
	int i = 0;
	char ch;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"本程序有6种排序方式：1、总分  2、语文   3、数学   4、英语    5、学号    6、姓名"<<endl;
	cout<<"（名次均为按每种属性排序下所形成的名次,输入相应代号对应相应的排序方式）"<<endl;
	cout<<"请输入排序方式："; 
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
		case 1:outstuf<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		   			<<"英语"<<setw(10)<<"总分"<<setw(10)<<"名次"<<setiosflags(ios::left)<<"（以总分排序）"<<endl;break;
		case 2:outstuf<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		   			<<"英语"<<setw(10)<<"总分"<<setw(10)<<"名次"<<setiosflags(ios::left)<<"（以语文排序）"<<endl;break;
		case 3:outstuf<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		   			<<"英语"<<setw(10)<<"总分"<<setw(10)<<"名次"<<setiosflags(ios::left)<<"（以数学排序）"<<endl;break;
		case 4:outstuf<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		   			<<"英语"<<setw(10)<<"总分"<<setw(10)<<"名次"<<setiosflags(ios::left)<<"（以英语排序）"<<endl;break;
		case 5:outstuf<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		   			<<"英语"<<setw(10)<<"总分"<<setw(10)<<"名次"<<setiosflags(ios::left)<<"（以学号排序）"<<endl;break;
		case 6:outstuf<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
		   			<<"英语"<<setw(10)<<"总分"<<setw(10)<<"名次"<<setiosflags(ios::left)<<"（以姓名排序）"<<endl;break;
	}
	for(i = 0;i<A[0].count;++ i) 
	{
		outstuf<<A[i];
	}
	cout<<"-------排序完毕！   已推出排序功能--------"<<endl<<endl; 
	outstuf.close();
}

void  Changedate()
{	cout<<"-----------现在正执行修改纪录的操作----------"<<endl<<endl; 
	cout<<"请输入要访问的文件名(包括格式)及文件所在位置（形如d:\\student.txt的形式）：";
	string filename;
	cin>>filename;
	Student A[10000];
	fileOutput(A,filename);
	cout<<"本程序有两种查找修改方式：1、按学号   2、按姓名    3、按名次     0、退出本次过程"<<endl<<endl;
	int type,rank,i,symbol = -1; 
	string id,name;
	char ch,choice; 
	cout<<"请输入查找方式（相应序号对应相应方式）：";
	while(cin>>type)
	{	if(type == 0)  
		{
			cout<<"已退出查找过程"<<endl<<endl;
			break;  
		}
		if(type == 1)
		{
			cout<<"请输入要查找学生的学号：";
			cin>>id;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].id == id)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"确定要修改该学生信息吗？(Y or N)       请输入选择：";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						cout<<"请重新输入修改后的学生信息："<<endl;
						cout<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
							<<"英语"<<setw(10)<<endl; 
						cin>>A[i];
						cout<<"修改成功！   请继续查找"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		if(type == 2)
		{
			cout<<"请输入要查找学生的姓名：";
			cin>>name;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].name == name)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"确定要修改该学生信息吗？(Y or N)       请输入选择：";
					cin>>ch;
					if(ch == 'Y'||ch == 'y')
					{
						cout<<"请重新输入修改后的学生信息："<<endl;
						cout<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
							<<"英语"<<setw(10)<<endl; 
						cin>>A[i];
						cout<<"修改成功！   请继续查找"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						break;
					}
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		if(type == 3)
		{
			cout<<"请输入要查找学生的名次：";
			cin>>rank;
			for(i = 0;i<A[0].count;++ i)
			{
				if(A[i].rank == rank)
				{	symbol = 1;
					cout<<"该学生是："<<endl;
					cout<<A[i];
					cout<<endl;
					cout<<"确定要修改该学生信息吗？(Y or N)       请输入选择：";
					cin>>ch;
					cout<<endl;
					if(ch == 'Y'||ch == 'y')
					{
						cout<<"请重新输入修改后的学生信息："<<endl;
						cout<<"学号"<<setw(15)<<"姓名"<<setw(15)<<"语文"<<setw(10)<<"数学"<<setw(10)
							<<"英语"<<setw(10)<<endl; 
						cin>>A[i];
						cout<<"修改成功！   请继续查找"<<endl<<endl;
					}
					if(ch == 'N'||ch == 'n')
					{
						break;
					}
					
				}
			}
			if(symbol == -1) 
			{
				cout<<"该文件为空文件或该学生信息不存在，请再次尝试。"<<endl; 
			}
		}
		cout<<"请输入查找方式（输入0退出该过程）  ：";
	}
	sort(A,A+A[0].count,cmp1);
	for(i = 0;i<A[0].count;++ i)
	{
		A[i].displayrank(i+1);                         
	}
	if(symbol == -1) 
	{
		cout<<"本次修改过程已结束！   请继续后续操作" <<endl<<endl; 
	}
	else
	{
		cout<<"确定要保存修改后的文档吗？（Y  or  N）"<<endl;
		cout<<"请选择：";
		cin>>choice;
		cout<<endl; 
		if(choice == 'y'||choice == 'Y')
		{
			fileInput(A,filename);
			cout<<"文件已保存！"<<endl; 
		}
		if(choice == 'N'||choice == 'n')
		{
			
			cout<<"修改无效，文件未保存！"<<endl; 
		}
		cout<<"-------已退出修改操作，请进行后续操作-------"<<endl<<endl;
	} 
}

void Combinefiles() 
{
	cout<<"-----------现在正执行合并文件的操作----------"<<endl<<endl; 
	cout<<"请输入要合并的文件名(包括格式)及文件所在位置（形如d:\\student.txt的形式）"<<endl;
	int n = 1,i = 0,choice; 
	string filename;
	char ch;
	Student A[10000]; 
	cout<<"请输入第"<<n<<"个文件（输入0退出该过程）：";
    while(cin>>filename)
    {	if(filename == "0")
    	{
    		if(n!=1)   cout<<"上述文件读取完毕！"<<endl<<endl;
			break; 
		}
    	char s[100];
		ifstream instuf;
		instuf.open(filename.c_str(),ios::in);
		if(!instuf)
		{
			cerr<<"文件不存在或文件打开出错，请重新输入一个文件"<<endl<<endl; 
			cout<<"请输入第"<<n<<"个文件（输入0退出该过程）："; 
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
		cout<<"请输入第"<<n<<"个文件（输入0退出该过程）："; 
	}
	sort(A,A+A[0].count,cmp1);
	for(i = 0;i<A[0].count;++ i)
	{
		A[i].displayrank(i+1);                          
	}
	if(n!=1)
	{
		cout<<"确定要合并以上文件吗？ （Y   or   N）"<<endl;
		cout<<"请输入选择：";
		cin>>ch;
		if(ch == 'Y'||ch == 'y')
		{
			cout<<"请输入要合并到的文件的文件名（形如d:\\student.txt的形式，原文件或新建文件均可）："<<endl;
			cin>>filename;
			fileInput(A,filename) ;
			cout<<"文件已成功合并至"<<filename<<endl<<endl;
			cout<<"----------已退出合并操作，请执行后续操作-----------"<<filename<<endl<<endl;
		}
		if(ch == 'N'||ch == 'n')
		{
			cout<<"-------合并失败！  合并功能结束，请继续其他操作----------"<<endl<<endl; 
		}
	}
	else
	{
		cout<<"---------合并功能结束，请继续其他操作----------"<<endl<<endl; 
	}
} 

void Deletefiles()
{
	cout<<"-----------现在正执行删除文件的操作----------"<<endl<<endl; 
	cout<<"请输入要删除的文件的文件名(包括格式)及文件所在位置（形如d:\\student.txt的形式）"<<endl;
	string filename;
	char ch;
	ofstream outstuf;
	int n = 1;
	cout<<"请输入第"<<n<<"个文件（输入0退出该过程）：";
	while(cin>>filename)
	{
		if(filename == "0")
    	{
    		if(n!=1)   cout<<"------------上述文件均已删除，请执行后续操作------------"<<endl<<endl;
    		else  cout<<"--------结束删除功能，请执行后续操作------------"<<endl<<endl; 
			break; 
		}
		cout<<"确定要删除"<<filename<<"的全部信息吗？  （Y   or  N）"<<endl;
		cout<<"请输入选择：";
		cin>>ch;
		if(ch == 'Y'||ch == 'y')
		{
			outstuf.open(filename.c_str(),ios::trunc);
			if(!outstuf)
			{
				cerr<<"文件不存在或文件打开出错，文件删除失败,请重新输入一个文件"<<endl<<endl;
				cout<<"请输入第"<<n<<"个文件（输入0退出该过程）：";
				continue; 
			}
			outstuf.close();
			cout<<"文件"<<filename<<"已成功删除"<<endl<<endl; 
		}
		if(ch == 'N'||ch == 'n')
		{
			cout<<"文件"<<filename<<"被取消删除操作，请继续"<<endl<<endl;
		}
		++ n; 
		cout<<"请输入第"<<n<<"个文件（输入0退出该过程）：";
	}  
} 

int main ()
{
	int choice;
	menu();
	cout<<"请输入要进行的操作（相应序号执行相应操作）：";
	while(cin>>choice)
	{	cout<<endl<<endl;
		if(choice == 0)
		{
			cout<<"***************已退出系统***************"<<endl<<endl;
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
		cout<<"请输入要进行的操作（相应序号执行相应操作）：";
	}
}