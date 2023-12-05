class Trie {
  children: Record<string, Trie> = {}
}

function replaceWords(dictionary: string[], sentence: string): string {
  const root = new Trie()
  for (const word of dictionary) {
    let cur = root
    for (const c of word) {
      if (!cur.children[c]) {
        cur.children[c] = new Trie()
      }
      cur = cur.children[c]
    }
    cur.children['#'] = new Trie()
  }

  const findRoot = (word: string): string => {
    let cur = root
    let ans = ''
    for (const c of word) {
      if (cur.children['#']) {
        return ans
      }

      if (!cur.children[c]) {
        return word
      }

      cur = cur.children[c]
      ans += c
    }

    return word
  }
  const words = sentence.split(' ')
  for (let i = 0; i < words.length; i++) {
    const word = words[i]
    words[i] = findRoot(word)
  }

  return words.join(' ')
}
