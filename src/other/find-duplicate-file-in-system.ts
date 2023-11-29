export function findDuplicate(paths: string[]): string[][] {
  const contentToList = new Map<string, string[]>()
  for (const path of paths) {
    const values = path.split(' ')
    for (let i = 1; i < values.length; i++) {
      const name_cont: string[] = values[i].split('(')
      name_cont[1] = name_cont[1].replace(')', '')
      const list = contentToList.get(name_cont[1]) ?? []
      list.push(`${values[0]}/${name_cont[0]}`)
      contentToList.set(name_cont[1], list)
    }
  }
  const res: string[][] = []
  for (const key of contentToList.keys()) {
    if (contentToList.get(key)!.length > 1) {
      res.push(contentToList.get(key)!)
    }
  }
  return res
}
