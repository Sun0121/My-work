C++ 中的容器使用

1、#include<Vector>
	
	vector<int> c;

	c.clear()         移除容器中所有数据。

    c.empty()         判断容器是否为空。

    c.erase(pos)        删除pos位置的数据

    c.erase(beg,end) 删除[beg,end)区间的数据

    c.front()         传回第一个数据。

    c.insert(pos,elem)  在pos位置插入一个elem拷贝

    c.pop_back()     删除最后一个数据。

    c.push_back(elem) 在尾部加入一个数据。

    c.resize(num)     重新设置该容器的大小

    c.size()         回容器中实际数据的个数。

    c.begin()           返回指向容器第一个元素的迭代器

    c.end()             返回指向容器最后一个元素的迭代器

2、#include<deque>

	(1)    构造函数
	deque():创建一个空deque

	deque(int nSize):创建一个deque,元素个数为nSize

	deque(int nSize,const T& t):创建一个deque,元素个数为nSize,且值均为t

	deque(const deque &):复制构造函数

	(2)    增加函数

	void push_front(const T& x):双端队列头部增加一个元素X

	void push_back(const T& x):双端队列尾部增加一个元素x

	iterator insert(iterator it,const T& x):双端队列中某一元素前增加一个元素x

	void insert(iterator it,int n,const T& x):双端队列中某一元素前增加n个相同的元素x

	void insert(iterator it,const_iterator first,const_iteratorlast):双端队列中某一元素前插入另一个相同类型向量的[forst,last)间的数据

	(3)    删除函数

	Iterator erase(iterator it):删除双端队列中的某一个元素

	Iterator erase(iterator first,iterator last):删除双端队列中[first,last）中的元素

	void pop_front():删除双端队列中最前一个元素

	void pop_back():删除双端队列中最后一个元素

	void clear():清空双端队列中最后一个元素

	(4)    遍历函数

	reference at(int pos):返回pos位置元素的引用

	reference front():返回手元素的引用

	reference back():返回尾元素的引用

	iterator begin():返回向量头指针，指向第一个元素

	iterator end():返回指向向量中最后一个元素下一个元素的指针（不包含在向量中）

	reverse_iterator rbegin():反向迭代器，指向最后一个元素

	reverse_iterator rend():反向迭代器，指向第一个元素的前一个元素

	(5)    判断函数

	bool empty() const:向量是否为空，若true,则向量中无元素

	(6)    大小函数

	Int size() const:返回向量中元素的个数

	int max_size() const:返回最大可允许的双端对了元素数量值

	(7)    其他函数

	void swap(deque&):交换两个同类型向量的数据

	void assign(int n,const T& x):向量中第n个元素的值设置为x

	
	
3、#include<list>
	assign() 给list赋值 
	back() 返回最后一个元素 
	begin() 返回指向第一个元素的迭代器 
	clear() 删除所有元素 
	empty() 如果list是空的则返回true 
	end() 返回末尾的迭代器 
	erase() 删除一个元素 
	front() 返回第一个元素 
	get_allocator() 返回list的配置器 
	insert() 插入一个元素到list中 
	max_size() 返回list能容纳的最大元素数量 
	merge() 合并两个list 
	pop_back() 删除最后一个元素 
	pop_front() 删除第一个元素 
	push_back() 在list的末尾添加一个元素 
	push_front() 在list的头部添加一个元素 
	rbegin() 返回指向第一个元素的逆向迭代器 
	remove() 从list删除元素 
	remove_if() 按指定条件删除元素 
	rend() 指向list末尾的逆向迭代器 
	resize() 改变list的大小 
	reverse() 把list的元素倒转 
	size() 返回list中的元素个数 
	sort() 给list排序 
	splice() 合并两个list 
	swap() 交换两个list 
	unique() 删除list中重复的元素
	
	
	
4、#include<stack>

	empty() 堆栈为空则返回真

	pop() 移除栈顶元素

	push() 在栈顶增加元素

	size() 返回栈中元素数目

	top() 返回栈顶元素
	
	
5、#include<queue>
	
	empty()  判断队列是否为空
	front()  返回第一个元素
	back()   返回最后一个元素
	push()   从尾部压入元素
	pop()    弹出第一个元素
	size()    返回元素个数

6、#include<queue>
	priority<int> M     (最大值优先队列)
	
	empty() 如果队列为空返回真

	pop() 删除对顶元素

	push() 加入一个元素

	size() 返回优先队列中拥有的元素个数

	top() 返回优先队列对顶元素
	在默认的优先队列中，优先级高的先出队。在默认的int型中先出队的为较大的数。
	