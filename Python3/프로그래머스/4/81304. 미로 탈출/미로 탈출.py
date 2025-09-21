import heapq

def solution(n, start, end, roads, traps):
    # traps 목록을 인덱스 맵핑하여 비트마스크의 비트 위치 지정
    trap_index = {trap: i for i, trap in enumerate(traps)}
    T = len(traps)
    
    # 인접리스트: 정방향 간선과 역방향 간선 따로 저장
    # adj_forward[u] = list of (v, cost)
    # adj_backward[u] = list of (v, cost) meaning edge v->u in 원래 그래프
    adj_forward = [[] for _ in range(n+1)]
    adj_backward = [[] for _ in range(n+1)]
    
    for u, v, w in roads:
        adj_forward[u].append((v, w))     # u -> v, 정방향
        adj_backward[v].append((u, w))    # 역방향 저장: 유의해서 사용할 것
    
    INF = float('inf')
    # dist[node][state] = 현재 노드 = node, trap 활성화 상태 bitmask = state 일 때의 최단 시간
    # 상태(state)는 0 ~ (1<<T)-1 까지
    dist = [ [INF] * (1<<T) for _ in range(n+1) ]
    
    # 우선순위 큐 요소: (누적비용, 현재노드, 현재 state 비트마스크)
    pq = []
    # 시작상태
    dist[start][0] = 0
    heapq.heappush(pq, (0, start, 0))
    
    while pq:
        cost, u, state = heapq.heappop(pq)
        # 이미 더 좋은 경로가 발견된 상태면 무시
        if dist[u][state] < cost:
            continue
        # 목표 도착
        if u == end:
            return cost
        
        # 현재 노드 u가 활성화된 트랩인지 여부
        u_is_trap = u in trap_index
        if u_is_trap:
            u_bit = (state >> trap_index[u]) & 1
        else:
            u_bit = 0
        
        # 이웃 노드 탐색: 정방향 간선과 역방향 간선 모두 고려
        # for each 가능한 이웃 v, 어떤 간선을 사용 가능한지 판단
        # 정방향 간선 사용 가능하려면: 간선이 원래 방향 u->v 인 경우, 간선이 뒤집혀 있지 않아야 함 (즉 u_bit ^ v_bit == 0)
        # 역방향 간선 사용 가능하려면: 유사하게 간선 원래 방향이 v->u 인 경우, 현재 상태에서 u_bit ^ v_bit == 1 이어야 함
        
        for v, w in adj_forward[u]:
            # consider u -> v (원래 정방향 간선)
            # 알아야 할 것: v가 트랩인지, 활성화 여부
            v_is_trap = v in trap_index
            v_bit = (state >> trap_index[v]) & 1 if v_is_trap else 0
            
            # edge u->v가 현재 상태에서 유효한가?
            # 정방향 간선은 정상적으로 u->v 방향인 상태일 때 유효
            # 즉, 간선이 뒤집혀 있으면 사용 불가
            # 간선이 뒤집힌 상태란 u_bit ^ v_bit == 1 인 경우
            if (u_bit ^ v_bit) == 0:
                next_state = state
                # v가 트랩이면 방문함으로써 상태 바뀜
                if v_is_trap:
                    next_state = state ^ (1 << trap_index[v])
                next_cost = cost + w
                if dist[v][next_state] > next_cost:
                    dist[v][next_state] = next_cost
                    heapq.heappush(pq, (next_cost, v, next_state))
        
        for v, w in adj_backward[u]:
            # consider 역방향 간선: 원래는 v->u 였던 간선, 현재 뒤집혀야 u->v 가 됨
            v_is_trap = v in trap_index
            v_bit = (state >> trap_index[v]) & 1 if v_is_trap else 0
            
            # 이 간선이 유효하려면 u_bit ^ v_bit == 1 이어야 함 (즉 간선이 뒤집힌 상태)
            if (u_bit ^ v_bit) == 1:
                next_state = state
                if v_is_trap:
                    next_state = state ^ (1 << trap_index[v])
                next_cost = cost + w
                if dist[v][next_state] > next_cost:
                    dist[v][next_state] = next_cost
                    heapq.heappush(pq, (next_cost, v, next_state))
    
    # end 노드에 도달한 모든 상태 중 최소값
    ans = min(dist[end])
    return ans