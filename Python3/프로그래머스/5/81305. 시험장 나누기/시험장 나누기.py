import sys
sys.setrecursionlimit(10**7)

def solution(k, num, links):
    n = len(num)
    # 부모가 없는 노드 = 루트 찾기
    parent = [-1] * n
    for i in range(n):
        l, r = links[i]
        if l != -1:
            parent[l] = i
        if r != -1:
            parent[r] = i
    root = parent.index(-1)

    # DFS 후위순회로 각 노드별 (인원합, 그룹개수) 반환
    def dfs(node, limit):
        left, right = links[node]
        sum_left, cnt_left = (dfs(left, limit) if left != -1 else (0, 0))
        sum_right, cnt_right = (dfs(right, limit) if right != -1 else (0, 0))

        total_people = num[node] + sum_left + sum_right

        # 경우 1: 자식 둘 + 나까지 같이 그룹 가능
        if total_people <= limit:
            return total_people, cnt_left + cnt_right
        # 경우 2: 자식 중 하나만 + 나 그룹
        if num[node] + min(sum_left, sum_right) <= limit:
            # 그룹 하나 더 생긴다: 기존 자식들 그룹 개수만큼 + (나 포함한 그룹 1개)
            # 자식 그룹 개수 합이 cnt_left+cnt_right
            # 여기서 묶는 자식의 그룹 개수 변화 없음
            return num[node] + min(sum_left, sum_right), cnt_left + cnt_right + 1
        # 경우 3: 둘 다 못 묶음 → 나만 새로운 그룹
        return num[node], cnt_left + cnt_right + 2

    # 이분탐색
    left = max(num)
    right = sum(num)
    answer = right
    while left <= right:
        mid = (left + right) // 2
        _, groups = dfs(root, mid)
        # 그룹 개수 값은 ‘groups’+1 그룹이 사용됨 (dfs는 새 그룹 생길 때 +2 등)
        if groups + 1 <= k:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1

    return answer