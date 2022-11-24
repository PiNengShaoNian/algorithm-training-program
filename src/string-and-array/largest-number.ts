function largestNumber(nums: number[]): string {
    const ans = nums.map(v => v.toString()).sort((a, b) => {
        const ab = a + b
        const ba = b + a
        return +ba - +ab
    }).join('')

    let i = 0;
    const len = ans.length;
    for(;i < len - 1;) {
        if(ans[i] === '0') {
            ++i
        } else {
            break;
        }
    }

    return ans.slice(i)
};