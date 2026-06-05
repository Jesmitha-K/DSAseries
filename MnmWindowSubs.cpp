#include <iostream>
#include <string>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    int cnt[128] = {};
    int left = 0, need = t.size(); //need=3
    int start = 0, len = INT_MAX;

    for(char c : t)
        cnt[c]++;    //a=1,b=1,c=1

    for(int right = 0; right < s.size(); right++) {

        if(cnt[s[right]]-- > 0)
            need--; //need=2

        while(need == 0) {

            if(right - left + 1 < len) {
                len = right - left + 1;
                start = left;
            }

            if(++cnt[s[left++]] > 0)
                need++;
        }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "String s : " << s << endl;
    cout << "String t : " << t << endl;

    cout << "Minimum Window : "
         << minWindow(s, t) << endl;

    return 0;
}