/*
Akash and Akhil are playing a game. They have N balls numbered from 0 to N-1. Akhil asks Akash to reverse the position of the balls, i.e., to change the order from say, 0,1,2,3 to 3,2,1,0. 
He further asks Akash to reverse the position of the balls N times, each time starting from one position further to the right, till he reaches the last ball. So, Akash has to reverse the positions of the ball 
starting from oth position, then from 1st position, then from 2nd position and so on. At the end of the game, Akhil will ask Akash the final position of any ball numbered K. Akash will win the game, if he can answer. Help Akash.

Input Format
The first line contains an integer T, i.e., the number of the test cases.
The next T lines will contain two integers N and K.

Output Format
Print the final index of ball K in the array.

Constraints
1<= T <= 50
1<= N <= 10^5
0 <= K < N


Sample Input

2
3 1
5 2
Sample Output

2
4
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int reversegame(int n, int k)
{
    int pos, mid;
    mid =  ((n%2 == 0)? n/2-1:n/2);
    if (k == mid)
        pos = n-1;
    else
    {
        pos = (n-1)-abs(mid-k)*2;
        if (((k< mid) and (n%2 == 1)) or ((k> mid) and (n%2 == 0)))
            pos += 1;
    } 
    return pos;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);
    ofstream fout(getenv("OUTPUT_PATH"));
    int t = stoi(ltrim(rtrim(t_temp)));
    for (int i= 0; i< t; i++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        
        int pos = reversegame(n, k);
        fout << pos << "\n";
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
