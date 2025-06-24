class Solution {
public:
	bool isKMirror(long long n, int k) //checks if n is palindrome in base k.
	{
		stack<int> stk;
		int d = (int)(log2(n)/log2(k)) + 1; //finding number of digits in num when converted to base k.
		int odd = d%2;
		d /= 2;
		while(d--)
		{
			stk.push(n%k);
			n/=k;
		}
		if(odd)
		{
			n/=k;
		}
		while(n>0)
		{
			if(stk.top() != n%k) return false;
			n /= k;
			stk.pop();
		}
		if(stk.size() != 0) return 0;
		return 1;
	}
	string num;
	void updateNum() //updates the num to next lexicographically greater palindrome in decimal
	{
		int n = num.size(), i = (n-1)/2;
		int  j = i;
		if(num[i] != '9')
		{
			num[i] = (num[i] + 1);
			if(n%2 == 0)
			{
				num[i+1] = (num[i+1] + 1);
				j++;
			}
			return;
		}
        num[i] = '0';
        if(n%2 == 0)
        {
            num[i+1] = '0';
            j++;
        }
		j++;
		i--;
		while(i>=0)
		{
			if(num[i] != '9')
			{
				num[i] = (num[i] + 1);
				num[j] = (num[j] + 1);
				return;
			}
            else
            {
                num[i] = '0';
				num[j] = '0';
            }
			i--;
			j++;
		}
		if(i<0)
		{
			num[0] = '1';
			for(i = 1;i<n;i++)
			{
				num[i] = '0';
			}
			num.push_back('1');
		}
	}
    long long kMirror(int k, int n) 
    {
        long long ans = 0;
        num = "1";

        while(n>0)
        {
        	long long i = atol(num.c_str());
        	if(isKMirror(i,k)) 
            {
                ans += i;
                n--;
            }
            updateNum();
        }
        return ans;
    }
};