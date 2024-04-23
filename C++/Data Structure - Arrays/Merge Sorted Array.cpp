#include <iostream>
#include <vector>
using namespace std;

void MergeSortedArray(vector<int> &Array1, vector<int> &Array2, vector<int> &result)
{
    int i = 0, j = 0;
    int size1 = Array1.size();
    int size2 = Array2.size();

    while(i < size1 && j < size2)
    {
        if(Array1[i] <= Array2[j])
        {
            result.push_back(Array1[i]);
            i++;
        }
        else
        {
            result.push_back(Array2[j]);
            j++;
        }
    }

    while(i < size1)
    {
        result.push_back(Array1[i]);
        i++;
    }

    while(j < size2)
    {
        result.push_back(Array2[j]);
        j++;
    }

}

int main()
{
    vector<int> arr1 = {1,3,5,7,9};
    vector<int> arr2 = {2,4,6,8,10};
    vector<int> res;

    MergeSortedArray(arr1,arr2,res);

    for(int i : res)
        cout << i << " ";

    return 0;
}