class Solution {
public:
    vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        //要删除的左括号数量
        int lremove = 0;
        //要删除的右括号的数量
        int rremove = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            //没遇到一个左括号就假设他是需要被删除的
            if(s[i] == '(') {
                ++lremove;
            } 
            else if(s[i] == ')'){
                if(lremove > 0) {
                    //前面存在左括号，该右括号可以和左括号匹配
                    --lremove;
                }
                else {
                    //不存在匹配，累加需要删除的右括号数量
                    ++rremove;
                }
            }
        }

        dfs(s, 0, lremove, rremove);

        return ans;
    }

    /**
     *  str 当前的字符串
     *  start 从那个字符开始寻找要删除的括号
     *  lremove 还剩余多少左括号要删除
     *  rremove 还剩余多少右括号要删除
     */
    void dfs(string str, int start, int lremove, int rremove) {
        if(lremove == 0 && rremove == 0 && isValid(str)) {
        //当前字符串不需要进行删除了，验证是否是合法的字符串，并更新答案
            ans.push_back(str);
            return;
        }

        int n = str.size();
        for(int i = start; i < n; ++i) {
            //剪枝逻辑，在当前循环中对于字符串(((()而言选择第一个左括号和还是其他左括号删除
            //都是等价的，所以每次都选择删除第一个左括号或者右括号，而跳过后面几个的重复删除逻辑
            if(i != start && str[i] == str[i - 1]) continue;

            //剩余的字符串已经不够删了，直接返回
            if((n - i) < lremove + rremove) {
                return;
            }

            //尝试删除此处的左括号
            if(lremove > 0 && str[i] == '(') {
                dfs(str.substr(0, i) + str.substr(i + 1), i, lremove - 1, rremove);
            }

            //尝试删除此处的右括号
            if(rremove > 0 && str[i] == ')') {
                dfs(str.substr(0, i) + str.substr(i + 1), i, lremove, rremove - 1);
            }
        }
    }

    inline bool isValid(string str) {
        int cnt = 0;
        int n = str.size();
        for(int i = 0; i < n; ++i) {
            if(str[i] == '(') {
                ++cnt;
            } else if(str[i] == ')') {
                --cnt;
                if(cnt < 0) {
                    return false;
                }
            }
        }

        return cnt == 0;
    }
};