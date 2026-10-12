class Solution {
public:
    typedef long long ll;
    void getbitcnt(ll num, vector<ll>&bitcount) {
        if (num == 0)
            return;
        if (num == 1) {
            bitcount[0] += 1;
            return;
        }
        if (num == 2) {
            bitcount[0] += 1;
            bitcount[1] += 1;
            return;
        }

        ll bitlen = log2(num);
        ll nearPower2 = 1ll << (bitlen);
        bitcount[bitlen] += (num - nearPower2 + 1);

        for (ll i = 0; i < bitlen; i++) {
            bitcount[i] += nearPower2 / 2;
        }

        num = num - nearPower2;
        getbitcnt(num,bitcount);
    }

    long long findMaximumNumber(long long k, int x) {
        ll result = 0;
        ll left = 1;
        ll right = 1e15;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            vector<ll>bitcount(65,0);
            getbitcnt(mid,bitcount);

            ll totalPrice = 0;
            for (ll i = 0; i < log2(mid) + 1; i++) {
                if ((i + 1) % x == 0) {
                    totalPrice += bitcount[i];
                }
            }
            if (totalPrice <= k) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};