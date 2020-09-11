//
//  백준1717 - 집합의 표현.cpp
//  OneDay2PS
//
//  Created by 김성헌 on 2020/09/11.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

int root[1000001]; //[x], x의 부모
int depth[1000001]; //[x]의 rank
using namespace std;

int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void unionByRank(int x,int y){
    x = find(x); //뿌리 찾기
    y = find(y);
    if(x == y) return;
    //항상 높이가 더 낮은 트리를 밑에 넣는다.
    if(depth[x] < depth[y]){
        root[x] = y;
    }else{
        root[y] = x;
        if(depth[x] == depth[y]) depth[x]++;
    }
}

int main(){
    vector<string> v;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<=n;i++) {
        root[i] = i;
        depth[i] = 0;
    }
    for(int i=0;i<m;i++){
        int op,one,two;
        cin >> op >> one >> two;
        switch (op) {
            case 0:
                unionByRank(one, two);
                break;
            case 1:
                if(find(one) == find(two)) v.push_back("YES");
                else v.push_back("NO");
                break;
        }
    }
    for(int i=0;i<v.size();i++) printf("%s\n",v[i].c_str());
    return 0;
}
