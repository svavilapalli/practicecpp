A person is getting ready to leave and needs a pair of matching socks. If there are  colors of socks in the drawer, how many socks need to be removed to be certain of having a matching pair?

Example 

/*
A person is getting ready to leave and needs a pair of matching socks. If there are m colors of socks in the drawer, how many socks need to be removed to be certain of having a matching pair?

Example = 2
There are 2 colors of socks in the drawer. If they remove 2 socks, they may not match. The minimum number to insure success is 3.

Function Description

Complete the maximumDraws function in the editor below.

maximumDraws has the following parameter:

int n: the number of colors of socks
Returns

int: the minimum number of socks to remove to guarantee a matching pair.
Input Format
The first line contains the number of test cases, t.
Each of the following t lines contains an integer n.

Constraints
1<= t<= 1000
0<n<10**6

Sample Input

2
1
2
Sample Output

2
3
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maximumDraws' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int maximumDraws(int n) {
    return n+1;
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

        int result = maximumDraws(n);

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
