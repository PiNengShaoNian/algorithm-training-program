function compareVersion(version1: string, version2: string): number {
    const v1 = version1.split('.').map(v => parseInt(v));
    const v2 = version2.split('.').map(v => parseInt(v));

    for (let i1 = 0, i2 = 0; i1 < v1.length || i2 < v2.length; i1++, i2++) {
        const num1 = v1[i1] ?? 0;
        const num2 = v2[i2] ?? 0;
        if (num1 === num2) {
            continue;
        }

        return num1 < num2 ? -1 : 1;
    }

    return 0;
};