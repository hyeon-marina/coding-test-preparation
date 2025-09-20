from collections import defaultdict, deque

def solution(nodes, edges):
    graph = defaultdict(list)
    # 그래프 생성 (무향)
    for a, b in edges:
        graph[a].append(b)
        graph[b].append(a)
    # isolated node 도 키로 보장
    for n in nodes:
        if n not in graph:
            graph[n] = []

    visited = set()
    ans_hol = 0   # 홀짝 트리 개수
    ans_rev = 0   # 역홀짝 트리 개수

    for start in nodes:
        if start in visited:
            continue
        # 컴포넌트 수집 (BFS)
        q = deque([start])
        visited.add(start)
        comp = []
        while q:
            u = q.popleft()
            comp.append(u)
            for v in graph[u]:
                if v not in visited:
                    visited.add(v)
                    q.append(v)

        hol_nonroot_cnt = 0   # 비-루트 가정에서 '홀짝 노드'인 개수
        rev_nonroot_cnt = 0   # 비-루트 가정에서 '역홀짝 노드'인 개수

        for u in comp:
            deg = len(graph[u])
            nonroot_children = deg - 1
            # 비-루트일 때의 자식 개수의 홀짝과 노드 번호 홀짝 비교
            if (u % 2) == (nonroot_children % 2):
                hol_nonroot_cnt += 1
            else:
                rev_nonroot_cnt += 1

        # rev_nonroot_cnt == 1 이면 그 1개를 루트로 택하면 전체가 '홀짝 트리'가 됨
        if rev_nonroot_cnt == 1:
            ans_hol += 1
        # hol_nonroot_cnt == 1 이면 그 1개를 루트로 택하면 전체가 '역홀짝 트리'가 됨
        if hol_nonroot_cnt == 1:
            ans_rev += 1

    return [ans_hol, ans_rev]