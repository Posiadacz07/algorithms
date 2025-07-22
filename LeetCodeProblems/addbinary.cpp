#include <string>

std::string addBinary(std::string a, std::string b) {
    int i = a.length() -1, j = b.length()-1;
    std::string result;
    int overflow = 0;
    while( i >= 0 || j >=0 || overflow){
        if(i >= 0) {
            overflow += a[i] - '0';
            i--;
        }
        if( j >= 0 ){
            overflow += b[j] - '0';
            j--;
        }
        result += overflow%2 + '0';
        overflow /= 2;
    }
    reverse(begin(result), end(result));
    return result;
}