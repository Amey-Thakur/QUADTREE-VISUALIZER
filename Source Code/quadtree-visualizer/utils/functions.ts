/**
 * Author: Amey Thakur
 * GitHub: https://github.com/Amey-Thakur
 *
 * Author: Mega Satish
 * GitHub: https://github.com/msatmod
 *
 * Author: Hasan Rizvi
 * GitHub: https://github.com/rizvihasan
 *
 * Project: QUADTREE-VISUALIZER
 * Group: Phi-CS-73
 * Batch: 2022
 * Repo: https://github.com/Amey-Thakur/QUADTREE-VISUALIZER
 * Date: 2022-04-25
 * License: MIT
 *
 * Developed as part of the BE Major-Project @ Terna Engineering College.
 *
 * Provides generic utility functions for state updates and immutable object manipulation.
 * Used primarily to perform type-safe partial updates on state interfaces without mutating references directly.
 */

/**
 * Updates an object with a partial object [source] containing any variable on the target
 * @param target object to update
 * @param source values to update
 */
export function updateWith<T>(target: T, source: { [K in keyof T]?: T[K] }): void {
  const sourceObjectMapping = Object.keys(source).map((key) => ({ key, value: source[(key as keyof T)] })) as Array<{ key: keyof T, value: T[keyof T] }>
  sourceObjectMapping.forEach((entry) => { target[entry.key] = entry.value })
}
