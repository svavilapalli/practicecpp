/*
Martha is interviewing at Subway. One of the rounds of the interview requires her to cut a bread of size l x b into smaller identical pieces such that each piece is a square having maximum possible side length with no left over piece of bread.

Input Format

The first line contains an integer T. T lines follow. Each line contains two space separated integers l and b which denote length and breadth of the bread.

Constraints
1 <= T, l, b <= 1000

Output Format

T lines, each containing an integer that denotes the number of squares of maximum size, when the bread is cut as per the given condition.

Sample Input 0

2
2 2
6 9
Sample Output 0

1
6
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'restaurant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER b
 */

int restaurant(int l, int b) {
    int s = min(l,b);
    long a =l*b;
    if (l == b) 
        return  1;
    for (int i=s; i>0; i--){
        if (l%i != 0)
            continue;
        if (b%i != 0)
            continue;
        long sq =i*i;
        if (a%sq == 0)
            return a/sq;
    }
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        int result = restaurant(l, b);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
