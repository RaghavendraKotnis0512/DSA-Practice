//Brute Force


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //this is brute force but it will give runtime error
        int ans=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
               int profit=prices[j]-prices[i];

                ans=max(profit,ans);
            }
        }
        return ans;
    }
};




//Optimal Approach


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int maxProfit=0;

        for(int i=0;i<prices.size();i++){
           int profit=prices[i]-minPrice;
            maxProfit=max(profit,maxProfit);  //check if profit is more
            minPrice=min(minPrice,prices[i]); //check if buying price is less

        }
        return maxProfit;
    }
};