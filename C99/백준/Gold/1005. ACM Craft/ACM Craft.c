#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
int main(void) {
    int T; scanf("%d", &T);
    while(T--) {
        int N, K, X, Y, W;
        int time[MAX], dp[MAX]={0}, indegree[MAX]={0};
        int adj[MAX][MAX]={0};
        scanf("%d %d", &N, &K);
        for(int i=1;i<=N;i++){
            scanf("%d", &time[i]);
            dp[i]=time[i];
        }
        for(int i=0;i<K;i++){
            scanf("%d %d",&X,&Y);
            adj[X][Y]=1;
            indegree[Y]++;
        }
        scanf("%d",&W);
        int queue[MAX], f=0, r=0;
        for(int i=1;i<=N;i++)
            if(indegree[i]==0) queue[r++]=i;
        while(f<r){
            int now=queue[f++];
            for(int next=1;next<=N;next++){
                if(adj[now][next]){
                    if(dp[next]<dp[now]+time[next])
                        dp[next]=dp[now]+time[next];
                    if(--indegree[next]==0)
                        queue[r++]=next;
                }
            }
        }
        printf("%d\n",dp[W]);
    }
    return 0;
}
