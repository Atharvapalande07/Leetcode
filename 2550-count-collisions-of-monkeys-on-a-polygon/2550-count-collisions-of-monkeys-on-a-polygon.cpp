class Solution {
     typedef long long ll;
     ll mod = 1e9 + 7;
     ll calculate_power(ll n)
     {
        if(n == 0)
        return 1;

        ll val = n;

        ll base = 2;
        ll res = 1;

        while(val)
        {
            if(val&1)
            {
                res = (res * base)%mod;
            }
            base = (base * base)%mod;
            val = val >> 1;
        }
        return res;
     }
public:
    int monkeyMove(int n) {
        ll xy = calculate_power(n);
       
        return xy - 2 >=0 ? xy - 2: mod + (xy - 2);
        
    }
};