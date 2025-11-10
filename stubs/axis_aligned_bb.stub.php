<?php

/**
 * AxisAlignedBB Extension Stub File
 * 
 * This file provides IDE autocompletion and type hints for the AxisAlignedBB extension.
 * It should NOT be included in your code - it's only for development tools.
 * 
 * @author MaruselPlay
 * @version 1.0.0
 */

namespace pocketmine\math;

/**
 * Axis-Aligned Bounding Box (AABB) class for 3D collision detection and spatial calculations.
 * 
 * An AABB is defined by two 3D points: the minimum corner (minX, minY, minZ) 
 * and the maximum corner (maxX, maxY, maxZ).
 */
class AxisAlignedBB
{
    /**
     * Minimum X coordinate of the bounding box
     */
    public float $minX;

    /**
     * Minimum Y coordinate of the bounding box
     */
    public float $minY;

    /**
     * Minimum Z coordinate of the bounding box
     */
    public float $minZ;

    /**
     * Maximum X coordinate of the bounding box
     */
    public float $maxX;

    /**
     * Maximum Y coordinate of the bounding box
     */
    public float $maxY;

    /**
     * Maximum Z coordinate of the bounding box
     */
    public float $maxZ;

    /**
     * Constructs a new AxisAlignedBB with the specified bounds.
     *
     * @param float $minX Minimum X coordinate
     * @param float $minY Minimum Y coordinate
     * @param float $minZ Minimum Z coordinate
     * @param float $maxX Maximum X coordinate
     * @param float $maxY Maximum Y coordinate
     * @param float $maxZ Maximum Z coordinate
     */
    public function __construct(float $minX, float $minY, float $minZ, float $maxX, float $maxY, float $maxZ) {}

    /**
     * Creates a unit bounding box (0,0,0) to (1,1,1).
     *
     * @return AxisAlignedBB A new 1x1x1 bounding box
     */
    public static function one(): AxisAlignedBB {}

    /**
     * Sets the bounds of this bounding box.
     *
     * @param float $minX Minimum X coordinate
     * @param float $minY Minimum Y coordinate
     * @param float $minZ Minimum Z coordinate
     * @param float $maxX Maximum X coordinate
     * @param float $maxY Maximum Y coordinate
     * @param float $maxZ Maximum Z coordinate
     * @return AxisAlignedBB This bounding box (for method chaining)
     */
    public function setBounds(float $minX, float $minY, float $minZ, float $maxX, float $maxY, float $maxZ): AxisAlignedBB {}

    /**
     * Creates a new bounding box extended in the direction of the given coordinates.
     * If a coordinate is negative, it extends the minimum; if positive, extends the maximum.
     *
     * @param float $x X offset
     * @param float $y Y offset
     * @param float $z Z offset
     * @return AxisAlignedBB A new extended bounding box
     */
    public function addCoord(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Creates a new bounding box grown in all directions by the specified amounts.
     * Decreases minimums and increases maximums.
     *
     * @param float $x Amount to grow in X direction
     * @param float $y Amount to grow in Y direction
     * @param float $z Amount to grow in Z direction
     * @return AxisAlignedBB A new grown bounding box
     */
    public function grow(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Expands this bounding box in all directions by the specified amounts.
     * Modifies this instance.
     *
     * @param float $x Amount to expand in X direction
     * @param float $y Amount to expand in Y direction
     * @param float $z Amount to expand in Z direction
     * @return AxisAlignedBB This bounding box (for method chaining)
     */
    public function expand(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Creates a copy of this bounding box expanded in all directions.
     * Does not modify this instance.
     *
     * @param float $x Amount to expand in X direction
     * @param float $y Amount to expand in Y direction
     * @param float $z Amount to expand in Z direction
     * @return AxisAlignedBB A new expanded bounding box
     */
    public function expandedCopy(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Offsets this bounding box by the specified amounts.
     * Modifies this instance.
     *
     * @param float $x X offset
     * @param float $y Y offset
     * @param float $z Z offset
     * @return AxisAlignedBB This bounding box (for method chaining)
     */
    public function offset(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Creates a copy of this bounding box offset by the specified amounts.
     * Does not modify this instance.
     *
     * @param float $x X offset
     * @param float $y Y offset
     * @param float $z Z offset
     * @return AxisAlignedBB A new offset bounding box
     */
    public function offsetCopy(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Creates a new bounding box shrunk in all directions by the specified amounts.
     * Increases minimums and decreases maximums.
     *
     * @param float $x Amount to shrink in X direction
     * @param float $y Amount to shrink in Y direction
     * @param float $z Amount to shrink in Z direction
     * @return AxisAlignedBB A new shrunk bounding box
     */
    public function shrink(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Contracts this bounding box in all directions by the specified amounts.
     * Modifies this instance.
     *
     * @param float $x Amount to contract in X direction
     * @param float $y Amount to contract in Y direction
     * @param float $z Amount to contract in Z direction
     * @return AxisAlignedBB This bounding box (for method chaining)
     */
    public function contract(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Creates a copy of this bounding box contracted in all directions.
     * Does not modify this instance.
     *
     * @param float $x Amount to contract in X direction
     * @param float $y Amount to contract in Y direction
     * @param float $z Amount to contract in Z direction
     * @return AxisAlignedBB A new contracted bounding box
     */
    public function contractedCopy(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Checks if this bounding box is equal to another bounding box.
     *
     * @param AxisAlignedBB $bb The bounding box to compare with
     * @return bool True if all coordinates are equal
     */
    public function equals(AxisAlignedBB $bb): bool {}

    /**
     * Sets this bounding box to match another bounding box.
     * Modifies this instance.
     *
     * @param AxisAlignedBB $bb The bounding box to copy from
     * @return AxisAlignedBB This bounding box (for method chaining)
     */
    public function setBB(AxisAlignedBB $bb): AxisAlignedBB {}

    /**
     * Creates a new bounding box offset by the specified amounts.
     * Alias for offsetCopy().
     *
     * @param float $x X offset
     * @param float $y Y offset
     * @param float $z Z offset
     * @return AxisAlignedBB A new offset bounding box
     */
    public function getOffsetBoundingBox(float $x, float $y, float $z): AxisAlignedBB {}

    /**
     * Calculates the X offset needed to prevent collision with another bounding box.
     * Used for collision response in physics calculations.
     *
     * @param AxisAlignedBB $bb The other bounding box
     * @param float $x The proposed X movement
     * @return float The adjusted X offset that prevents overlap
     */
    public function calculateXOffset(AxisAlignedBB $bb, float $x): float {}

    /**
     * Calculates the Y offset needed to prevent collision with another bounding box.
     * Used for collision response in physics calculations.
     *
     * @param AxisAlignedBB $bb The other bounding box
     * @param float $y The proposed Y movement
     * @return float The adjusted Y offset that prevents overlap
     */
    public function calculateYOffset(AxisAlignedBB $bb, float $y): float {}

    /**
     * Calculates the Z offset needed to prevent collision with another bounding box.
     * Used for collision response in physics calculations.
     *
     * @param AxisAlignedBB $bb The other bounding box
     * @param float $z The proposed Z movement
     * @return float The adjusted Z offset that prevents overlap
     */
    public function calculateZOffset(AxisAlignedBB $bb, float $z): float {}

    /**
     * Checks if this bounding box intersects with another bounding box.
     *
     * @param AxisAlignedBB $bb The other bounding box to check
     * @param float $epsilon Minimum overlap distance to consider as intersection (default: 0.00001)
     * @return bool True if the bounding boxes intersect
     */
    public function intersectsWith(AxisAlignedBB $bb, float $epsilon = 0.00001): bool {}

    /**
     * Checks if a 3D point (vector) is inside this bounding box.
     *
     * @param Vector3 $vector The point to check
     * @return bool True if the point is inside the bounding box
     */
    public function isVectorInside(Vector3 $vector): bool {}

    /**
     * Calculates the average length of all edges of this bounding box.
     *
     * @return float The average edge length
     */
    public function getAverageEdgeLength(): float {}

    /**
     * Checks if a point is within the Y-Z plane bounds of this bounding box.
     *
     * @param Vector3 $vector The point to check
     * @return bool True if the point's Y and Z coordinates are within bounds
     */
    public function isVectorInYZ(Vector3 $vector): bool {}

    /**
     * Checks if a point is within the X-Z plane bounds of this bounding box.
     *
     * @param Vector3 $vector The point to check
     * @return bool True if the point's X and Z coordinates are within bounds
     */
    public function isVectorInXZ(Vector3 $vector): bool {}

    /**
     * Checks if a point is within the X-Y plane bounds of this bounding box.
     *
     * @param Vector3 $vector The point to check
     * @return bool True if the point's X and Y coordinates are within bounds
     */
    public function isVectorInXY(Vector3 $vector): bool {}

    /**
     * Calculates the intersection point of a ray with this bounding box.
     * Used for ray tracing and line-of-sight calculations.
     *
     * @param Vector3 $pos1 Start position of the ray
     * @param Vector3 $pos2 End position of the ray
     * @return mixed RayTraceResult if the ray intersects, null otherwise
     */
    public function calculateIntercept(Vector3 $pos1, Vector3 $pos2): mixed {}

    /**
     * Returns a string representation of this bounding box.
     *
     * @return string A formatted string showing all coordinates
     */
    public function __toString(): string {}
}
