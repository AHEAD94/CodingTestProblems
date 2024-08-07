#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

template<class T>
void PrintContainer(const T& container_begin, const T& container_end) {
    for (auto iter = container_begin; iter != container_end; iter++) {
        cout << *iter << "\t";
    }
    cout << endl;
}

int GetWeight(const vector<int>& on_bridge) {
    return accumulate(on_bridge.begin(), on_bridge.end(), 0);
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0;
    int weight_size = truck_weights.size();
    int truck_idx = 0;
    vector<int> on_bridge(bridge_length, 0);
    
    while (truck_idx < weight_size) {
        // 트럭이 다리에서 나가는 경우
        if (on_bridge.back() != 0) {
            on_bridge.back() = 0;
        }
        
        // 트럭이 다리 위에서 길이 1만큼 이동하는 경우
        if (on_bridge.back() == 0) {
            on_bridge.insert(on_bridge.begin(), 0);
            on_bridge.pop_back();
        }
        
        // 트럭이 다리에 진입하는 경우
        int next_weight = truck_weights[truck_idx];
        if (on_bridge.front() == 0 and GetWeight(on_bridge) + next_weight <= weight) {
            on_bridge.front() = next_weight;
            truck_idx++;
        }
        
        time++;
        
        // cout << "[" << answer << "]" << endl;
        // PrintVector(on_bridge.begin(), on_bridge.end());
    }
    
    answer = time + bridge_length;
        
    return answer;
}