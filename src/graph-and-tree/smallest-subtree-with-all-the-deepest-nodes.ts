export function subtreeWithAllDeepest(root: TreeNode | null): TreeNode | null {
  type LCA = [node: TreeNode | null, depth: number]

  const Impl = (node: TreeNode | null): LCA => {
    if (!node) {
      return [null, 0]
    }

    const left = Impl(node.left)
    const right = Impl(node.right)

    if (left[1] > right[1]) {
      return [left[0], left[1] + 1]
    }

    if (right[1] > left[1]) {
      return [right[0], right[1] + 1]
    }

    return [node, left[1] + 1]
  }

  return Impl(root)[0]
}
