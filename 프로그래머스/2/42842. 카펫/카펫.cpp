#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int carpet_size = brown + yellow;
    
    for (int i = 1; i <= sqrt(carpet_size); i++) {
        if (carpet_size % i == 0) {
            if ((i - 2) * (carpet_size / i - 2) == yellow) {
                answer.push_back(carpet_size / i);
                answer.push_back(i);
            }
        }
    }
    
    return answer;
}