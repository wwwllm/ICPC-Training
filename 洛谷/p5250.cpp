/*
set<int>ds			:建立一个叫作bs的元素类型为int的集合
ds.insert(x)		:在集合中插入一个元素，如果这个元素存在，则什么也不干
ds.erase(x)			:在集合中删除一个元素，如果这个元素不存在，则什么也不干
ds.erasr(it)		:删除集合中地址为it的元素
ds.end()			:返回集合中最后元素的下一个元素的地址。不过这个很少直接使用，
					 而是配合其他方法进行比较，一确认某个元素是否存在。
ds.find(x)			:查询x在集合中的地址，如果这个数不存在，则返回ds.end()。
ds.lower_bound(x)	:查询不小于x的最小的数在集合中的地址，如果这个数不存在，则返回ds.end()。
ds.upper_bound(x)	:查询大于x的最小的数在集合中的地址，如果这个数不存在，则返回ds.end()。	
ds.empty()			:如果集合为空则返回1，否则返回0 。
ds.size()			:返回元素个数。	
*/
#include<bits/stdc++.h>
using namespace std;

int n,opt,lenth;
set<int>ds;
int main(){
	cin>>n;
	while(n--){
		cin>>opt>>lenth;
		if(opt==1){
			if(ds.find(lenth)!=ds.end())cout<<"Already Exist"<<endl;
			else	ds.insert(lenth);
		}
		else if(ds.empty())	
			cout<<"Empty"<<endl;
		else{
			set<int>::iterator i=ds.lower_bound(lenth),j=i;//iterator为迭代器 
			if(j!=ds.begin())--j;
			if(i!=ds.end()&&lenth-(*j)>(*i)-lenth)j=i;
			cout<<(*j)<<endl;
			ds.erase(j);
		}
	}
	return 0;
}   
