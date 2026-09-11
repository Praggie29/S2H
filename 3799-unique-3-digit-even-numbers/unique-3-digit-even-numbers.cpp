class Solution {
public:
   set<int>st;
   void solve(vector<int>&digits,vector<bool>&check,int num,int len){
    if(len==3){
        if(num>=100 && num%2==0){
            st.insert(num);
        }
        return;
    }
    for(int i=0;i<digits.size();i++){
        if(check[i]) continue;
        if(len==0 && digits[i]==0) continue;
        check[i]=true;
        solve(digits,check,num*10+digits[i],len+1);
        check[i]=false;
    }
   }
    int totalNumbers(vector<int>& digits) {
        vector<bool>check(digits.size(),false);
        solve(digits,check,0,0);
        return st.size();
    }
};