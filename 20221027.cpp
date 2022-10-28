#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer{ 0, 0 };
    answer[0] = (brown + 4 + sqrt((brown - 4) * (brown - 4) - 16 * yellow)) / 4;
    answer[1] = (brown + 4 - sqrt((brown - 4) * (brown - 4) - 16 * yellow)) / 4;
    return answer;
}

int main() {
    int brown = 24;
    int yellow = 24;
    for (int i = 0; i < solution(brown, yellow).size(); i++) {
        cout << solution(brown, yellow)[i] << endl;
    }
}