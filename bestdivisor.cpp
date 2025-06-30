/*
Kristen loves playing with and comparing numbers. She thinks that if she takes two different positive numbers, the one whose digits sum to a larger number is better than the other. If the sum of digits is equal for both numbers, then she thinks the smaller number is better. For example, Kristen thinks that 13 is better than 31 and that 12 is better than 11.

Given an integer, n, can you find the divisor of n that Kristin will consider to be the best?

Input Format

A single integer denoting n.

Constraints
0< n < 10^5
Output Format

Print an integer denoting the best divisor of n.
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int sumdigits(int  n){
    int  sum = 0;
    while(n>0){
        sum  = sum + (n%10);
        n = n/10;
    }
    return sum;
}

int  bestdivisor(int  n)
{
    int  best = 0, bestsum = 0;
    if(n==1) 
        return 1;
    for(int  i = 1; i<=n/2; i++){
        if(n%i == 0){
            int  d= n/i;
            int  sum1, sum2;
            sum1 = sumdigits(i);
            sum2 = sumdigits(d);
            if (sum1 > bestsum)
            {
                bestsum = sum1;
                best = i;
            }
            else if (sum1== bestsum){
                if (best > i)
                    best = i;
            }
            if(sum2 > bestsum)
            {
                bestsum = sum2;
                best = d;
            }
            else if(sum2 == bestsum)
            {
                if(best > d)
                    best = d;
            }
        }
    }
    return best;   
}

int main()
{
    string n_temp;
    getline(cin, n_temp);
    ofstream fout(getenv("OUTPUT_PATH"));
    int  n = stoi(ltrim(rtrim(n_temp)));

    int  d = bestdivisor(n);
    fout << d << "\n";
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
