class Solution {
private:
    int partition(vector<int>& nums, int low, int high) {
        int index = low - 1;
        int pivot = nums[high];

        for (int idx = low; idx < high; idx++) {
            if (nums[idx] < pivot) {
                swap(nums[index + 1], nums[idx]);
                index++;
            }
        }

        swap(nums[index + 1], nums[high]);

        return index + 1;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {

        int low = 0;
        int high = nums.size() - 1;

        int temp = 10;
        while (low <= high) {
            int pivot_index = partition(nums, low, high);

            if (pivot_index > nums.size() - k) {
                high = pivot_index - 1;
            } else if (pivot_index < nums.size() - k) {
                low = pivot_index + 1;
            } else {
                return nums[pivot_index];
            }
        }

        return -1;
    }
};
