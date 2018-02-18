#include <iostream>
#include <cstring>
#include <queue>
#define N 550
using namespace std;
int sx, sy, ex, ey, n, m;
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };
int vis[N][N];
int bfs() {
	pair<int, int> end(ex, ey);
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(sx, sy), 0));
	while (!q.empty()) {
		pair<int, int> p = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (p == end) return cnt;
		for (int i = 0; i < 8; ++i) {
			int _x = p.first + dx[i];
			int _y = p.second + dy[i];
			if (_x < 1 || _y < 1 || _x > m || _y >n || vis[_x][_y])
				continue;
			vis[_x][_y] = 1;
			q.push(make_pair(make_pair(_x, _y), cnt + 1));
		}
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		cin >> m >> n;
		cin >> sx >> sy >> ex >> ey;
		cout << bfs() << endl;
	}
	return 0;
}