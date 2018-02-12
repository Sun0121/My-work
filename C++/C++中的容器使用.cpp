C++ �е�����ʹ��

1��#include<Vector>
	
	vector<int> c;

	c.clear()         �Ƴ��������������ݡ�

    c.empty()         �ж������Ƿ�Ϊ�ա�

    c.erase(pos)        ɾ��posλ�õ�����

    c.erase(beg,end) ɾ��[beg,end)���������

    c.front()         ���ص�һ�����ݡ�

    c.insert(pos,elem)  ��posλ�ò���һ��elem����

    c.pop_back()     ɾ�����һ�����ݡ�

    c.push_back(elem) ��β������һ�����ݡ�

    c.resize(num)     �������ø������Ĵ�С

    c.size()         ��������ʵ�����ݵĸ�����

    c.begin()           ����ָ��������һ��Ԫ�صĵ�����

    c.end()             ����ָ���������һ��Ԫ�صĵ�����

2��#include<deque>

	(1)    ���캯��
	deque():����һ����deque

	deque(int nSize):����һ��deque,Ԫ�ظ���ΪnSize

	deque(int nSize,const T& t):����һ��deque,Ԫ�ظ���ΪnSize,��ֵ��Ϊt

	deque(const deque &):���ƹ��캯��

	(2)    ���Ӻ���

	void push_front(const T& x):˫�˶���ͷ������һ��Ԫ��X

	void push_back(const T& x):˫�˶���β������һ��Ԫ��x

	iterator insert(iterator it,const T& x):˫�˶�����ĳһԪ��ǰ����һ��Ԫ��x

	void insert(iterator it,int n,const T& x):˫�˶�����ĳһԪ��ǰ����n����ͬ��Ԫ��x

	void insert(iterator it,const_iterator first,const_iteratorlast):˫�˶�����ĳһԪ��ǰ������һ����ͬ����������[forst,last)�������

	(3)    ɾ������

	Iterator erase(iterator it):ɾ��˫�˶����е�ĳһ��Ԫ��

	Iterator erase(iterator first,iterator last):ɾ��˫�˶�����[first,last���е�Ԫ��

	void pop_front():ɾ��˫�˶�������ǰһ��Ԫ��

	void pop_back():ɾ��˫�˶��������һ��Ԫ��

	void clear():���˫�˶��������һ��Ԫ��

	(4)    ��������

	reference at(int pos):����posλ��Ԫ�ص�����

	reference front():������Ԫ�ص�����

	reference back():����βԪ�ص�����

	iterator begin():��������ͷָ�룬ָ���һ��Ԫ��

	iterator end():����ָ�����������һ��Ԫ����һ��Ԫ�ص�ָ�루�������������У�

	reverse_iterator rbegin():�����������ָ�����һ��Ԫ��

	reverse_iterator rend():�����������ָ���һ��Ԫ�ص�ǰһ��Ԫ��

	(5)    �жϺ���

	bool empty() const:�����Ƿ�Ϊ�գ���true,����������Ԫ��

	(6)    ��С����

	Int size() const:����������Ԫ�صĸ���

	int max_size() const:�������������˫�˶���Ԫ������ֵ

	(7)    ��������

	void swap(deque&):��������ͬ��������������

	void assign(int n,const T& x):�����е�n��Ԫ�ص�ֵ����Ϊx

	
	
3��#include<list>
	assign() ��list��ֵ 
	back() �������һ��Ԫ�� 
	begin() ����ָ���һ��Ԫ�صĵ����� 
	clear() ɾ������Ԫ�� 
	empty() ���list�ǿյ��򷵻�true 
	end() ����ĩβ�ĵ����� 
	erase() ɾ��һ��Ԫ�� 
	front() ���ص�һ��Ԫ�� 
	get_allocator() ����list�������� 
	insert() ����һ��Ԫ�ص�list�� 
	max_size() ����list�����ɵ����Ԫ������ 
	merge() �ϲ�����list 
	pop_back() ɾ�����һ��Ԫ�� 
	pop_front() ɾ����һ��Ԫ�� 
	push_back() ��list��ĩβ���һ��Ԫ�� 
	push_front() ��list��ͷ�����һ��Ԫ�� 
	rbegin() ����ָ���һ��Ԫ�ص���������� 
	remove() ��listɾ��Ԫ�� 
	remove_if() ��ָ������ɾ��Ԫ�� 
	rend() ָ��listĩβ����������� 
	resize() �ı�list�Ĵ�С 
	reverse() ��list��Ԫ�ص�ת 
	size() ����list�е�Ԫ�ظ��� 
	sort() ��list���� 
	splice() �ϲ�����list 
	swap() ��������list 
	unique() ɾ��list���ظ���Ԫ��
	
	
	
4��#include<stack>

	empty() ��ջΪ���򷵻���

	pop() �Ƴ�ջ��Ԫ��

	push() ��ջ������Ԫ��

	size() ����ջ��Ԫ����Ŀ

	top() ����ջ��Ԫ��
	
	
5��#include<queue>
	
	empty()  �ж϶����Ƿ�Ϊ��
	front()  ���ص�һ��Ԫ��
	back()   �������һ��Ԫ��
	push()   ��β��ѹ��Ԫ��
	pop()    ������һ��Ԫ��
	size()    ����Ԫ�ظ���

6��#include<queue>
	priority<int> M     (���ֵ���ȶ���)
	
	empty() �������Ϊ�շ�����

	pop() ɾ���Զ�Ԫ��

	push() ����һ��Ԫ��

	size() �������ȶ�����ӵ�е�Ԫ�ظ���

	top() �������ȶ��жԶ�Ԫ��
	��Ĭ�ϵ����ȶ����У����ȼ��ߵ��ȳ��ӡ���Ĭ�ϵ�int�����ȳ��ӵ�Ϊ�ϴ������
	