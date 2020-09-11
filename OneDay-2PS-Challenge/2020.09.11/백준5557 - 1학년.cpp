//
//  백준5557 - 1학년.cpp
//  OneDay2PS
//
//  Created by 김성헌 on 2020/09/11.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

long long cache[101][20000];
long long ans;
vector<int> v;

long long cal(int n,int sum){
    if(sum < 0 || sum > 20) return 0;
    long long &ret = cache[n][sum];
    if(ret != 0) return ret;
    if(n == v.size() - 1){
        if(sum == ans) return 1;
        else return 0;
    }
    ret = cal(n+1,sum + v[n+1]) + cal(n+1,sum - v[n+1]);
    return ret;
}
int main(){
    memset(cache,0,sizeof(cache));
    int n,element;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> element;
        v.push_back(element);
    }
    cin >> ans;
    cout << cal(0,v[0]) << endl;
    return 0;
}
