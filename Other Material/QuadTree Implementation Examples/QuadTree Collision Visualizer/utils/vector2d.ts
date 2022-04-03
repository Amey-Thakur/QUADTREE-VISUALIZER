/**
 * 2D Vector representation with functional utilities,
 * majority physics related
 */
export class Vector2D {
  constructor(public x: number = 0, public y: number = 0) { }

  /**
   * useful for avoiding the sqaure root calculation when necessary
   */
  get sqrMagnitude(): number {
    return this.x * this.x + this.y * this.y
  }

  /**
   * scalar length quantity of the vector 
   */
  get magnitude(): number {
    return Math.sqrt(this.x * this.x + this.y * this.y)
  }

  /**
   * Flips the vector 180 degrees
   */
  reversed(): Vector2D {
    return this.scale(-1)
  }

  /**
   * Returns the unit vector of the current vector
   */
  normalized(): Vector2D {
    const mag = this.magnitude
    return new Vector2D(
      this.x / mag,
      this.y / mag
    )
  }

  /**
   * calculate the cosine of the angle between two vectors using the dot product identity
   * @param vector other vector
   * @returns cosine of the angle between the vectors
   */
  cosineAngleBetween(vector: Vector2D): number {
    return this.dot(vector) / Math.sqrt(this.sqrMagnitude * vector.sqrMagnitude)
  }

  /**
   * calculate angle between two vectors using the dot product identity
   * @param vector other vector
   * @returns angle between in radians
   */
  angleBetween(vector: Vector2D): number {
    return Math.acos(this.dot(vector) / Math.sqrt(this.sqrMagnitude * vector.sqrMagnitude))
  }

  /**
   * Dot product of this vector with another
   * @param vector other vector
   */
  dot(vector: Vector2D): number {
    return this.x * vector.x + this.y * vector.y
  }

  /**
   * A new vector equal to the current vector plus another
   * @param vector other vector
   */
  plus(vector: Vector2D): Vector2D {
    return new Vector2D(
      this.x + vector.x,
      this.y + vector.y
    )
  }

  /**
   * A new vector equal to the current vector rotated a number of radians
   * @param radians radians to rotate the vector
   */
  rotated(radians: number): Vector2D {
    return new Vector2D(
      this.x * Math.cos(radians) - this.y * Math.sin(radians),
      this.x * Math.sin(radians) - this.y * Math.cos(radians)
    )
  }

  /**
   * The difference between two vectors, with the current as the start point
   * @param vector other vector
   */
  vectorTo(vector: Vector2D): Vector2D {
    return new Vector2D(
      vector.x - this.x,
      vector.y - this.y
    )
  }

  /**
   * Creates a new vector scaled by an amount
   * @param factor scalar to resize the vector
   */
  scale(factor: number): Vector2D {
    return new Vector2D(
      this.x * factor,
      this.y * factor
    )
  }
}
