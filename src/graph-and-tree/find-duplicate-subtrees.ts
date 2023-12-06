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

export function findDuplicateSubtrees(
  root: TreeNode | null
): Array<TreeNode | null> {
  // nodeVal,leftId,rightId ==> [root, id]
  const seen = new Map<string, [TreeNode, number]>()
  const repeat = new Set<TreeNode>()
  let idx = 0
  // 获取以node为根子树的id
  const dfs = (node: TreeNode | null): number => {
    if (!node) {
      return 0
    }

    const tri = [node.val, dfs(node.left), dfs(node.right)]
    const hash = tri.toString()
    if (seen.has(hash)) {
      const [node, id] = seen.get(hash)!
      repeat.add(node)
      return id
    } else {
      seen.set(hash, [node, ++idx])
      return idx
    }
  }

  dfs(root)
  return Array.from(repeat)
}
