#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /********** Divide and Conquer **********/
    int findKthLargest(vector<int>& nums, int k) {
        quickSelect(nums, 0, nums.size()-1, k);
        return nums[k-1];
    }
    
    void quickSelect(vector<int>& nums, int low, int high, int k) {
        if(low>=high) return;
        
        int m = partition(nums, low, high);
        int leftLength = m - low + 1;

        if(leftLength > k) quickSelect(nums, low, m-1, k);
        else if(leftLength < k) quickSelect(nums, m+1, high, k-leftLength);
        else return;
    }
    
    // Element larger than pivot will be on the left side of the pivot
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;
        
        for(int j=low; j<high; ++j) {
            if(nums[j] >= pivot) {
                i++;
                swap(&nums[i], &nums[j]);
            }
        }
        swap(&nums[i+1], &nums[high]);
        return i+1;
    }
    
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main(){
    Solution A;
    vector<int> arr;
    int n;
    int k;
    cin>>n;
    cin>>k;
    for (int i = 1; i <= n; i++){
        int temp;
        cin>> temp;
        arr.push_back(temp);
    }
    cout<<A.findKthLargest(arr, k);
    
}
