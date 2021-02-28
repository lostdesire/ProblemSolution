#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int n, L, k;
vector<int> ball;

void find() {
	sort(ball.begin(), ball.end());
	cout << ball[k-1] << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin >> T;

	while (T--) {
		ball.clear();
		cin >> n >> L >> k;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a < 0)
				ball.push_back(abs(a));
			else
				ball.push_back(L - a);
		}
		find();
	}


	return 0;
}