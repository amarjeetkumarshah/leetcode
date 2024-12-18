class Solution {
public:

    int UB1, UB2, cnt; 

    bool containsMedian(int t, vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size(), n = nums2.size();

        int ub1 = upper_bound(begin(nums1), end(nums1), t) - begin(nums1);
        int ub2 = upper_bound(begin(nums2), end(nums2), t) - begin(nums2);
        

        if(ub1+ub2 >= (m+n+1)/2){
            cnt = ub1+ub2;
            UB1 = ((ub1 < m) ? nums1[ub1] : 1e9);
            UB2 = ((ub2 < n) ? nums2[ub2] : 1e9);

            return true;
        }
        return false;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        int s = -1e6-1, e = 1e6+1, mid;
        while(e-s > 1){
            mid = s + (e-s)/2;
            if(containsMedian(mid, nums1, nums2)) e = mid;
            else s = mid;
        }

        double ans = e;

        if((m+n)%2 == 0 && cnt == (m+n+1)/2){
            ans += min(UB1, UB2);
            ans /= 2.0;
        }

        return ans;
    }
};