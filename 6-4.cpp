#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int c, n, m, x, y;
bool areFriends[10][10];
bool taken[10];

int countPairings(bool taken[10]) {
	bool finished = true;
	for (int i = 0; i < n; i++) if (!taken[i]) finished = false;
	if (finished) return 1;
	int ret = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
	return ret;
}

int main()
{
	cin >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> n >> m;

		for (int j = 0; j < m; j++) {
			cin >> x >> y;
			areFriends[x][y] = 1;
			areFriends[y][x] = 1;
		}

		cout << countPairings(taken) << '\n';

		for (int j = 0; j < 10; j++) {
			taken[j] = 0;
			for (int k = 0; k < 10; k++) {
				areFriends[j][k] = 0;
			}
		}
	}

	return 0;
}
