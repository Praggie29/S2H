class Solution {
public:
    int maxProduct(int n) {
        vector<int>dig;
        int num=n;
        while(num){
            int mod=num%10;
            dig.push_back(mod);
            num/=10;
        }
        int maxi=INT_MIN;
        for(int i=0;i<dig.size();i++){
            for(int j=i+1;j<dig.size();j++){
                int prod=dig[i]*dig[j];
                maxi=max(maxi,prod);
            }
        }
      return maxi;
    }
};