// Given an array we have to provide the number of consecutive numbers that are smaller or equal to that element before it
// ip=[100,80,60,70,60,75,85]
// o/p=[1,1,1,2,1,4,6]

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void ngl(vector<int>inp,vector<int>& res){
    stack<pair<int,int>>st;
    vector<int>v;
    for(int i=0;i<inp.size();i++){
        if(st.empty())v.push_back(-1);
        else if(st.top().first>inp[i]){
            v.push_back(st.top().second);
        }
        else{
            while(st.size()>0 && st.top().first<= inp[i]){
                st.pop();
            }
            if(st.empty())v.push_back(-1);
            else v.push_back(st.top().second);
        }
        st.push({inp[i],i});
        // for(int i=0;i<v.size();i++){
        //     res[i]=v[i]-i;
        // }

    }
    for(int i=0;i<v.size();i++){
            res.push_back(i-v[i]);
        }
}
int main(){
    int n;
    cout<<"Enter how many number you want in array: ";
    cin>>n;
    vector<int>inp;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        inp.push_back(number);
    }
    vector<int>res;
    ngl(inp,res);
    cout<<"Our stock span problem output is:"<<endl;
    for(int i:res){
        cout<<i<<" ";
    }
}