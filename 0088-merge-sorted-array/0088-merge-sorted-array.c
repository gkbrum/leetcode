
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int result[m + n];

    int k = (m + n) - 1;
    int i = m - 1;
    int j = n - 1;

    while(k >= 0){
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        if(j < 0){
            return;
        }else{
            while(j >= 0){
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        return;
    }


}