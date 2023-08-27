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

void print(vector<int>&v,int n){
    for(int i=0;i<n;i++){
        int a=(v[0]*v[0]*v[0])+(v[1]*v[1]*v[1]);
        int b=(v[2]*v[2]*v[2]);
        cout<<v[0]<<'^'<<v[3]<<'+'<<v[1]<<'^'<<v[3];
        if(a>b)cout<<'>';
        else cout<<'<';
        cout<<v[2]<<'^'<<v[3]<<endl;
        f(v);
    }
}
