

#include <iostream>
#include <vector>
#include <queue>

void BFS(int G[7][7], int start, int n) {
	int i = start, j;
	std::vector<int> visited(n, 0);
	std::queue<int> q;
	std::cout << i << " ";
	visited[i] = 1;
	q.push(i);
	while (!q.empty()) {
		i = q.front();
		q.pop();
		for (j = 1; j < n; j++) {
			if (G[i][j] == 1 && visited[j] == 0) {
				std::cout << j << " ";
				visited[j] = 1;
				q.push(j);
			}
		}
	}
}

void DFS(int G[7][7], int start, int n) {
	int i = start, j;
	static std::vector<int> visited(n, 0);
	if (visited[i] == 0) {
		std::cout << i << " ";
		visited[i] = 1;
		for (j = 1; j < n; j++) {
			if (G[i][j] == 1 && visited[j] == 0) {
				DFS(G, j, n);
			}
		}
	}
}

int main()
{
	int G[7][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 1, 0, 1, 1},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0}
	};
	DFS(G, 1, 7);
	std::cout << std::endl;
	return 0;
}
