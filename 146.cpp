#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1005;
const int M = 2005;
struct Node{
    int k, x, y, flag;
};

int n, m, a[N][M], res[M], ans[M], cnt;
bool operator<(Node a, Node b) {
    return a.k > b.k;
}
signed main() {
    int tt;
    cin >> tt;
    while(tt--){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cin >> a[i][j];
            }
            sort(a[i] + 1, a[i] + m + 1);
        }
        for(int j = 1; j <= m; ++j) res[j] = a[1][j];
        for(int i = 2; i <= n; ++i) {
            cnt = 0;
            priority_queue<Node> q;
            q.push(Node{res[1] + a[i][1], 1, 1, 0});
            for(int j = 1; j <= m; ++j){
                Node t = q.top(); q.pop();
                ans[++cnt] = t.k;
                if(t.x < m) q.push(Node{res[t.x + 1] + a[i][t.y], t.x + 1, t.y, 1});
                if(t.y < m && t.flag == 0) q.push(Node{res[t.x] + a[i][t.y + 1], t.x, t.y + 1, 0});
            }
            memcpy(res, ans, (m + 1) * sizeof(int));
        }
        for(int i = 1; i <= m; ++i){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}