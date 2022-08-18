// In this problem we have to find the maximum area we can find with the histogram
//ip=[6,2,5,4,5,1,6]
//op=12

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void nsl(vector<int>inp,vector<int>& res){
    stack<pair<int,int>>st;
    for(int i=0;i<inp.size();i++){
        if(st.empty())res.push_back(-1);
        else if(st.top().first<inp[i]){
            res.push_back(st.top().second);
        }
        else{
            while(st.size()>0 && st.top().first>= inp[i]){
                st.pop();
            }
            if(st.empty())res.push_back(-1);
            else res.push_back(st.top().second);
        }
        st.push({inp[i],i});
    }
}
void nsr(vector<int>inp,vector<int>& res){
    stack<pair<int,int>>st;
    int temp=inp.size();
    for(int i=inp.size()-1;i>=0;i--){
        if(st.empty())res.push_back(temp);
        else if(st.top().first<inp[i]){
            res.push_back(st.top().second);
        }
        else{
            while(st.size()>0 && st.top().first>= inp[i]){
                st.pop();
            }
            if(st.empty())res.push_back(temp);
            else res.push_back(st.top().second);
        }
        st.push({inp[i],i});

        // cout<<res[i];
    }
    reverse(res.begin(),res.end());
}
int main(){
     int n,ans=INT_MIN;
    cout<<"Enter how many number you want in array: ";
    cin>>n;
    vector<int>inp;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        inp.push_back(number);
    }
    vector<int>temp1,temp2,temp3;
    nsl(inp,temp1);
    nsr(inp,temp2);
    for(int i=0;i<inp.size();i++){
        temp3.push_back(temp2[i]-temp1[i]-1);
        ans=max(ans,temp3[i]*inp[i]);
    }
    cout<<"Maximum area is :"<<ans;
}