#include<bits/stdc++.h>
using namespace std;

struct State {
    int r, c, d;
};

int dr[] = {-1, 1, 0, 0}; // U, D, L, R
int dc[] = {0, 0, -1, 1};
char dchar[] = {'U', 'D', 'L', 'R'};
int p_dir[1005][1005][4]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    int sr, sc, gr, gc;

    for (int i = 0; i < H; i++) {
        cin >> grid[i];
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'S') { sr = i; sc = j; }
            if (grid[i][j] == 'G') { gr = i; gc = j; }
        }
    }

    for(int i=0; i<H; ++i)
        for(int j=0; j<W; ++j)
            for(int k=0; k<4; ++k)
                p_dir[i][j][k] = -1;

    queue<State> q;

    for (int i = 0; i < 4; i++) {
        int nr = sr + dr[i], nc = sc + dc[i];
        if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] != '#') {
            if (p_dir[nr][nc][i] == -1) {
                p_dir[nr][nc][i] = 4; 
                q.push({nr, nc, i});
            }
        }
    }

    int final_d = -1;
    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.r == gr && curr.c == gc) {
            final_d = curr.d;
            break;
        }

        char cell = grid[curr.r][curr.c];
        for (int i = 0; i < 4; i++) {
            if (cell == 'o' && i != curr.d) continue;
            if (cell == 'x' && i == curr.d) continue;

            int nr = curr.r + dr[i], nc = curr.c + dc[i];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] != '#') {
                if (p_dir[nr][nc][i] == -1) {
                    p_dir[nr][nc][i] = curr.d;
                    q.push({nr, nc, i});
                }
            }
        }
    }

    if (final_d == -1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        string path = "";
        int cr = gr, cc = gc, cd = final_d;
        
        while (cd != 4) {
            path += dchar[cd];
            int prev_d = p_dir[cr][cc][cd];
            cr -= dr[cd];
            cc -= dc[cd];
            cd = prev_d;
        }
        path += dchar[cd == 4 ? final_d : cd];
        path = "";
        cr = gr, cc = gc, cd = final_d;
        while(true){
            path += dchar[cd];
            int next_prev_d = p_dir[cr][cc][cd];
            if(next_prev_d == 4) break;
            cr -= dr[cd];
            cc -= dc[cd];
            cd = next_prev_d;
        }
        
        reverse(path.begin(), path.end());
        cout << path << endl;
    }

    return 0;
}