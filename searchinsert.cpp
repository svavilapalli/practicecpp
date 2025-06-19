/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0 ;
        int mid;
        int right = nums.size()-1;
        while(left <= right){
            mid = (left+right)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid]>target)
                right = mid-1;
            else
                left = mid + 1;          
        }
        return left;
    }
};



int main()
{ 
    int target = 5;
    std::vector<int> nums = {1, 3, 5, 6};
    Solution s  = new Solution();
    int r = s.searchInsert(nums, target);
    ofstream fout(getenv("OUTPUT_PATH"));
    fout << "Expected Output: 2";
    fout << "Actual Output: ";
    fout << r;
    fout << "\n";
    fout.close();
    return 0;
}
