#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int M, N;
char o;
int x, y, s, e;
vector <pair<int, int>> v[26];
int use[100 * 100];
int dis, fidx, sidx;
bool back;

int distance(pair<int, int> a, pair<int, int> b) {
	int dy = abs(a.first - b.first);
	int dx = abs(a.second - b.second);

	return dy * dy + dx * dx;
}
void print(int i, int fidx, int sidx) {
	cout << char('A' + i);
	cout << " " << v[i][fidx].second << " " << v[i][fidx].first;
	cout << " " << v[i][sidx].second << " " << v[i][sidx].first;
	cout << "\n";
}
void Card() {
	for (int i = 0; i < 26; i++) {
		if (v[i].empty())
			continue;
		sort(v[i].begin(), v[i].end());
		s = 0; e = 1; dis = 20000;
		memset(use, 0, sizeof(use));
		while (s < v[i].size() - 1) {
			while (e < v[i].size()) {
				if (use[s] == 0 && use[e] == 0
					&& (v[i][s].first != v[i][e].first || v[i][s].second != v[i][e].second)) {
					int temp = distance(v[i][s], v[i][e]);
					if (dis > temp) {
						dis = temp;
						fidx = s;
						sidx = e;
					}
					if (dis == temp) {
						if (v[i][s].first + v[i][e].first < v[i][fidx].first + v[i][sidx].first) {
							fidx = s;
							sidx = e;
						}
						else if (v[i][s].first + v[i][e].first == v[i][fidx].first + v[i][sidx].first) {
							if (v[i][s].second + v[i][e].second < v[i][fidx].second + v[i][sidx].second) {
								fidx = s;
								sidx = e;
							}
						}
					}
				}
				e++;
			}
			s++;
			e = s + 1;
			if (e == v[i].size()) {
				if (use[fidx] == 0 && use[sidx] == 0) {
					print(i, fidx, sidx);
					use[fidx]++;
					use[sidx]++;
				}
				dis = 20000;
				back = false;
				for (int j = 0; j < v[i].size(); j++) {
					if (use[j] == 0) {
						back = true;
						break;
					}
				}
				if (back == true) {
					s = 0;
					e = 1;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> T;

	while (T--) {
		for (int i = 0; i < 26; i++) {
			v[i].clear();
		}
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> o >> x >> y;
			v[o - 'A'].push_back({ y, x });
		}
		Card();
	}

	return 0;
}