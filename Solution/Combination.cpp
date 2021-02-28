#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int T;
int N;
vector<int> v;
int a, b, x;
long long sum;
int total;

void cntTotal() {
	sum = 0;
 	for (int i = 0; i < N; i++)
		sum += pow(x, i) * v[i];
	sum %= 1013;
	if (sum >= a && sum <= b)
		total++;
}
void Combination(int Start, int End) {
	if (Start == End) {
		cntTotal();
	}
	else {
		for (int i = Start; i <= End; i++) {
			swap(v[Start], v[i]);
			Combination(Start + 1, End);
			swap(v[Start], v[i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		total = 0;
		cin >> N;
		v.resize(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];

		cin >> a >> b >> x;

		Combination(0, N - 1);
		cout << total << "\n";
	}

	return 0;
}