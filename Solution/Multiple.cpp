#include <iostream>
#include <string>
using namespace std;

int T;
string A;
int B;
int remain;

void Multiple()
{	
	remain = 0;
	int Asize = A.length();
	
	for (int i = 0; i < Asize; i++)
		remain = (remain * 10 + (int)A[i] - '0') % B;
	if (remain == 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		Multiple();
	}

	return 0;
}