class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        //将nums1和nums2分成两部分，我们保证每次分割后nums1左部分和nums2的左部分
        //元素的个数之和总是和右部相等(总共有偶数个元素)或者比右部大一(总共有奇数个元素)
        
        //          i
        // [3, 8, | 9, 10]
        //             j
        // [2, 4, 6, | 12, 18, 20]
        //考虑上面的情况，将nums1从9分割成两部分，将nums2从12分割成两部分,此时元素的总个数为偶数此时的中位数
        // median1 = max(nums1[i - 1], num2[j - 1])
        // median2 = min(nums1[i], nums2[j])  
        // ans = (median1 + median2) / 2
        //奇数的情况下也是同理
        //注意分割不是任意的，必须得保证nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i]
        //否则分割出来的数组边界左右两边的数字就是无效的不能参加中位数的计算
        int n = nums1.size();
        int m = nums2.size();
        //nums1分割后的左部分和nums2分割后的左部分的元素个数之和
        int leftTotal = (n + m + 1) / 2;
        //nums1分割的左右边界，当分割线为n时表示nums1分割后的右部分一个元素都没有
        int left = 0;
        int right = n;
        //两个中位数如果元素总个数为奇数时只有median1有意义
        int median1 = 0;
        int median2 = 0;
        while(left <= right) {
            //枚举nums1的分割线，和nums1分割后左部分有几个元素等价
            int i = left + (right - left) / 2;
            //由于两个元素分割后左部分元素个数是已知的，所以在这里减去i就是nums2分割
            //后左部有几个元素
            int j = leftTotal - i;

            //由于分割后的左部分和右部分都可能为空所以要做边界检查
            int num_im = i == 0 ? INT_MIN : nums1[i - 1];
            int num_i = i == n ? INT_MAX : nums1[i];
            int num_jm = j == 0 ? INT_MIN : nums2[j - 1];
            int num_j = j == m ? INT_MAX : nums2[j];

            if(num_im <= num_j) {
                left = i + 1;
                median1 = max(num_im, num_jm);
                median2 = min(num_i, num_j);
            }
            else {
                right = i - 1;
            }
        }

        return (n + m) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};