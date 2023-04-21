#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    string s;
    vector<vector<int>> ans;
    int n;

    fstream input;
    input.open("481(input).txt");
    fstream output;
    output.open("481(output).txt");

    input >> s;
    n = s.size();
    ans = vector<vector<int>>(n, vector<int>(n, 0));


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c = j + i;
            if (c == n)
            {
                break;
            }
            if (j == c)
            {
                ans[j][c] = 1;
            }
            else
            {
                if (s[j] != s[c])
                {
                    ans[j][c] = ans[j + 1][c] + ans[j][c - 1] - ans[j + 1][c - 1];
                }
                else
                {
                    ans[j][c] = ans[j + 1][c] + ans[j][c - 1] + 1;
                }
            }
        }
    }
    output << ans[0].back() << endl;

    input.close();
    output.close();


    return 0;
}