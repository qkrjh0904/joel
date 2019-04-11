#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int d[100][100];
bool apple[100][100];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        apple[x-1][y-1] = true;
    }
    memset(d,-1,sizeof(d));
    int x = 0;
    int y = 0;
    int dir = 0;
    int len = 1;
    d[x][y] = 0;
    cin >> m;
    int now = 0;
    for (int k=0; k<=m; k++) {
        int t = n*n+1;
        char ch = 'L';
        if (k < m) {
            cin >> t >> ch;
        }
        while (now < t) {
            now += 1;
            x += dx[dir];
            y += dy[dir];
            if (x < 0 || x >= n  || y < 0 || y >= n) {
                cout << now << '\n';
                return 0;
            }
            if (apple[x][y]) {
                apple[x][y] = false;
                len += 1;
            }
            if (d[x][y] != -1 && now-d[x][y] <= len) {
                cout << now << '\n';
                return 0;
            }
            d[x][y] = now;
            
//            for(int i=0; i<n; ++i){
//				for(int j=0; j<n; ++j){
//					cout.width(3);
//					cout<<d[i][j]<<' ';
//				}
//				cout<<endl;
//			} cout<<endl;
        }
        if (ch == 'L') {
            dir = (dir + 3) % 4;
        } else {
            dir = (dir + 1) % 4;
        }
    }
    return 0;
}


/*
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j)
			cout<<d[i][j]<<' ';
		cout<<endl;
	} 
*/
