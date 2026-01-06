/**
 * Updates an object with a partial object [source] containing any variable on the target
 * @param target object to update
 * @param source values to update
 */
export function updateWith<T>(target: T, source: { [K in keyof T]?: T[K] }): void {
  const sourceObjectMapping = Object.keys(source).map((key) => ({ key, value: source[(key as keyof T)] })) as Array<{ key: keyof T, value: T[keyof T] }>
  sourceObjectMapping.forEach((entry) => { target[entry.key] = entry.value })
}
