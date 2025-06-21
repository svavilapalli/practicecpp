/*
Leonardo loves primes and created q queries where each query takes the form of an integer, n. For each n, count the maximum number of distinct prime factors of any number in the inclusive range [1, n].

Note: Recall that a prime number is only divisible by 1 and itself, and 1 is not a prime number.

Example

The maximum number of distinct prime factors for values less than or equal to 100 is 3. One value with 3 distinct prime factors is 30. Another is 42.

Function Description

Complete the primeCount function in the editor below.

primeCount has the following parameters:

int n: the inclusive limit of the range to check
Returns

int: the maximum number of distinct prime factors of any number in the inclusive range [0 - n].
Input Format

The first line contains an integer, q, the number of queries.
Each of the next q lines contains a single integer, n.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */
bool isPrime(long  n){
    if (n == 2)
        return true;
    if (n==3)
        return true;
    for (long i= 3; i*i<=n+1;i+=2){
        if (n%i == 0)
            return  false;
    }
    return true;
}
int primeCount(long n) {
    if (n <=1)
        return 0;
    if (n<=5)
        return 1;
    long val = 2;
    int count = 1;
    for (long i =3;val*i<=n;i = i+2){
        if (isPrime(i)){
            val = (long)( val*i);

            if (val>n)
                return count;
            else if(val == n)
                return count+1;
            if (val <0)
                break;
            count++;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));
    // long val =2;
    //     for (int i = 3; i<=60; i+=2){
    //         if(isPrime(i)){
    //             val =val*i;
    //             fout<<" prime " << i << " " << val <<"\n";
    //         }
    //     }
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));
        

        int result = primeCount(n);

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
