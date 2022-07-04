class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    //和LIS一样的思路不过是二维的
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //我们先按照宽度按照升序排序，然后只剩下高度一个维度，然后就可以按照LIS的思路来解题了
        //这里有个细节考虑envelopes：[[1,1],[2,2],[2,3]]，根据题意只有宽高都大于的情况下才能
        //嵌套，所以[2,2]不能放进[2,3],但是如果只按照宽度进行升序排序，此时的高度形成的序列
        //就为[1,2,3]满足LIS的条件，但是实际最大的嵌套层数只能为2,此时如果我们再加入一个限制条件
        //在宽度相同的情况下，再按照高度降序排序此时高度组成的序列就为[1,3,2],此时计算出的答案就
        //是正确的，应为我们能保证，在宽度相同的所有信封我们最多只会挑出一个把他加入LIS中，这样
        //我们就能保证宽度相同的信封不会被重复假如，产生错误的答案
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) -> bool {
            if(a[0] == b[0]) {
                return a[1] > b[1]; 
            }
            return a[0] < b[0];
        });
        int n = envelopes.size();
        vector<int> vec;

        for(int i = 0; i < n; ++i) {
            int p = lower_bound(vec.begin(), vec.end(), envelopes[i][1]) - vec.begin();

            if(p < (int)vec.size()) {
                vec[p] = envelopes[i][1];
            }
            else {
                vec.push_back(envelopes[i][1]);
            }
        }

        return (int)vec.size();
    }
};