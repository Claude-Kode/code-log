#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
int a[1010][1010];
int fan[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool mark;
bool sti[1010][1010];
void dfs(int x,int y,const int& mid) {
	if(mark){
		//TODO
		return;
	}
	if (x>n||x<1||y>n||y<1) return;
	if (a[x][y] > mid) return;
	if (x==n) {
		mark = 1;
		return;
	}
	if (sti[x][y] == 0) {
		sti[x][y] = 1;
		for (int i=0;i<4;i++) {
			int as = x+fan[i][0];
			int bs = y+fan[i][1];
			dfs(as,bs,mid);
		}
	}
	
}
signed main () {
	std::ios::sync_with_stdio(false);
	cin. tie(0),cout. tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	int l=0;
	int r=1000;
	int ans = -1;
	while (l<=r) {
		memset(sti,0,sizeof(sti));
		int mid = l+r>>1;
		mark = 0;
		for (int i=1;i<=n;i++) {
			dfs(1,i,mid);
		}
		if (mark) {
			r = mid-1;
			ans = mid;
		} else {
			l = mid+1;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}