void f(vector<int>&v){
    v[2]++;
    if(v[2]==v[3]+1){
        v[2]=1;
        v[1]++;
    }
    if(v[1]==v[3]+1){
        v[1]=1;
        v[0]++;
    }
    if(v[0]==v[3]+1){
        v[0]=1;
        v[3]++;
    }
}
