C++�е�get(),getchar(),getline()�ȵ��÷�������

������������һ���ַ�ָ�룬���������ƶ���ÿ��ָ��ǰӦ�����ַ���


1��get()
	
	1) �޲�get()
		�÷���cin,get();
		���Դ�����������ȡһ���ַ��������հ��ַ������������������е��ļ���������
		����ֵ�����ļ�������־EOF(End Of File)��һ����-1����EOF��
		
		[��] ��get���������ַ���

			#include <iostream>
			using namespace std;
			int main( )
			{
			int c;
			cout<<"enter a sentence:"<<endl;
			while((c=cin.get())!=EOF)
			cout.put(c);
			return 0;
			}
			
			����������£�
			enter a sentence:
			I study C++ very hard   //(����һ���ַ�)
			I study C++ very hard      // (��������ַ�)
			^Z�L(�������)
			
	2) ��һ��������get()����
		��ʽ��cin.get(ch);
		�������Ǵ��������ж�ȡһ���ַ��������ַ�����ch��
		
		��������ӿ��Ը�д���£�

		#include <iostream>
		using namespace std;
		int main( )
		{
		  char c;
		  cout<<"enter a sentence:"<<endl;
		  while(cin.get(c)) //��ȡһ���ַ������ַ�����c,�����ȡ�ɹ�,cin.get(c)Ϊ��
		  {cout.put(c);}
		  cout<<"end"<<endl;
		  return 0;
		}
		
	3) ������������get()����
		��ʽ�� cin.get(�ַ�����, �ַ�����n, ��ֹ�ַ�) �� cin.get(�ַ�ָ��, �ַ�����n, ��ֹ�ַ�)
				�����ֹ�ַ���д����Ĭ��Ϊ���з���
		�������Ǵ��������ж�ȡn-1���ַ�������ָ�����ַ�����(���ַ�ָ��ָ�������)������ڶ�ȡn-1
		���ַ�֮ǰ����ָ������ֹ�ַ�������ǰ������ȡ�������ȡ�ɹ���������true(��)��
		��ʧ��(���ļ�������) ��������false(��)��
		
		������

		#include <iostream>
		using namespace std;
		int main( )
		{
		  char ch[20];
		  cout<<"enter a sentence:"<<endl;
		  cin.get(ch,10,'\\n');//ָ�����з�Ϊ��ֹ�ַ�
		 cout<<ch<<endl;
		  return 0;
		}
		
		����������£�

		enter a sentence:
		I study C++ very hard
		I study
		
2��getchar()   {��Ϊ�ú�����c���Զ���������û��cin.getchar()��˵��}
	�˺����������Ǵ��ն�(��ϵͳ����ָ���������豸)����һ���ַ���getchar����û�в�����
	��һ����ʽΪgetchar( )������ֵ���Ǵ������豸�õ����ַ���
	�÷���char ch = getchar();
	getchar()��cin.get()Ч�����ơ�
	
3��getline()
	�ú��������Ǵ���������ȡһ���ַ�(�����ո�)��  �������ǰû�������ʹ��������������û����룬������������
	1) ����ַ����ַ���
	�÷�����get()�������������ƣ� cin.getline(�ַ�����(���ַ�ָ��), �ַ�����n, ��ֹ��־�ַ�)
	
	2)���string��
	�÷���getchar(cin,str);
	��ȡһ���ַ����ڴ�str�У�
	
4��cin>>
	���������������ո���оͽ�����
		
		
����Ӧ�ã�
��Բ�֪�����뼸��Ԫ�أ��������س����м�ͣ����
#include <iostream> 
#include <string>
#include<stdio.h>
using namespace std; 
int main() 
{ 
	int i = 0,array[10000],temp;
	while(cin>>temp)
	{
		array[i++] = temp;
		if(cin.get() == '\n')
			break;
	}
	for(int j = 0;j<i;++ j)
	{
		cout<<array[j]<<" ";
	}
} 

ע�⣬�ж��Ƿ�Ϊ���з������if(cin.get() == '\n') break;
һ��Ҫ����ѭ��������������һ���֣����ܽ��ַ�ȫ�����롣
			
		
		
		
			