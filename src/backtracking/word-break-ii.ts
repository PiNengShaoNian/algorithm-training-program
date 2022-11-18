function wordBreak(s: string, wordDict: string[]): string[] {
    const ans: string[] = []
    const n = s.length
    const wordSet = new Set<string>(wordDict);

    const dfs = (idx: number, paths: string[]): void => {
        if (idx >= n) {
            ans.push(paths.join(' '))
            return
        }

        for (let i = 1; i <= 10 && i + idx <= n; ++i) {
            const cand = s.substr(idx, i)
            if (!wordSet.has(cand)) continue
            paths.push(cand)
            dfs(idx + i, paths)
            paths.pop()
        }
    }

    dfs(0, [])

    return ans
};