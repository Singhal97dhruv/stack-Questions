//In this we have to find the total amount of water we can store between the buildings
// ip=[3,0,0,2,0,4]
//op=10
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int trw(vector<int>height){
    vector<int>mxl(height.size()),mxr(height.size());
    mxl[0]=height[0];
    for(int i=1;i<height.size();i++){
        mxl[i]=max(mxl[i-1],height[i]);
    }
    mxr[height.size()-1]=height[height.size()-1];
    for(int i=height.size()-2;i>=0;i--){
        mxr[i]=max(mxr[i+1],height[i]);
    }
    vector<int>water(height.size());
    int total_water=0;
    for(int i=0;i<water.size();i++){
        water[i]=min(mxl[i],mxr[i])-height[i];
        total_water+=water[i];
    }
    return total_water;
}
int main(){
    int n;
    cout<<"Enter the number of buildings: ";
    cin>>n;
    vector<int>buildings(n);
    cout<<"Enter the heights of buildings: ";
    for(int i=0;i<n;i++){
        cin>>buildings[i];
    }
    cout<<"The maximum water we can store is: "<<trw(buildings);
}