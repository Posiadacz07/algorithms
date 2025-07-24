#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    if(numRows == 1){
        return {{1}};
    }
    std::vector<std::vector<int>> result(numRows);
    result[0] = {1};
    result[1] = {1,1};
    for(int i = 2; i < numRows; i++) {
        result[i].push_back(1);
        for(int j = 1; j < i; j++) {
            result[i].push_back(result[i-1][j-1]+result[i-1][j]);
        }
        result[i].push_back(1);
    }
    return result;
}