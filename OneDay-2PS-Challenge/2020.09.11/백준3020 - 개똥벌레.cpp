//
//  백준3020 - 개똥벌레.cpp
//  OneDay2PS
//
//  Created by 김성헌 on 2020/09/11.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,h,element;
    vector<int> jong,suk;
    cin >> n >> h;
    for(int i=1;i<=n;i++){
        cin >> element;
        if(i%2 == 0) jong.push_back(element);
        else suk.push_back(element);
    }
    
    sort(jong.begin(),jong.end());
    sort(suk.begin(),suk.end());
    
    vector<int> answer;
    for(int i=1;i<=h;i++){
        int index = int(suk.size()) - int(lower_bound(suk.begin(), suk.end(), i) - suk.begin());
        index += jong.size() - (upper_bound(jong.begin(), jong.end(), h-i) - jong.begin());
        answer.push_back(index);
    }

    sort(answer.begin(),answer.end());
    int cnt = int(upper_bound(answer.begin(), answer.end(), answer[0]) - answer.begin());
    cout << answer[0] << " " << cnt << endl;
    return 0;
}
