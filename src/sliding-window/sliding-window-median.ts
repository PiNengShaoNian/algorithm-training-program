class MyTreeNode<Key, Value> {
  public size: number = 0
  public left: MyTreeNode<Key, Value> | null = null
  public right: MyTreeNode<Key, Value> | null = null
  constructor(public key: Key, public value: Value) {
    this.size = 1
  }
}

class MultiOrderedMap<Key extends string | number, Value> {
  private root: MyTreeNode<Key, Value> | null = null

  private _size(root: MyTreeNode<Key, Value> | null): number {
    return root?.size ?? 0
  }

  size(): number {
    return this._size(this.root)
  }

  put(key: Key, value: Value): void {
    this.root = this._put(this.root, key, value)
  }

  private _put(
    root: MyTreeNode<Key, Value> | null,
    key: Key,
    value: Value
  ): MyTreeNode<Key, Value> {
    if (!root) return new MyTreeNode<Key, Value>(key, value)

    if (key <= root.key) {
      root.left = this._put(root.left, key, value)
    } else {
      root.right = this._put(root.right, key, value)
    }

    root.size = this._size(root.left) + this._size(root.right) + 1
    return root
  }

  get(key: Key): Value | null {
    const node = this._get(this.root, key)

    if (!node) return null
    return node.value
  }

  private _get(
    root: MyTreeNode<Key, Value> | null,
    key: Key
  ): MyTreeNode<Key, Value> | null {
    if (!root) return null
    if (key === root.key) return root
    else if (key < root.key) {
      return this._get(root.left, key)
    } else return this._get(root.right, key)
  }

  contains(key: Key): boolean {
    return this._get(this.root, key) !== null
  }

  delete(key: Key): void {
    if (!this.contains(key)) return

    this.root = this._delete(this.root!, key)
  }

  private _min(root: MyTreeNode<Key, Value>): MyTreeNode<Key, Value> {
    if (!root.left) return root

    return this._min(root.left)
  }

  private _deleteMin(
    root: MyTreeNode<Key, Value>
  ): MyTreeNode<Key, Value> | null {
    if (!root.left) return root.right

    root.left = this._deleteMin(root.left)

    root.size = this._size(root.left) + this._size(root.right) + 1
    return root
  }

  private _delete(
    root: MyTreeNode<Key, Value>,
    key: Key
  ): MyTreeNode<Key, Value> | null {
    if (key < root.key) {
      root.left = this._delete(root.left!, key)
    } else if (key > root.key) {
      root.right = this._delete(root.right!, key)
    } else {
      if (!root.right) return root.left

      if (!root.left) return root.right

      const node = this._min(root.right)

      root.value = node.value
      root.key = node.key
      root.right = this._deleteMin(root.right)
    }

    root.size = this._size(root.left) + this._size(root.right) + 1
    return root
  }

  select(k: number): Key | null {
    if (k >= this.size() || this.size() === 0) return null

    return this._select(this.root!, k).key
  }

  private _select(
    root: MyTreeNode<Key, Value>,
    k: number
  ): MyTreeNode<Key, Value> {
    const leftTreeSize = this._size(root.left)

    if (leftTreeSize === k) return root
    else if (leftTreeSize > k) {
      return this._select(root.left!, k)
    } else return this._select(root.right!, k - leftTreeSize - 1)
  }
}

export function medianSlidingWindow(nums: number[], k: number): number[] {
  const map = new MultiOrderedMap<number, boolean>()

  const getMedian = () => {
    if (k % 2 === 0) {
      return map.select(k >> 1)! / 2 + map.select((k >> 1) - 1)! / 2
    } else return map.select(k >> 1)!
  }

  for (let i = 0; i < k; ++i) {
    map.put(nums[i], false)
  }

  const ans: number[] = []

  ans[0] = getMedian()

  for (let i = 0; i < nums.length - k; ++i) {
    map.delete(nums[i])
    map.put(nums[i + k], false)
    ans[i + 1] = getMedian()
  }

  return ans
}
