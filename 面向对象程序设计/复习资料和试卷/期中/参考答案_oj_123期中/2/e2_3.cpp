#include <iostream>

#include <string>

using namespace std;

struct sct

{

    int times;

    char c;

};

int main()

{

    string str;

    while (cin >> str)

    {

        sct sig[1000];

        int count = 0;

        for (size_t i = 0; i < str.size(); i++)

        {

            char c = str[i];

            if (c == ' ')

                continue;

            //³õÊ¼»¯

            sig[count].c = c;

            sig[count].times = 1;

            str[i] = ' ';

            int pos = 0;

            while ((pos = str.find(c)) != -1)

            {

                sig[count].times++;

                str[pos] = ' ';

            }

            count++;

        }

        for (size_t i = 0; i < count - 1; i++)

        {

            int okay = 1;

            for (size_t j = 0; j < count - 1 - i; j++)

            {

                if (sig[j].times < sig[j + 1].times)

                {

                    int tpt = sig[j].times;

                    char tpc = sig[j].c;

                    sig[j].times = sig[j + 1].times;

                    sig[j].c = sig[j + 1].c;

                    sig[j + 1].times = tpt;

                    sig[j + 1].c = tpc;

                    okay = 0;

                }

                if (sig[j].times == sig[j + 1].times)

                    if (sig[j].c < sig[j + 1].c)

                    {

                        char tpc = sig[j].c;

                        sig[j].c = sig[j + 1].c;

                        sig[j + 1].c = tpc;

                        okay = 0;

                    }

            }

            if (okay)

                break;

        }

        for (size_t i = 0; i < count; i++)

            cout << sig[i].c << ':' << sig[i].times << ' ';

        cout << endl;

    }

    return 0;

}