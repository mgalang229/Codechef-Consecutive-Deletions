#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		// find the no. of 1s at every position (prefix sum)
		vector<int> pref(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + a[i];
		}
		// find a subarray with length 'k' that has the minimum sum
		// using this subarray, we can change all the remaining 1s (one-by-one), either
		// that 1 will be on the leftmost or rightmost position of the subarray
		int total_ones = pref[n];
		int min_subarray = k;
		for (int i = k; i <= n; i++) {
			int cur = pref[i] - pref[i - k];
			min_subarray = min(min_subarray, cur);
		}
		// to get the answer, calculate the sum of the subarray that we've chosen and all the remaining ones
		cout << ((min_subarray * (min_subarray + 1)) / 2) + (total_ones - min_subarray) << '\n';
	}
	return 0;
}
