// 暴力解法
class NestedIterator
{
public:
    deque<int> list;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (auto &x : nestedList)
        {
            flatten(x);
        }
    }

    void flatten(NestedInteger &i)
    {
        if (i.isInteger())
        {
            list.push_back(i.getInteger());
        }
        else
        {
            for (auto &x : i.getList())
            {
                flatten(x);
            }
        }
    }

    int next()
    {
        int ans = list.front();
        list.pop_front();
        return ans;
    }

    bool hasNext()
    {
        return !list.empty();
    }
};

// 均摊复杂度解法
class NestedIterator
{
public:
    using Iter = vector<NestedInteger>::iterator;
    using Pair = pair<Iter, Iter>;

    vector<Pair> stk;
    NestedIterator(vector<NestedInteger> &nestedList) : stk({{nestedList.begin(), nestedList.end()}})
    {
    }

    int next()
    {
        auto &[it1, it2] = stk.back();
        int ans = it1->getInteger();
        ++it1;
        return ans;
    }

    bool hasNext()
    {
        while (!stk.empty())
        {
            auto &[begin, end] = stk.back();

            if (begin == end)
            {
                stk.pop_back();
                continue;
            }

            if (begin->isInteger())
            {
                return true;
            }

            auto &newPair = begin->getList();
            ++begin;
            stk.emplace_back(newPair.begin(), newPair.end());
        }

        return false;
    }
};