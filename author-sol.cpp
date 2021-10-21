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
		// find the no. of 1's at every position (use prefix sum)
		vector<int> pref(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + a[i];
		}
		// find the subarray of length 'k' with the minimum sum
		// we can see that for every operation, the chosen subarray can be used to transform
		// all the remaining ones one-by-one (either from current position to the left side or
		// current position to the right side)
		long long total_ones = pref[n];
		long long min_subarray = k;
		for (int i = k; i <= n; i++) {
			long long subarray = pref[i] - pref[i - k];
			min_subarray = min(min_subarray, subarray);
		}
		// to get the number of operations for the chosen subarray, we need to use the sum formula
		// and add it to the remaining 1's in the sequence after changing the subarray to all 0's
		long long res = min_subarray * (min_subarray + 1) / 2 + total_ones - min_subarray;
		cout << res << '\n';
	}
	return 0;
}
