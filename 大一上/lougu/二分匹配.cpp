//二分匹配（匈牙利算法） 
//寻找二分图中最多可以匹配多少对
//匹配对数=所有线段被关联的最少点数 
#include<bits/stdc++.h>
using namespace std;

const int MAXN=520;
int un,vn;//un存储男生人数，vn存储女生 
int g[MAXN][MAXN];//构造图 
int linker[MAXN];//存储女生对象 
bool used[MAXN];//存储女生是否有对象 
bool dfs(int u){//搜索到第u个男生 
	for(int v=0;v<vn;v++){
		if(g[u][v]&&!used[v]){
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
} 
int hungary(){
	int res=0;
	memset(linker,-1,sizeof(linker));
	for(int u=0;u<un;u++){
		memset(used,false,sizeof (used));//重置 
		if(dfs(u)res++;
	}
	return res;
}
int main(){
	int k;
	while(cin>>un==1&&un){
		cin>>vn>>k;
		memset(g,0,sizeof(g));
		int id,u,v;
		while(k--){
			cin>>id>>u>>v;
			if(u!=0&&v!=0){
				g[u][v]=1;
			}
			cout<<hungary();
		}
	}
	return 0;
}
