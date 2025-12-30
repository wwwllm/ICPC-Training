//队列,数组 
#include<bits/stdc++.h>
using namespace std;

int n,m;
queue<int>Q;
vector<int> P(0,0);
bool chazhao(int x){
	int len=P.size();
	if(len>=m){
		for(int i=len-m;i<len;i++){
			if(P[i]==x)return true;
		}
		return false;
	}
	else{
		for(int i=0;i<len;i++){
			if(P[i]==x)return true;
		}
		return false;
	}
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		Q.push(k);
	}
	while(!Q.empty()){
		int q=Q.front();
		Q.pop();
		if(chazhao(q))continue;
		else{
			P.push_back(q);
		}
	}
	cout<<P.size();
	return 0;
} 
