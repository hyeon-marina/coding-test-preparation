import sys
sys.setrecursionlimit(10**7)

def solution(sales, links):
    n = len(sales)
    children = [[] for _ in range(n)]
    for a, b in links:
        # 직원번호가 1부터 주어지므로 인덱스 변환
        children[a-1].append(b-1)
    
    # dp[i][0] = i번 직원(인덱스 i)이 **참석하지 않을 경우**의 최소 매출손실
    # dp[i][1] = i번 직원이 **참석할 경우**의 최소 매출손실
    dp = [[0, 0] for _ in range(n)]
    visited = [False]*n

    def dfs(u):
        visited[u] = True
        # 자식들부터 처리
        total_min_children = 0
        for v in children[u]:
            dfs(v)
            total_min_children += min(dp[v][0], dp[v][1])
        
        # u 참석하는 경우: 자신의 매출 + 자식들이 참석하거나 안하거나 최소
        dp[u][1] = sales[u] + total_min_children
        
        # u 참석하지 않는 경우:
        # 기본은 자식들이 최소값을 취한 상태
        dp[u][0] = total_min_children
        
        # 단, u가 팀장이므로 자신이 참석 안 하면 **자식들 중 적어도 하나는 반드시 참석해야 함**
        # → 모든 자식 v에 대해 dp[v][0] <= dp[v][1] 일 경우(모두 참석하지 않는 게 더 좋을 경우)
        #    그러면 그 중 하나를 강제로 참석시키는 비용을 고려해야 한다.
        if children[u]:
            # 참석 안 했을 때 자식들 모두 dp[v][0] <= dp[v][1] 인지 확인
            all_non_attend_better = True
            min_extra = float('inf')
            for v in children[u]:
                if dp[v][1] < dp[v][0]:
                    all_non_attend_better = False
                # 참석했을 때 - 안 했을 때 차이
                min_extra = min(min_extra, dp[v][1] - dp[v][0])
            
            if all_non_attend_better:
                dp[u][0] += min_extra

    # CEO는 직원번호 1이므로 인덱스 0부터 시작
    dfs(0)
    return min(dp[0][0], dp[0][1])