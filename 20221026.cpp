#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string str) {
    vector<int> v;
    string answer = "";
    istringstream ss(str);
    string stringBuffer;

    while (getline(ss, stringBuffer, ' ')) {
        v.push_back(stoi(stringBuffer));
    }

    sort(v.begin(), v.end());
    answer = to_string(v.front()) + " " + to_string(v.back());

    return answer;
}

int main() {
    string str = "1 2 3 4";
    cout << solution(str);
}