#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int left = 0;
        int right = 1;

        int max = 0;

        while(right < prices.size()){
            if (prices[left] < prices[right]){
                int current_profit = prices[right] - prices[left];
                if (current_profit > max){
                    max = current_profit;
                }
            }
            else{ // if left is greater or equal to right
                // move left
                left = right;
            }
            right++;
        }
        return max;
    }
};

int main(){

    // vector<int> v{7,1,5,3,6,4}; // 5
    vector<int> v{1,2,4,2,5,7,2,4,9,0,9};

    Solution s;

    cout << s.maxProfit(v) << endl;

}