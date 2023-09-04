/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

/*
 * Encodes a tree to a single string.
 */
declare class TreeNode {
  public val: number
  public left: TreeNode | null
  public right: TreeNode | null
  constructor(val: number, left?: TreeNode | null, right?: TreeNode | null)
}

function serialize(root: TreeNode | null): string {
  const ans: string[] = []

  const dfs = (node: TreeNode | null): void => {
    if (!node) {
      ans.push('$')
      return
    }

    ans.push(node.val.toString())
    dfs(node.left)
    dfs(node.right)
  }

  dfs(root)

  return ans.join(',')
}

/*
 * Decodes your encoded data to tree.
 */
function deserialize(data: string): TreeNode | null {
  const NULL_VAL = 1e9
  const vals: number[] = data.split(',').map((v) => {
    return v === '$' ? 1e9 : parseInt(v)
  })
  let idx = 0
  const dfs = (): TreeNode | null => {
    if (vals[idx] === NULL_VAL) {
      idx++
      return null
    }

    const root = new TreeNode(vals[idx])
    idx++
    root.left = dfs()
    root.right = dfs()

    return root
  }

  return dfs()
}

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */
