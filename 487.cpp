#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{

	ifstream input;
	input.open("487(input).txt");
	ofstream output;
	output.open("487(output).txt");

	int n, k, p;
	input >> n >> k >> p;

	while (p--)
	{
		int x;
		input >> x;
		int q = n - x;
		if (q % (k + 1) == 0)
		{
			output << "T" << endl;
		}
		else
		{
			output << "F" << endl;
		}
	}

	return 0;
}