#include <iostream>
#include <string.h>
#include <string>
#pragma warning(disable:4996)
using namespace std;

int T;
int LCS[1001][1001];
string A, B;

int main() {
	ios::sync_with_stdio(false);
	freopen("sample-LCS.txt", "r", stdin);
	cin >> T;

	while (T--) {
		cin >> A >> B;
		for (int i = 1; i <= A.size(); i++) {
			for (int j = 1; j <= B.size(); j++) {
				if (A[i - 1] == B[j - 1])
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else
					LCS[i][j] = LCS[i - 1][j] >= LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
			}
		}
		cout << LCS[A.size()][B.size()] << "\n";
	}

	return 0;
}