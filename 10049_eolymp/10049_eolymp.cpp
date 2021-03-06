#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <math.h>
using namespace std;

int height, width;
vector<vector<int>> bitmap;
vector<vector<int>> dist;
queue<pair<int, int>> q;

void add(const int &x, const int &y, const int &dist_x_y) {
	if (x < 0 || y < 0 || x >= height || y >= width) return;
	if (dist[x][y] != -1) return;
	q.push(make_pair(x, y));
	dist[x][y] = dist_x_y;
}

int main()
{
	int tests;
	cin >> tests;
	while (tests--) {
		cin >> height >> width;
		bitmap.resize(height);
		dist.resize(height);
		for (int i = 0; i < height; ++i) {
			string s;
			cin >> s;
			vector<int> tmp(width);
			dist[i] = tmp;
			for (int k = 0; k < width; ++k) {
				bitmap[i].push_back(s[k] - 48);
				if (bitmap[i][k] == 1) {
					q.push(make_pair(i, k));
					dist[i][k] = 0;
				}
				else dist[i][k] = -1;
			}
		}
		// bfs ----------------------------------
		int x, y;
		while (q.size() != 0) {
			pair<int, int> tmp = q.front();
			q.pop();
			x = tmp.first, y = tmp.second;
			add(x, y - 1, dist[x][y] + 1);
			add(x - 1, y, dist[x][y] + 1);
			add(x + 1, y, dist[x][y] + 1);
			add(x, y + 1, dist[x][y] + 1);
		}
		//----------------------------------------
		for (int j = 0; j < height; ++j) {
			for (int k = 0; k < width; ++k) cout << dist[j][k] << ' ';
			cout << endl;
		}
		// clear vectors--------------------------
		bitmap.clear();
		dist.clear();
	}
    return 0;
}

