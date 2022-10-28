#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int num = 1;
    int size = s.size();

    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
    }
    cout << endl;

    if (s.back() == '(') {
        s.pop_back();
        return false;
    }
    
    else {
        s.pop_back();
        for (int i = 1; i < size; i++) {
            if (s.back() == '(') {
                cout << "s.back() = " << s.back() << endl;
                s.pop_back();
                num--;
                if (num < 0) {
                    break;
                }
                cout << "num = " << num << endl;
            }
            else if (s.back() == ')') {
                cout << "s.back() = " << s.back() << endl;
                s.pop_back();
                num++;
                cout << "num = " << num << endl;
            }
        }
    }

    if (num == 0) {
        return true;
    }
    else
        return false;

}

int main() {
    string s = "())()(()";
    cout << solution(s);
}