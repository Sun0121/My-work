#include<iostream>
using namespace std;

template<typename T>
class T_Counter
{	
	T n;
	public:
		T_Counter (T a = 0) { n = a;}
		T_Counter(T_Counter &a) { n = a.n;}
		T_Counter operator+(T_Counter &a) 
		{	
			T_Counter b;
			b.n = this->n+a.n;
			return b;
		}
		T_Counter operator-(T_Counter &a)
		{
			T_Counter b;
			b.n = this->n-a.n;
			return b;
		}
		T_Counter operator*(T_Counter &a)
		{
			T_Counter b;
			b.n = this->n*a.n;
			return b;
		}	
		T_Counter & operator=(T_Counter &a) { n = a.n;return *this;}
		template<typename T>                                          //此两个函数是友元函数，不属于类中。
		friend ostream & operator<<(ostream &Output, T_Counter<T> &A);   //所以要用template<typename T>声明。
		template<typename T>
		friend istream & operator>>(istream &Input ,T_Counter<T> &A);
};
template<typename T>
ostream & operator<<(ostream &Output, T_Counter<T> &A)
{	
	cout<<A.n;
	return Output;
}
template<typename T>
istream & operator>>(istream & Input ,T_Counter<T> &A)
{	
	cin>>A.n;
	return Input;
}

template<typename T>
class T_Vector
{	
	int len;
	T *v;
	public:
		T_Vector(int n = 0);
		T_Vector( T *,int n = 0);
		T_Vector(T_Vector &);
		T_Vector operator +(T_Vector &);
		T_Vector operator -(T_Vector &);
		int operator *(T_Vector &);
		T_Vector & operator = (T_Vector &);
		template<typename T>
		friend ostream & operator<<(ostream &Output,T_Vector<T> &);
		template<typename T>
		friend istream & operator>>(istream &Input, T_Vector<T> &);
} ;
template<typename T> T_Vector<T>::T_Vector(int n)
{	
	v = new T[n];
	len = n;
}
template<typename T> T_Vector<T>::T_Vector( T *a,int n)
{	
	v = new T[n];
	len = n;
	for(int i = 0;i<n;++ i)
	{		
		v[i] = a[i];
	}	
} 
template<typename T> T_Vector<T>::T_Vector(T_Vector<T> &a)
{	
	len = a.len;             
	v = new T[len];
	for(int i = 0;i<len;++ i)
	{	
		v[i] = a.v[i];
	}
}
template<typename T>
istream & operator>>(istream &Input,T_Vector<T> &A)
{	
	for(int i = 0;i<A.len;++ i)
	{	
		Input>>A.v[i];
	}
	return Input;
}
template<typename T>
ostream & operator<<(ostream &Output,T_Vector<T> &A)
{	
	for(int i = 0;i<A.len;++ i)
	{	
		Output<<A.v[i]<<" ";
	}
	return Output;
}
template<typename T>T_Vector<T> T_Vector<T>::operator +(T_Vector &A)
{	
	T_Vector<T> C;
	C.len = A.len;
	C.v = new T[C.len];
	for(int i = 0;i<A.len;++ i)
	{	
		C.v[i] = v[i] + A.v[i]; 
	}
	return C;
}
template<typename T>T_Vector<T> T_Vector<T>::operator -(T_Vector &A)
{	
	T_Vector<T> C;
	C.len = A.len;
	C.v = new T[C.len];
	for(int i = 0;i<A.len;++ i)
	{	
		C.v[i] = v[i] - A.v[i]; 
	}
	return C;
}
template<typename T>int T_Vector<T>::operator *(T_Vector &A)
{	int C = 0;
	for(int i = 0;i<A.len;++ i)
	{	
		C += v[i] * A.v[i]; 
	}
	return C;
}
template<typename T>T_Vector<T> &T_Vector<T>::operator =(T_Vector &A)
{	len = A.len; 
	for(int i = 0;i<A.len;++ i)
	{	
		v[i] = A[i]; 
	}
	return *this;
}

template<typename T>
class T_Matrix
{
	int a,b;
	T v[100][100];
	public:
		T_Matrix(int m = 0,int n = 0);
		T_Matrix(T_Matrix &A);
		~T_Matrix() {}
		T_Matrix operator +(T_Matrix &);
		T_Matrix operator -(T_Matrix &);
		T_Matrix operator *(T_Matrix &);
		T_Matrix & operator =(T_Matrix &);
		template<typename T>
		friend istream & operator >>(istream &Input,T_Matrix<T> &);
		template<typename T>
		friend ostream & operator <<(ostream &Output,T_Matrix<T> &);
};
template<typename T>
T_Matrix<T>::T_Matrix(int m,int n)
{
	a = m;
	b = n;
}
template<typename T>
T_Matrix<T>::T_Matrix(T_Matrix<T> &A)
{
	a = A.a;
	b = A.b;
	for(int i = 0;i<a;++ i)
		for(int j = 0;j<b;++ j)
			v[i][j] = A.v[i][j];
}
template<typename T>
T_Matrix<T> T_Matrix<T>::operator  +(T_Matrix<T> &A)
{
	T_Matrix<T> C;
	C.a = A.a;
	C.b = A.b;
	int i,j;
	for(i = 0;i<a;++ i)
		for(j = 0;j<b;++ j)
		{
			C.v[i][j] = v[i][j] + A.v[i][j];
		}
	return C;
}
template<typename T>
T_Matrix<T> T_Matrix<T>::operator  -(T_Matrix<T> &A)
{
	T_Matrix<T> C;
	C.a = A.a;
	C.b = A.b;
	int i,j;
	for(i = 0;i<a;++ i)
		for(j = 0;j<b;++ j)
		{
			C.v[i][j] = v[i][j] - A.v[i][j];
		}
	return C;
}
template<typename T>
T_Matrix<T> T_Matrix<T>::operator  *(T_Matrix<T> &A)
{
	T_Matrix<T> C;
	int m,n;
	C.a = a;
	C.b = A.b;
	int i,j;
	for(i = 0;i<C.a;++ i)
		for(j = 0;j<A.b;++ j)
		{
			C.v[i][j] = 0;
			for(m = 0,n = 0;m<b;++ m,++ n)
				C.v[i][j] += v[i][m]*A.v[n][j];
		}
	return C;
}
template<typename T>
T_Matrix<T> & T_Matrix<T>::operator  =(T_Matrix<T> &A)
{
	a = A.a;
	b = A.b;
	int i,j;
	for(i = 0;i<a;++ i)
		for(j = 0;j<b;++ j)
		{
			v[i][j] = A.v[i][j];
		}
	return *this;
}
template<typename T>
istream & operator >>(istream &Input,T_Matrix<T> &A)
{
	int i,j;
	for(i = 0;i<A.a;++ i)
		for(j = 0;j<A.b;++ j)
			cin>>A.v[i][j];
	return Input;
}
template<typename T>
ostream & operator <<(ostream &Output,T_Matrix<T> &A)
{
	int i,j;
	for(i = 0;i<A.a;++ i)
	{	for(j = 0;j<A.b;++ j)
		{	cout<<A.v[i][j]<<" ";
		}
		cout<<endl;
	}
	return Output;
}

int main ()
{
	T_Matrix<int> a(2,2),b(2,2),c(2,2);
	T_Counter<double> a1,b1,c1;
	T_Vector<char> a2,b2,c2;
	cin>>a>>b;
	c = a-b;
	cout<<c;
	c = a*b;
	cout<<c;
}