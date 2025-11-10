import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int[][] solution(int[][] rc, String[] operations) {
        int R = rc.length;
        int C = rc[0].length;

        Deque<Integer> leftCol = new ArrayDeque<>();
        Deque<Integer> rightCol = new ArrayDeque<>();
        Deque<Deque<Integer>> midRows = new ArrayDeque<>();

        // 초기 상태 분리 저장
        for (int i = 0; i < R; i++) {
            leftCol.addLast(rc[i][0]);
            rightCol.addLast(rc[i][C-1]);
            Deque<Integer> mid = new ArrayDeque<>();
            for (int j = 1; j < C-1; j++) {
                mid.addLast(rc[i][j]);
            }
            midRows.addLast(mid);
        }

        // 연산 처리
        for (String op : operations) {
            if (op.equals("ShiftRow")) {
                // 맨 아래 행을 맨 위로
                leftCol.addFirst(leftCol.removeLast());
                rightCol.addFirst(rightCol.removeLast());
                midRows.addFirst(midRows.removeLast());
            } else if (op.equals("Rotate")) {
                // 바깥 테두리 시계방향 회전
                // 순서: leftCol 첫 -> midRows 첫 앞, midRows 첫 뒤 -> rightCol 첫,
                //       rightCol 마지막 -> midRows 마지막 뒤, midRows 마지막 앞 -> leftCol 마지막
                midRows.peekFirst().addFirst(leftCol.removeFirst());
                rightCol.addFirst(midRows.peekFirst().removeLast());
                midRows.peekLast().addLast(rightCol.removeLast());
                leftCol.addLast(midRows.peekLast().removeFirst());
            }
        }

        // 결과 행렬 재조립
        int[][] answer = new int[R][C];
        for (int i = 0; i < R; i++) {
            answer[i][0] = leftCol.removeFirst();
            answer[i][C-1] = rightCol.removeFirst();
            Deque<Integer> mid = midRows.removeFirst();
            for (int j = 1; j < C-1; j++) {
                answer[i][j] = mid.removeFirst();
            }
        }

        return answer;
    }
}