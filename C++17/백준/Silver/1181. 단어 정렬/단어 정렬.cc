#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> words;
    words.reserve(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }
    sort(words.begin(), words.end(), [](const string &a, const string &b){
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    // 중복 제거
    words.erase(unique(words.begin(), words.end()), words.end());
    for(const string &s : words){
        cout << s << '\n';
    }
    return 0;
}