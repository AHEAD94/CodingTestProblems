#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void foldBill(vector<int>& bill) {
    bill.at(1) = bill.at(1) / 2;
    sort(bill.begin(), bill.end());
}

bool isAcceptable(const vector<int>& wallet, const vector<int>& bill) {
    bool acceptable = false;
    if (bill.at(0) <= wallet.at(0) and bill.at(1) <= wallet.at(1)) {
        acceptable = true;
    }
    return acceptable;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    sort(wallet.begin(), wallet.end());
    sort(bill.begin(), bill.end());
    
    while (!isAcceptable(wallet, bill)) {
        foldBill(bill);
        answer++;
    }
    
    return answer;
}