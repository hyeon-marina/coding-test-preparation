def solution(distance, rocks, n):
    rocks.sort()
    rocks.append(distance)
    
    left, right = 1, distance
    answer = 0
    
    while left <= right:
        mid = (left + right) // 2
        remove_cnt = 0
        prev = 0
        
        for rock in rocks:
            if rock - prev < mid:
                remove_cnt += 1
            else:
                prev = rock
        
        if remove_cnt > n:
            right = mid - 1
        else:
            answer = mid
            left = mid + 1
    
    return answer