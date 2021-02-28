#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

int T;
int N;
int cost[1000], package[1000];
int product, sub;
int parent[1001], treesize[1001];

struct edge {
	int start;
	int end;
	int weight;
};

vector <edge> v;

void init() {
	v.clear();
	memset(cost, 0, sizeof(cost));
	memset(package, 0, sizeof(package));
	memset(parent, 0, sizeof(parent));
	memset(treesize, 0, sizeof(treesize));
}

bool cmp(edge a, edge b) {
	return a.weight < b.weight;
}
int find(int root) {
	if (parent[root] == root)
		return root;
	else
		return find(parent[root]);
}
void update(int a, int b) {
	if (treesize[a] < treesize[b]) {
		parent[a] = b;
		treesize[b] += treesize[a];
	}
	else {
		parent[b] = a;
		treesize[a] += treesize[b];
	}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("sample-Shopping.txt", "r", stdin);
	cin >> T;

	while (T--) {
		product = 0;
		sub = 0;
		init();

		cin >> N;
		for (int i = 1; i <= N + 1; i++) {
			parent[i] = i;
			treesize[i] = 1;
		}
		for (int i = 1; i <= N; i++) {
			cin >> cost[i] >> package[i];
			product += cost[i];
			edge e;
			e.start = i;
			e.end = N + 1;
			e.weight = cost[i];
			v.push_back(e);
			if (i > 1) {
				e.start = i - 1;
				e.end = i;
				e.weight = package[i];
				v.push_back(e);
			}
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++) {
			edge e = v[i];
			int a = find(e.start);
			int b = find(e.end);
			if(a != b){
				update(a, b);
				sub += e.weight;
			}
		}
		cout << product + sub << "\n";
	}
	return 0;
}