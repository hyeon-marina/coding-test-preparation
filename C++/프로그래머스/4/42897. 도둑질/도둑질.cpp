#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;

    const int size = money.size();

    std::vector<int> dp(size + 1);
    dp[1] = money[0];

    for (int i = 2; i < size; ++i)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + money[i - 1]);
    }

    answer = std::max(dp[size - 1], dp[size - 2]);

    dp.clear();
    dp.resize(size + 1);

    for (int i = 2; i <= size; ++i)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + money[i - 1]);
    }

    answer = std::max(answer, std::max(dp[size], dp[size - 1]));

    return answer;
}
