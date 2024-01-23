#include<iostream>
#include<algorithm>

#include<vector>

using namespace std;


long long N;
vector<long long> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    arr.resize(N);

    for(int i=0;i<N;i++){
        long long grade;
        cin>>grade;
        arr[i]=grade;
    }//일단 등수 받고
    sort(arr.begin(),arr.end());

    long long differ_sum=0;
    for(int i=0;i<N;i++){
        differ_sum += abs((arr[i]-(i+1)));
    }
    cout<<differ_sum;
    return 0;


}