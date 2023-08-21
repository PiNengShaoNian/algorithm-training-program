declare class TreeNode {
  public val: number
  public left: TreeNode | null
  public right: TreeNode | null
  constructor(val: number, left: TreeNode | null, right: TreeNode | null)
}

export function serialize(root: TreeNode | null): string {
  if (!root) return ''
  const ans: number[] = []
  const traverse = (node: TreeNode | null) => {
    if (!node) {
      ans.push(Infinity)
      return
    }

    ans.push(node.val)
    traverse(node.left)
    traverse(node.right)
  }

  traverse(root)
  return ans.join(',')
}

/*
 * Decodes your encoded data to tree.
 */
export function deserialize(data: string): TreeNode | null {
  if (!data.length) return null
  const nodes = data.split(',').map((v) => Number(v))
  let idx = 0
  const buildTree = (): TreeNode | null => {
    if (!isFinite(nodes[idx])) {
      ++idx
      return null
    }

    const root = new TreeNode(nodes[idx], null, null)
    idx++
    root.left = buildTree()
    root.right = buildTree()

    return root
  }

  return buildTree()
}
