template<class Key,class Elem>       //�ҵ�λ�ã�������ӦԪ��
bool Insert(const Key & k,const Elem & e)
{
	int home = h(k);    //h(k)Ϊ��ϣ�������ҵ�������׸�λ��
	int pos = home;
	int i = 1;
	while(HT[pos] != EMPTY)
	{
	  if(k = getKey(HT[pos]))
			return false;     //�����ظ�����
	  pos = (pos + p(k,i)) % M;  //p(k,i)Ϊ̽�⺯����MΪ��ϣ����
	  ++ i;
	}
	HT[pos] = e;
	return true;
}


template<class Key,class Elem>       //������ӦԪ��
bool Search(const Key & k,Elem & e)
{
	int home = h(k);    //h(k)Ϊ��ϣ�������ҵ�������׸�λ��
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
	else return false;     //���ݲ��ڱ���
}
