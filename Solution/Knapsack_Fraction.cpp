#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int T;
int N, K;
int W[10000];
int V[10000];
int VW[10000];
int idx[10000];
int value;
int weight;

void init() {
	memset(W, 0, sizeof(W));
	memset(V, 0, sizeof(V));
	memset(VW, 0, sizeof(VW));
	memset(idx, 0, sizeof(idx));
	value = 0;
	weight = 0;
}
void knapsack() {
	for (int i = 0; i < N; i++) {
		VW[i] = V[i] / W[i];
		idx[i] = VW[i];
	}
	sort(idx, idx + N, greater<int>());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (idx[i] == VW[j]) {
				if (K - weight <= 0)
					break;
				if (K - weight > W[j]) {
					weight += W[j];
					value += V[j];
				}
				else {
					value += VW[j] * (K - weight);
					weight = K;
					break;
				}
				VW[j] = 0;
			}
		}
	}
	cout << value << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin >> T;

	while (T--) {
		cin >> N >> K;

		init();
		for (int i = 0; i < N; i++) {
			cin >> W[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> V[i];
		}
		knapsack();
	}
	return 0;
}