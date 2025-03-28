#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        LL k, m = -1, n = -1, best = -1;
        cin >> k;
        k = k * 2 - 1;

        for (LL i = 1; i * i * 2 < k; ++i)
        {
            if ((k - i) % (2 * i + 1) == 0)
            {
                LL j = (k - i) / (2 * i + 1);
                if (j < i)
                    break;
                if (best == -1 || best > j - i)
                {
                    best = j - i;
                    m = i;
                    n = j;
                }
            }
        }
        cout << m << " " << n << "\n";
    }
    return 0;
}