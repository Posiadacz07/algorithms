/* Example of implemantation and usage of marge sort algorithm for integers. 
 * As an output of the program is given numbers of sorted array.
 * 
 * Made by: Posiadacz07
 */

#include <vector>
#include <iostream>

void merge(std::vector<int>& array, int startIndex, int middleIndex, int endIndex)
{
    std::vector<int> tmp(array);
    int i = startIndex, j = middleIndex + 1, k = startIndex;
    while(i <= middleIndex && j <= endIndex)
    {
        array.at(k++) = tmp.at(i) < tmp.at(j) ? tmp.at(i++) : tmp.at(j++);
    }
    while(i <= middleIndex)
    {
        array.at(k++) = tmp.at(i++);
    }
    while(j <= endIndex)
    {
        array.at(k++) = tmp.at(j++);
    }
}

void mergeSort(std::vector<int>& array, int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        int middleIndex = (startIndex + endIndex)/2;

        mergeSort(array, startIndex, middleIndex);
        mergeSort(array, middleIndex + 1, endIndex);

        merge(array, startIndex, middleIndex, endIndex);
    }
}

int main()
{
    std::vector<int> array = 
        {30,29,28,27,26,25,1,2,3,4,5,6,7,24,23,22,21,20,19,18,8,9,10,11,17,16,15,13,14,12};

    mergeSort(array, 0, array.size() - 1);
    
    for(int i : array)
    {
        std::cout << i << ' ';
    }

    return 0;
}