//
//  백준17244 - 아맞다우산.cpp
//  OneDay2PS
//
//  Created by 김성헌 on 2020/09/11.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    int n,m;
    char map[51][51];
    int final_answer = 987654321;
    pair<int,int> start,dest;
    vector<pair<int,int>> material;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            map[i][j] = str[j];
            if(map[i][j] == 'S') start = {i,j};
            else if(map[i][j] == 'X') material.push_back({i,j});
            else if(map[i][j] == 'E') dest = {i,j};
        }
    }
    
    do{
        //material의 순열
        int answer = 0;
        pair<int,int> want,cstart;
        for(int i=0;i<=material.size();i++){
            queue<pair<int,int>> q;
            if(i == material.size()) want = dest;
            else want = material[i];
            int depth[50][50];
            memset(depth,-1,sizeof(depth));
            if(i == 0) cstart = start;
            q.push(cstart);
            depth[cstart.first][cstart.second] = 0;
            while(!q.empty()){
                pair<int,int> top = q.front(); q.pop();
                if(top == want){
                    answer += depth[top.first][top.second];
                    break;
                }
                for(int j=0;j<4;j++){
                    int nx = top.first + dx[j];
                    int ny = top.second + dy[j];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(depth[nx][ny] == -1 && map[nx][ny] != '#'){
                        q.push({nx,ny});
                        depth[nx][ny] = depth[top.first][top.second] + 1;
                    }
                }
            }
            if(i != material.size()) cstart = material[i];
        }
        final_answer = min(answer,final_answer);
    }while(next_permutation(material.begin(), material.end()));
    cout << final_answer << endl;
    return 0;
}
