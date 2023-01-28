//A - Labyrinth
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int mp[1000][1000],dir[1000][1000];
int main(){
    fio;
    int n,m;
    cin>>n>>m;
    pair<int,int>A,B;//�sAB�I���y��
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            char tmp;
            cin>>tmp;
            //��a���ܦ�1�B0���Φ�
            if(tmp=='#')mp[i][k]=0;
            else mp[i][k]=1;
            //��XA.B���y��
            if(tmp=='A')A={i,k};
            else if(tmp=='B')B={i,k};
        }
    }
    queue<pair<int,int>>q;
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//��W�U���k���I
    q.push(A);//�qA�I�}�l�]
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
    if (!dir[B.first][B.second]){//�p�GB�I�S����V
        cout<<"NO"<<endl;
        return 0;
    }

    vector<char>v;
    string tar=" DURL";//D:�U,U:�W...
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




