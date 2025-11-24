#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		int len[1005] = { 0 };
		for (size_t i = 0; i < N; i++)
			cin >> len[i];

		if (N < 3)
		{
			cout << -1 << endl;
			continue;
		}


		for (size_t i = 0; i < N - 1; i++)
		{
			int okay = 1;
			for (size_t j = 0; j < N - 1 - i; j++)
			{
				if (len[j] < len[j + 1])
				{
					int temp = len[j];
					len[j] = len[j + 1];
					len[j + 1] = temp;
					okay = 0;
				}
			}
			if (okay)
				break;
		}

		bool no = true;
		int a, b, c;
		for (size_t i = 0; i < N - 2; i++)
		{
			a = len[i];
			for (size_t j = i + 1; j < N - 1; j++)
			{
				b = len[j];
				for (size_t k = j + 1; k < N; k++)
				{
					c = len[k];
					if (c + b > a)
					{
						no = false;
						goto end;
					}
				}
			}
		}
	end:
		if (no)
			cout << -1 << endl;
		else
			cout << a + b + c << endl;
	}


	return 0;
}