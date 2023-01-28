//A - Labyrinth
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int mp[1000][1000],dir[1000][1000];
int main(){
    fio;
    int n,m;
    cin>>n>>m;
    pair<int,int>A,B;//存AB點的座標
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            char tmp;
            cin>>tmp;
            //把地圖變成1、0的形式
            if(tmp=='#')mp[i][k]=0;
            else mp[i][k]=1;
            //找出A.B的座標
            if(tmp=='A')A={i,k};
            else if(tmp=='B')B={i,k};
        }
    }
    queue<pair<int,int>>q;
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//找上下左右的點
    q.push(A);//從A點開始跑
    while(!q.empty()){
        auto now=q.front();
        q.pop();//
        for(int k=0;k<4;k++){
            int x = now.first + d[k][0];
            int y = now.second + d[k][1];
            if (0 <= x && x < n && 0 <= y && y < m && mp[x][y]){
                mp[x][y] = 0;
                dir[x][y] = k+1;
                q.push({x, y});
            }
        }
    }
    if (!dir[B.first][B.second]){//如果B點沒有方向
        cout<<"NO"<<endl;
        return 0;
    }

    vector<char>v;
    string tar=" DURL";//D:下,U:上...
    while(B!=A){
        v.push_back(tar[dir[B.first][B.second]]);
        B = {B.first-d[ dir[B.first][B.second] -1 ][0],B.second - d[ dir[B.first][B.second] -1 ][1]};
    }
    reverse(v.begin(), v.end());
    cout << "YES\n";
    cout << v.size() << "\n";
    for (auto i:v){
        cout << i;
    }
}




