class Solution
{
public:
    int shortestWay(string source, string target)
    {
        int ans = 1;
        string::size_type cur = 0;

        for (char c : target)
        {
            string::size_type t = source.find(c, cur);

            if (t == string::npos)
            {
                t = source.find(c);

                if (t == string::npos)
                    return -1;

                ++ans;
            }

            cur = t + 1;
        }

        return ans;
    }
};

class Solution1
{
public:
    bool isSubSeq(string &sub, string s)
    {
        int cur = 0;
        int n = sub.size();

        for (char c : s)
        {
            if (cur >= n)
                break;
            if (c == sub[cur])
                ++cur;
        }

        return cur >= n;
    }

    int shortestWay(string source, string target)
    {
        int count[26] = {0};

        for (char c : source)
            count[c - 'a'] = 1;

        for (char c : target)
            if (!count[c - 'a'])
                return -1;

        int ans = 1;
        string tmp = "";
        for (char c : target)
        {
            tmp += c;
            if (!isSubSeq(tmp, source))
            {
                tmp = "";
                tmp += c;

                ans++;
            }
        }

        return ans;
    }
};