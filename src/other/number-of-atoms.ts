enum TokenType {
  Atom = 'Atom',
  LP = '(',
  RP = ')',
  Number = 'Number',
  List = 'List',
  Mul = 'Mul',
  EOF = 'EOF',
}

class Token {
  constructor(public readonly type: TokenType, public readonly literal: any) {}
}

const lex = (formula: string): Token[] => {
  let idx = 0
  const n = formula.length
  const isUpperCaseLitter = (c: string) => {
    return c >= 'a' && c <= 'z'
  }
  const isLetter = (c: string) => {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
  }
  const readAtom = () => {
    const start = idx
    idx++
    while (idx < n && isUpperCaseLitter(formula[idx])) {
      idx++
    }

    return formula.slice(start, idx)
  }

  const readNumber = () => {
    const start = idx
    while (idx < n && formula[idx] >= '0' && formula[idx] <= '9') {
      idx++
    }

    return parseInt(formula.slice(start, idx))
  }
  const tokens: Token[] = []
  while (idx < n) {
    const c = formula[idx]
    switch (c) {
      case '(': {
        idx++
        tokens.push(new Token(TokenType.LP, null))
        break
      }
      case ')': {
        idx++
        tokens.push(new Token(TokenType.RP, null))
        break
      }
      default: {
        if (isLetter(c)) {
          const atom = readAtom()
          tokens.push(new Token(TokenType.Atom, atom))
        } else if (c >= '0' && c <= '9') {
          const num = readNumber()
          tokens.push(new Token(TokenType.Number, num))
        } else {
          throw new Error(`unexpected char ${c} at ${idx}`)
        }
      }
    }
  }

  tokens.push(new Token(TokenType.EOF, null))

  return tokens
}

class MyListNode {
  readonly type = TokenType.List
  children: (MyListNode | MulNode | Token)[] = []
}

class MulNode {
  readonly type = TokenType.Mul
  left!: MyListNode | Token
  factor!: Token
}

type ASTNode = MulNode | MyListNode | Token

const parse = (tokens: Token[]): MyListNode => {
  let idx = 0

  const parseMulNode = (): MulNode | Token => {
    let left: MulNode | Token | MyListNode
    if (tokens[idx].type === TokenType.LP) {
      idx++
      left = parseListNode(TokenType.RP)
      idx++
    } else if (tokens[idx].type === TokenType.Atom) {
      left = tokens[idx]
      idx++
    }

    if (tokens[idx].type === TokenType.Number) {
      const mulNode = new MulNode()
      mulNode.left = left! as any
      mulNode.factor = tokens[idx]
      idx++
      return mulNode
    } else {
      return left! as any
    }
  }

  const parseListNode = (endTokenType: TokenType): MyListNode => {
    const node = new MyListNode()
    while (tokens[idx].type !== endTokenType) {
      const child = parseMulNode()
      node.children.push(child)
    }
    return node
  }

  return parseListNode(TokenType.EOF)
}

const evalTree = (node: MyListNode): Record<string, number> => {
  const evalMulNode = (mulNode: MulNode): Record<string, number> => {
    const left = mulNode.left
    const ans: Record<string, number> = {}
    if (left.type === TokenType.List) {
      const subAns = evalListNode(left as MyListNode)
      for (const [key, val] of Object.entries(subAns)) {
        ans[key] = (ans[key] ?? 0) + val
      }
    } else {
      ans[left.literal] = 1
    }
    const factor: number = mulNode.factor.literal
    for (const key of Object.keys(ans)) {
      ans[key] *= factor
    }
    return ans
  }
  const evalListNode = (listNode: MyListNode) => {
    const ans: Record<string, number> = {}
    for (const child of listNode.children) {
      if (child.type === TokenType.Atom) {
        ans[child.literal] = (ans[child.literal] ?? 0) + 1
      } else if (child.type === TokenType.List) {
        const subAns = evalListNode(child as MyListNode)
        for (const [key, val] of Object.entries(subAns)) {
          ans[key] = (ans[key] ?? 0) + val
        }
      } else if (child.type === TokenType.Mul) {
        const subAns = evalMulNode(child as MulNode)
        for (const [key, val] of Object.entries(subAns)) {
          ans[key] = (ans[key] ?? 0) + val
        }
      }
    }
    return ans
  }

  return evalListNode(node)
}

function countOfAtoms(formula: string): string {
  const tokens = lex(formula)
  // console.log(tokens)
  const ast = parse(tokens)
  // console.log(JSON.stringify(ast, null, 2))
  const ans = evalTree(ast)
  // console.log(ans)
  return Object.entries(ans)
    .sort(([k1], [k2]) => {
      if (k1 < k2) {
        return -1
      } else if (k1 > k2) {
        return 1
      } else {
        return 0
      }
    })
    .map(([k, v]) => (v === 1 ? k : `${k}${v}`))
    .join('')
}
