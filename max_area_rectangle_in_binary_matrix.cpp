// in this input 2d array is given we have to find the max area rectangle we can make by including 1s only
// ip=[[0,1,1,0],[1,1,1,1],[1,1,1,1],[1,1,0,0]]
// op=8
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
int mah(vector<int>vect){
vector<int>temp1,temp2,temp3;
nsl(vect,temp1);
nsr(vect,temp2);
int ans=INT_MIN;
for(int i=0;i<vect.size();i++){
    temp3.push_back(temp2[i]-temp1[i]-1);
    ans=max(ans,temp3[i]*vect[i]);
}
return ans;
}
int mar(vector<vector<int>>v){
    vector<int>vect;
    for(int j=0;j<v[0].size();j++){
        vect.push_back(v[0][j]);
    }
    int mx=mah(vect);
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            if(v[i][j]==0)
                vect[j]=0;
            else{
                vect[j]=vect[j]+v[i][j];
            }
        }
        mx=max(mah(vect),mx);
    }
    return mx;
}

int main(){
    int rows,cols;
    cout<<"Enter the number of rows and columns";
    cin>>rows;
    cin>>cols;
    vector<vector<int>>inp(rows,vector<int>(cols,0));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>inp[i][j];
        }
    }
    cout<<mar(inp);
}