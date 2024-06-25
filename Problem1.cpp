/* 
Find the missing element

Time Complexity: O(log(n))

Space Complexity: O(1)

*/

#include <iostream>
#include <vector>

int findTheMissingElement(std::vector<int>& nums){
    int low = 0;
    int size = nums.size();
    if (size == 0) return -1;
    else if (nums[low] != 1) return 1;
    int  high = size - 1;
    while (low <= high){
        int mid = low + (high - low)/2;
        if (nums[mid] - nums[mid - 1] > 1) return nums[mid] - 1;
        else if (nums[mid]  > mid + 1 ) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    std::vector<int> arr = {1,2,3,5,6,7,8,9};
    int missing_element = 4;
    int result = findTheMissingElement(arr);
    if (missing_element != result) std::cout<< "Wrong Answer: " << result << " . Does not match expected result: " << missing_element << std::endl;
    else std::cout<< "Answer matches: " << result << " . Does match expected result: " << missing_element << std::endl;

    arr = {2,3,4,5,6,7,8,9};
    missing_element = 1;
    result = findTheMissingElement(arr);
    if (missing_element != result) std::cout<< "Wrong Answer: " << result << " . Does not match expected result: " << missing_element << std::endl;
    else std::cout<< "Answer matches: " << result << " . Does match expected result: " << missing_element << std::endl;

    arr = {1,3,4,5,6,7,8,9};
    missing_element = 2;
    result = findTheMissingElement(arr);
    if (missing_element != result) std::cout<< "Wrong Answer: " << result << " . Does not match expected result: " << missing_element << std::endl;
    else std::cout<< "Answer matches: " << result << " . Does match expected result: " << missing_element << std::endl;
    
    arr = {1,2, 3,4,5,6,7,9};
    missing_element = 8;
    result = findTheMissingElement(arr);
    if (missing_element != result) std::cout<< "Wrong Answer: " << result << " . Does not match expected result: " << missing_element << std::endl;
    else std::cout<< "Answer matches: " << result << " . Does match expected result: " << missing_element << std::endl;

    arr = {1,2,3,4,5,6,8,9};
    missing_element = 7;
    result = findTheMissingElement(arr);
    if (missing_element != result) std::cout<< "Wrong Answer: " << result << " . Does not match expected result: " << missing_element << std::endl;
    else std::cout<< "Answer matches: " << result << " . Does match expected result: " << missing_element << std::endl;

    return 0;
}