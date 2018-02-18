template<class Key,class Elem>       //找到位置，插入相应元素
bool Insert(const Key & k,const Elem & e)
{
	int home = h(k);    //h(k)为哈希函数，找到插入的首个位置
	int pos = home;
	int i = 1;
	while(HT[pos] != EMPTY)
	{
	  if(k = getKey(HT[pos]))
			return false;     //数据重复插入
	  pos = (pos + p(k,i)) % M;  //p(k,i)为探测函数，M为哈希表长度
	  ++ i;
	}
	HT[pos] = e;
	return true;
}


template<class Key,class Elem>       //查找相应元素
bool Search(const Key & k,Elem & e)
{
	int home = h(k);    //h(k)为哈希函数，找到插入的首个位置
	int pos = home;
	int i = 1;
	while(getKey(HT[pos]) != k && HT[pos] != EMPTY)
	{
	  pos = (pos + p(k,i))%M;
	  if(k == getKey(HT[pos]))         //found it
	  {
			e = Ht[pos];
			return true;
	  }
	}
	else return false;     //数据不在表中
}
