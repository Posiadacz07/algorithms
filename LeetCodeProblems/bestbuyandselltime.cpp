#include <vector>

int maxProfit(std::vector<int>& prices) {
    int max = 0;
    int buy = prices[0];
    for(int i = 1; i < prices.size(); i++){
        if(buy > prices[i]){
            buy = prices[i];
        } else if (prices[i] - buy > max){
            max = prices[i] - buy;
        }
    }

    return max;
}