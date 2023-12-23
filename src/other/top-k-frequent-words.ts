function topKFrequent(words: string[], k: number): string[] {
  const wordToFre: Record<string, number> = {}

  for (const word of words) {
    wordToFre[word] = (wordToFre[word] ?? 0) + 1
  }

  return Object.entries(wordToFre)
    .sort((a, b) => {
      if (b[1] !== a[1]) {
        return b[1] - a[1]
      } else {
        if (a[0] > b[0]) {
          return 1
        } else {
          return -1
        }
      }
    })
    .slice(0, k)
    .map((v) => v[0])
}
