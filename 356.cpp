#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Coin
{
    int value;
    int weight;
};

bool cmp(const Coin& a, const Coin& b)
{
    return a.value > b.value;
}

int main()
{
    ifstream input;
    input.open("356(input).txt");
    ofstream output;
    output.open("356(output).txt");

    int E, F, N;
    input >> E >> F >> N;

    vector<Coin> coins(N);

    for (int i = 0; i < N; i++)
    {
        input >> coins[i].value >> coins[i].weight;
    }

    sort(coins.begin(), coins.end(), cmp);

    vector<int> vec(F - E + 1, -1);
    vec[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = coins[i].weight; j <= F - E; j++)
        {
            if (vec[j - coins[i].weight] != -1)
            {
                if (vec[j] == -1 || vec[j] > vec[j - coins[i].weight] + coins[i].value)
                {
                    vec[j] = vec[j - coins[i].weight] + coins[i].value;
                }
            }
        }
    }

    int min_sum = vec[F - E];

    if (min_sum == -1)
    {
        cout << "This is impossible." << endl;
        return 0;
    }

    vec.assign(F - E + 1, -1);

    vec[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = coins[i].weight; j <= F - E; j++)
        {
            if (vec[j - coins[i].weight] != -1)
            {
                if (vec[j] == -1 || vec[j] < vec[j - coins[i].weight] + coins[i].value)
                {
                    vec[j] = vec[j - coins[i].weight] + coins[i].value;
                }
            }
        }
    }

    int max_sum = vec[F - E];

    if (max_sum == -1)
    {
        output << "This is impossible." << endl;
        return 0;
    }

    output << min_sum << " " << max_sum << endl;

    input.close();
    output.close();

    return 0;
}