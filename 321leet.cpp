/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


 void sortDescending(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
}
    vector<int> subaray(vector<int>& nums, int k)
    {
        vector<int> ans,temp(nums.begin(),nums.end());
        sortDescending(temp);
        temp.resize(k);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<temp.size();j++)
            {
                if(nums[i]==temp[j]) {
                    ans.push_back(temp[j]);               
                    temp.erase(temp.begin()+j);
                }
            }
        }
        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> temp1, temp2,ans, fina;
        for(int i=k;i>-1;i--)
        {
            temp1=subaray(nums1, i);
            temp2=subaray(nums2, k-i);
            int j=0;
            while(j<temp1.size()+temp2.size()){
                if(j < temp1.size() && j < temp2.size()) {
                    if(temp1[j] > temp2[j]) ans.push_back(temp1[j]);
                    else ans.push_back(temp2[j]);
                } 
                else if(j < temp1.size()) ans.push_back(temp1[j]);
                else if(j < temp2.size())  ans.push_back(temp2[j]);
                j++;
                
            }
            if(fina.size()>0){
                for(int z=0;z<max(fina.size(),ans.size());z++)
                {  
                    
                    if(ans[z]>fina[z] && ans.size()>fina.size()) 
                        { 
                            fina.clear();
                            for(int u=0;u<ans.size();u++)  fina.push_back(ans[u]);
                        }
                }
                ans.clear();
            }
            else{
                for(int i=0;i<ans.size();i++) fina.push_back(ans[i]);
                ans.clear();
            }
            
        }
        return fina;
    }
    
    
    int main(){
        int k=5;
        vector<int> nums1, nums2, fina;
        nums1.push_back(3);
        nums1.push_back(4);
        nums1.push_back(6);
        nums1.push_back(5);
        nums2.push_back(9);
        nums2.push_back(1);
        nums2.push_back(2);
        nums2.push_back(5);
        nums2.push_back(8);
        nums2.push_back(3);
        fina=maxNumber(nums1,nums2,k);
        for(int i=0;i<fina.size();i++) cout<<fina[i];
        cout<<endl<<fina.size();
        return 0;
    }
    
    
    