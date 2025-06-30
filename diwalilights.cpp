/*
On the eve of Diwali, Hari is decorating his house with a serial light bulb set. The serial light bulb set has N bulbs placed sequentially on a string which is programmed to change patterns every second. If at least one bulb in the set is on at any given instant of time, how many different patterns of light can the serial light bulb set produce?

Note: Lighting two bulbs *-* is different from **-

Input Format
The first line contains the number of test cases T, T lines follow.
Each line contains an integer N, the number of bulbs in the serial light bulb set.

Output Format
Print the total number of patterns modulo 105

Constraints
1 <= T <= 1000
0< N < 104

Sample Input

2
1
2
Sample Output

1
3
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'lights' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER n as parameter.
 */

long lights(int n) {
  /*
  solution is 2^n -1, however, the value can be so high, beyond the limit of long. Hence, it need to be calculated iteratively
    */
    long res = 1;
    for(int i =0; i< n; i++)
    {
        res *= 2;
        res = res% 100000;
    }
    return res - 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        long result = lights(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
