//given an input array we have to find the nearest smaller element in right of every element present in the array
// eg i/p=[1,3,0,0,1,2,4]
//o/p=[0,0,-1,-1,-1,-1,-1]


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
void nle(vector<int>inp,vector<int>& res){
    stack<int>st;
    for(int i=inp.size()-1;i>=0;i--){
        if(st.empty())res.push_back(-1);
        else if(st.top()<inp[i]){
            res.push_back(st.top());
        }
        else{
            while(st.size()>0 && st.top()>= inp[i]){
                st.pop();
            }
            if(st.empty())res.push_back(-1);
            else res.push_back(st.top());
        }
        st.push(inp[i]);
        // cout<<res[i];
    }
}
int main(){
    int n;
    cout<<"Enter the numbers you want to enter in the array: ";
    cin>>n;
    vector<int>vect;
    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        vect.push_back(num);
    }
    vector<int>res;
    nle(vect,res);
    reverse(res.begin(),res.end());
    cout<<"Next smaller elements of the given input are :"<<endl;
    for(int i:res){
        cout<<i<<" ";
    }
}