//
//  main.cpp
//  OneDay2PS
//
//  Created by 김성헌 on 2020/09/10.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
priority_queue<int,vector<int>,greater<int>> max_heap;
priority_queue<int,vector<int>,less<int>> min_heap;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n,element;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> element;
        if(max_heap.size() == min_heap.size()) max_heap.push(element);
        else min_heap.push(element);
        if(!max_heap.empty() && !min_heap.empty() && min_heap.top() > max_heap.top()){
            int swap_x = max_heap.top();
            int swap_y = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            max_heap.push(swap_y);
            min_heap.push(swap_x);
        }
        if(i%2 != 0) printf("%d\n",max_heap.top());
        else printf("%d\n",min_heap.top());
    }
    return 0;
}
