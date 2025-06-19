/*


Consider two points, p =(px,py) and q=(qx, qy. We consider the inversion or point reflection, r= (rx.ry), of point p across point q to be a 180 degrees rotation of point p around q.

Given n sets of points p and q, find r for each pair of points and print two space-separated integers denoting the respective values of rx and ry on a new line.

Function Description

Complete the findPoint function in the editor below.

findPoint has the following parameters:

int px, py, qx, qy: x and y coordinates for points p and q 
Returns

int[2]: x and y coordinates of the reflected point r
Input Format

The first line contains an integer, n, denoting the number of sets of points.
Each of the  subsequent lines contains four space-separated integers that describe the respective values of px, py, qx, and qy defining points p = (px,py) and q = (qx,qy).

Constraints

Sample Input

2
0 0 1 1
1 1 2 2
Sample Output

2 2
3 3

*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findPoint' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER px
 *  2. INTEGER py
 *  3. INTEGER qx
 *  4. INTEGER qy
 */

vector<int> findPoint(int px, int py, int qx, int qy) {

    /*
      180 degree reflection of point a = (x,y) around (0,0) is (-x,-y)
      to get reflection around another point c= (x', y') the steps are
      1. Subtract the point c from point a ( in this case  p-q)
      2. Rotate the result of step1 around  0 , 0 ( i.e. -(p-q) = q-p)
      3. Add point c back to result of step 2 (i.e. q-p+q => 2.q+p)
    */
    vector<int> point;
    point.push_back(2*qx-px);
    point.push_back(2*qy-py);
    return point;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int px = stoi(first_multiple_input[0]);

        int py = stoi(first_multiple_input[1]);

        int qx = stoi(first_multiple_input[2]);

        int qy = stoi(first_multiple_input[3]);

        vector<int> result = findPoint(px, py, qx, qy);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
