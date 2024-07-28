#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const unsigned long long INF = numeric_limits<unsigned long long>::max();
vector<vector<unsigned long long>> dist;

void findPartyHouse(int N, int M) {
    unsigned long long minSum = INF;
    int party = -1;

    for (int i = 0; i < N; ++i) {
        unsigned long long sum = 0;
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] == INF) {
                sum = INF;
                break;
            }
            sum += dist[i][j];
        }

        if (sum < minSum) {
            minSum = sum;
            party = i;
        }
    }

    cout << party + 1 << '\n';
}

int main() {
    int N, M;
    cin >> N >> M;
    dist.resize(N, vector<unsigned long long>(N, INF));

    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        int x, y;
        unsigned long long l;
        cin >> x >> y >> l;
        --x; --y;
        if (dist[x][y] > l) {
            dist[x][y] = l;
            dist[y][x] = l;
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    findPartyHouse(N, M);

    return 0;
}

