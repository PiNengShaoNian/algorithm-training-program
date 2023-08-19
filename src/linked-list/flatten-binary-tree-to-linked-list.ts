declare type TreeNode = any

export function flatten(node: TreeNode | null): void {
  let preNode: TreeNode | null = null
  const Impl = (root: TreeNode | null) => {
    if (!root) {
      return
    }

    Impl(root.right)
    Impl(root.left)

    root.left = null
    root.right = preNode
    preNode = root
  }

  Impl(node)
}
