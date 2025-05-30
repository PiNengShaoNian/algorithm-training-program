class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto check = [&](long long t) -> bool {
            long long cnt = 0;
            for (int period : time) {
                cnt += t / period;
            }
            return cnt >= totalTrips;
        };

        long long l = 1;
        long long r = (long long)totalTrips * *max_element(time.begin(), time.end());
        long long ans = r;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};