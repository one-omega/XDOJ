#include <bits/stdc++.h>
using namespace std;
int visited[31];
vector<vector<int> > vec(31);
int cnt, sum;
int num[31];
inline dfs(int s) {
	visited[s] = 1;
	sum++;
	int len = vec[s].size();
	for (int i = 0; i < len; i++) {
		int e = vec[s][i];
		if (!visited[e]) {
			dfs(e);
		}
	}
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
    	int s,e;
    	scanf("%d %d",&s, &e);
    	vec[s].push_back(e);
    	vec[e].push_back(s);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
			num[cnt] = sum;
			sum = 0;
		}
	}
	printf("%d\n",cnt);
	sort(num+1,num+1+cnt);
	for (int i = 1; i <= cnt; i++) {
		printf("%d ",num[i]);
	}
    return 0;
}

