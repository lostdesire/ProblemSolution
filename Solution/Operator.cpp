#include <iostream>
#include <vector>
#define SUM 0
#define MUL 1
using namespace std;

int M, N;
vector<int> Answer;
int B[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
vector<int> in;
vector<int> v;

void calc(int oper) 
{
	vector<int> op(N - 1);
	for (int i = 0; i < N - 1; i++) 
	{
		op[i] = (oper & B[i]) / B[i];
	}
	vector<bool> usedOP(N - 1, false);
	vector<bool> usedN(N, false);

	for (int i = 0; i < N - 1; i++) 
	{
		if (!usedOP[i] && op[i] == MUL) 
		{
			usedOP[i] = true;
			int left = i;
			int right = i + 1;
			while (usedN[left]) 
				left--;
			usedN[right] = true;
			v[left] = v[left] * v[right];
		}
	}
	for (int i = 0; i < N - 1; i++) 
	{
		if (!usedOP[i] && op[i] == SUM) 
		{
			usedOP[i] = true;
			int left = i;
			int right = i + 1;
			while (usedN[left]) 
				left--;
			usedN[right] = true;
			v[left] = v[left] + v[right];
		}
	}
}

void solution() 
{
	for (int i = 0; i < B[N - 1]; i++) 
	{
		v = in;
		calc(i);
		if (v[0] == v[N]) 
		{
			Answer.push_back(1);
			return;
		}
	}
	Answer.push_back(0);
}

int main() 
{
	ios_base::sync_with_stdio(false);
	
	int T;

	cin >> T;

	while(T--) 
	{
		cin >> M >> N;
		Answer.clear();
		in.resize(N + 1);
		v.resize(N + 1);
		for (int i = 0; i < M; i++) 
		{
			for (int j = 0; j < N + 1; j++) 
			{
				cin >> in[j];
			}
			solution();
		}
		for (int i = 0; i < Answer.size(); i++) 
		{
			cout << Answer[i] << " ";
		}
		cout << '\n';
	}

	return 0;
}