class Solution {
public:
	long long myPow(long long x, int n, int mod) {
		long long ans = 1;
		while (n) {
			if (n & 1) {
				ans = ans * x % mod;
			}

			x = x * x % mod;
			n >>= 1;
		}

		return ans;
	}

	int check(vector<int>& nums1, vector<int>& nums2, int len) {
		if (!len) return false;
		const int mod = 1000000009;
		const int base = 113;
		const int n = nums1.size();
		const int m = nums2.size();
		long long p13331 = myPow(base, len - 1, mod);
		set<long long> hashBuckets1;

		long long hash1 = 0;
		for (int i = 0; i < len; ++i) {
			hash1 = (hash1 * base + nums1[i]) % mod;;
		}

		hashBuckets1.insert(hash1);

		for (int i = len; i < n; ++i) {
			hash1 = ((hash1 - nums1[i - len] * p13331 % mod + mod) % mod * base + nums1[i]) % mod;
			hashBuckets1.insert(hash1);
		}

		long long hash2 = 0;

		for (int i = 0; i < len; ++i) {
			hash2 = (hash2 * base + nums2[i]) % mod;
		}

		if (hashBuckets1.count(hash2)) return true;


		for (int i = len; i < m; ++i) {
			hash2 = ((hash2 - nums2[i - len] * p13331 % mod + mod) % mod * base + nums2[i]) % mod;
			if (hashBuckets1.count(hash2)) return true;
		}

		return false;
	}

	int findLength(vector<int>& nums1, vector<int>& nums2) {
		int l = 1;
		int r = min(nums1.size(), nums2.size());
		int ans = 0;
		while (l <= r) {
			int mid = l + ((r - l) >> 1);
			if (check(nums1, nums2, mid)) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		return ans;
	}
};
