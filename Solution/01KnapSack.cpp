#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int T;
int N, K;
pair<int, int> WV[10001];
int value[501][100001];

void init() {
	memset(WV, 0, sizeof(WV));
}
void knapsack() {
	sort(WV, WV + N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (WV[i].first > j)
				value[i][j] = value[i - 1][j];
			else
				value[i][j] = max(value[i - 1][j], value[i - 1][j - WV[i].first] + WV[i].second);
		}
	}
	cout << value[N][K] << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin >> T;

	while (T--) {
		cin >> N >> K;

		init();
		
		for (int i = 1; i <= N; i++) {
			cin >> WV[i].first;
		}
		for (int i = 1; i <= N; i++) {
			cin >> WV[i].second;
		}
		knapsack();
	}
	return 0;
}