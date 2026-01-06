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
 * Defines fundamental geometric primitives for the simulation engine.
 * Specifically, the `Rect` class provides an axis-aligned bounding box (AABB) representation,
 * essential for spatial querying and collision boundary definitions within the QuadTree.
 */

export class Rect {
  constructor(
    public x: number = 0,
    public y: number = 0,
    public w: number = 0, // width
    public h: number = 0 // height
  ) { }
}
