#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int T;
int S[10000];
int f, l;
char fs, ls;

void palindrome(int S[10000], int size)
{
	f = 0;
	l = size - 1;

	while (f <= l + 1)
	{
		while (S[f] < 'A' || (S[f] > 'Z' && S[f] < 'a') || S[f] > 'z')
			f++;
		while (S[l] < 'A' || (S[l] > 'Z' && S[l] < 'a') || S[l] > 'z')
			l--;
		if (f < l)
		{
			if (S[f] >= 97)
				S[f] = S[f] - 32;
			if (S[l] >= 97)
				S[l] = S[l] - 32;
			if (S[f] != S[l])
			{
				cout << "No" << "\n";
				return;
			}
			else
			{
				f++;
				l--;
			}
		}
		else
		{
			cout << "Yes" << "\n";
			return;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	string s;
	int size;

	cin >> T;

	while(T--)
	{
		memset(S, 0, sizeof(S));
		cin >> s;
		size = s.length();
		for (int i = 0; i < size; i++)
		{
			S[i] = s[i];
		}
		palindrome(S, size);
	}

	return 0;
}