#include<bits/stdc++.h>
using namespace std;

//Time Complexity:O(N) Auxilari Space:O(1)
pair<int,int> maxsubarraysum(vector<int>&arr){
    int maxsum=0,currentsum=0,startindex=0,tmp=0;
    for(int i=0;i<arr.size();i++){
        currentsum+=arr[i];
        if(currentsum>maxsum){
            startindex=tmp;
            maxsum=currentsum;
        }
        if(currentsum<0){
            currentsum=0;tmp=i+1;
        }
    }
    return {maxsum,startindex};
}
