#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 123456789

// info_rows는 2차원 배열 info의 행 길이, info_cols는 2차원 배열 info의 열 길이입니다.
int solution(int** info, size_t info_rows, size_t info_cols, int n, int m) {
    // dp[b]: B도둑의 누적 흔적이 b일 때, A도둑의 최소 흔적합
    int* dp = (int*)malloc(sizeof(int) * m);
    int* ndp = (int*)malloc(sizeof(int) * m);
    for(int i=0; i<m; i++) dp[i] = INF;
    dp[0] = 0;

    for(size_t i=0; i<info_rows; i++) {
        for(int j=0; j<m; j++) ndp[j] = INF;
        int a_tr = info[i][0];
        int b_tr = info[i][1];
        for(int b_sum=0; b_sum<m; b_sum++) {
            if(dp[b_sum] == INF) continue;
            // 1. A도둑이 담당
            int a_sum = dp[b_sum] + a_tr;
            if(a_sum < n) {
                if(ndp[b_sum] > a_sum) ndp[b_sum] = a_sum;
            }
            // 2. B도둑이 담당
            int nb_sum = b_sum + b_tr;
            if(nb_sum < m) {
                if(ndp[nb_sum] > dp[b_sum]) ndp[nb_sum] = dp[b_sum];
            }
        }
        int* temp = dp;
        dp = ndp;
        ndp = temp;
    }

    // dp 배열 중 최소값 찾기
    int answer = INF;
    for(int i=0; i<m; i++) {
        if(dp[i] < answer) answer = dp[i];
    }
    free(dp);
    free(ndp);
    return (answer == INF) ? -1 : answer;
}
