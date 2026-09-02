class Solution {
public:
bool isPossible(vector<int>&nums,int k,int mid){
    int subarrays=1;
    int currentsum=0;
    for(int num:nums){
        if(currentsum+num <= mid ){
            currentsum+=num;
        }else{
            subarrays++;
            currentsum=num;
        }
    }
    return subarrays <= k ;
}
    int splitArray(vector<int>& nums, int k) {
       int left=*max_element(nums.begin(),nums.end());
       int right=0;
       for(int num:nums) right+=num;
       while(left<=right){
        int mid=left+(right-left)/2;
        if(isPossible(nums,k,mid)){
            right=mid-1;
        }else{
            left=mid+1;
        }
       }
       return left; 
    }
};