#include <iostream>
#include <string.h>
using namespace std;

int T;
int M, N;
int arr[101];
int score[100];
int a, b;
int total;
int totalScore;

void init() {
	memset(arr, 0, sizeof(arr));
	memset(score, 0, sizeof(score));
	totalScore = 0;
}
void sorting() {
	int start = 1;
	int	end = 1;
	for (int i = 2; i < M + 1; i++) {
		if (arr[end] < arr[i]) {
			end++;
			if (end == M) {
				total = end - start;
				totalScore += score[total];
			}
		}
		else {
			total = end - start;
			start = i;
			end = i;
			totalScore += score[total];
			if (i == M) {
				totalScore += score[0];
			}
		}
	}
	cout << totalScore << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;

	while (T--) {
		init();
		cin >> M >> N;

		for (int i = 0; i < M; i++) {
			cin >> score[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			arr[b] = a;
		}
		sorting();
	}


	return 0;
}