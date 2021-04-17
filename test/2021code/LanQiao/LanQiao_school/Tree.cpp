//http://lx.lanqiao.cn/problem.page?gpid=T282
#include<iostream>
using namespace std;

int n,m;
int A[1000];
int visited[1000];
int final[1000];
int total = 0;
int x_max = -100000;

void getmax(int t){
	if(t > x_max){
		x_max = t;	
	}
}

int dfs(int goal, int w)
{
	if(goal == m+1){
		int t = 0; 
		for(int j=1; j<=m; j++){
			t += final[j];
		}
		getmax(t);
		return 0;
	}
	else if(w > n){
		return 0;
	}
	else{
		for(int i=w; i<=n; i++){
			if(visited[i] <= 0){
				visited[i] ++;
				if(i-1 == 0){
					visited[n] ++;
				}
				else
					visited[i-1] ++;
				if(i+1 == n+1){
					visited[1] ++;
				}
				else
					visited[i+1] ++;
				final[goal] = A[i];
				dfs(goal + 1, w + 2);
				visited[i] --;
				if(i-1 == 0){
					visited[n] --;
				}
				else
					visited[i-1] --;
				if(i+1 == n+1){
					visited[1] --;
				}
				else
					visited[i+1] --;
				dfs(goal, w + 1);
			} 
		}		
	}
	return 0;	
}
int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		int aa;
		cin>>aa;
		A[i] = aa;
	}
	dfs(1, 1);
	if(x_max == -100){
		cout<<"Error!";
	}
	else
		cout<<x_max;
	return 0;
}