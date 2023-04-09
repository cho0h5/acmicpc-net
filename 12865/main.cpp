#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int N, K;
pair<int, int> items[100];
int dp[101][100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
	int w, v;
	cin >> w >> v;
	items[i] = make_pair(w, v);
    }

    for(int i = 0; i < N; i++) {
	for(int j = 1; j <= K; j++) {
	    if(j < items[i].first) {
		dp[i+1][j] = dp[i][j];
	    } else {
		dp[i+1][j] = max(items[i].second + dp[i][j-items[i].first], dp[i][j]);
	    }
	}
    }

//    for(int i = 0; i <= N; i++) {
//	for(int j = 0; j <= K; j++) {
//	    cout << dp[i][j] << ' ';
//	}
//	cout << '\n';
//    }

    cout << dp[N][K];
}
