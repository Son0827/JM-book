#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int c, n, m, x, y;
bool areFriends[10][10];
bool taken[10];

int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[pairWith] = taken[firstFree] = 1;
			ret += countPairings(taken);
			taken[pairWith] = taken[firstFree] = 0;
		}
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
