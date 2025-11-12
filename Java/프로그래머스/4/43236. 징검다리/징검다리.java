import java.util.Arrays;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        // 바위를 제거한 뒤, 시작점(0)부터 도착점(distance)까지
        // 각 지점 사이의 거리 중 **최솟값**이 되도록 하는 값을 “가능한 한 크게” 만드는 것이 목표

        Arrays.sort(rocks);  // 바위 위치 정렬

        int left = 1;           // 최소 가능 거리 (1부터 시작)
        int right = distance;   // 최대 가능 거리
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;  // “지점 간 최소 거리로 가정하는 값”
            int prev = 0;                  // 직전 남은 지점 (출발점은 0)
            int removeCnt = 0;             // 제거해야 하는 바위 수

            for (int rock : rocks) {
                if (rock - prev < mid) {
                    // 이 바위를 남기면 이전 지점과의 거리가 mid 미만이므로 제거해야 한다
                    removeCnt++;
                } else {
                    // 유지할 바위로 선택 → 현재 지점을 prev로 갱신
                    prev = rock;
                }
            }

            // 도착점까지 남은 마지막 거리 체크
            if (distance - prev < mid) {
                removeCnt++;
            }

            if (removeCnt > n) {
                // 바위를 너무 많이 제거해야만 mid 이상 간격을 만들 수 있었다 → mid가 너무 크다
                right = mid - 1;
            } else {
                // 바위를 n개 이하로 제거하고 mid 이상의 간격 확보 가능 → mid 가능
                answer = mid;
                left = mid + 1;
            }
        }

        return answer;
    }
}