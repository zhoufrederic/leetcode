//
// Created by zibo on 19-7-5.
//
#include <iostream>
#include <vector>

using namespace std;

//快速排序
void quickSort(vector<int>& nums, int left, int right)
{
    int l = left;
    int r = right;

    if (l < r)
    {
        auto temp = nums[l];

        while (l != r)
        {
            while (l < r && nums[r] >= temp)
            {
                --r;
            }
            nums[l] = nums[r];

            while (l < r && nums[l] <= temp)
            {
                ++l;
            }

            nums[r] = nums[l];
        }

        nums[r] = temp;

        quickSort(nums, left, l - 1);
        quickSort(nums, l + 1, right);
    }
}

//插入排序
void insertSort(vector<int>& a)
{
    for (int i = 1; i < a.size(); ++i)
    {
        int temp = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; --j)
        {
            a[j + 1] = a[j];
        }

        a[j + 1] = temp;
    }
}

//选择排序
void selectSort(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[minIndex] > nums[j])
            {
                minIndex = j;
            }
        }
        swap(nums[minIndex], nums[i]);
    }
}

int main()
{
    vector<int> nums{10, 7, 2, 5, 4, 8, 1, 9, 6, 3};

    //quickSort(nums, 0, nums.size() - 1);
    //insertSort(nums);
    selectSort(nums);

    for (const auto& c : nums)
    {
        cout << c << " ";
    }

    return 0;
}
