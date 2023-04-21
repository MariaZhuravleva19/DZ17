#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{

    ifstream input;
    input.open("683(input).txt");
    ofstream output;
    output.open("683(output).txt");

    int n;
    input >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        input >> a[i];
    }
    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 2; i <= n; i++)
    {
        for (int left = 0; left + i - 1 < n; left++)
        {
            int right = left + i - 1;
            if (i == 2)
            {
                ans[left][right] = 0;
            }
            else
            {
                ans[left][right] = 2000 * 1000 + 1;
                for (int mid = left + 1; mid <= right - 1; mid++)
                {
                    ans[left][right] = min(ans[left][right], a[mid] * (a[left] + a[right]) + ans[left][mid] + ans[mid][right]);
                }

            }
        }

    }

    output << ans[0][n - 1] << endl;
    return 0;
}