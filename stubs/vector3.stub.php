<?php

/**
 * Vector3 Extension Stub File
 * 
 * This file provides IDE autocompletion and type hints for the Vector3 extension.
 * It should NOT be included in your code - it's only for development tools.
 * 
 * @version 1.0.0
 */

namespace pocketmine\math {

    /**
     * 3D Vector class for mathematical operations and 3D positioning.
     * 
     * Represents a point or direction in 3D space with x, y, and z coordinates.
     * All transformation methods return new instances (immutable), except for
     * setComponents() and fromObjectAdd() which modify the current instance.
     */
    class Vector3 {
        /**
         * X coordinate (horizontal, east-west)
         */
        public float $x;

        /**
         * Y coordinate (vertical, up-down)
         */
        public float $y;

        /**
         * Z coordinate (depth, north-south)
         */
        public float $z;

        // Direction constants
        public const int SIDE_DOWN = 0;
        public const int SIDE_UP = 1;
        public const int SIDE_NORTH = 2;
        public const int SIDE_SOUTH = 3;
        public const int SIDE_WEST = 4;
        public const int SIDE_EAST = 5;

        /**
         * Constructs a new Vector3 with the specified coordinates.
         *
         * @param float $x X coordinate (default: 0)
         * @param float $y Y coordinate (default: 0)
         * @param float $z Z coordinate (default: 0)
         */
        public function __construct(float $x = 0, float $y = 0, float $z = 0) {}

        /**
         * Gets the X coordinate.
         *
         * @return float The X coordinate
         */
        public function getX(): float {}

        /**
         * Gets the Y coordinate.
         *
         * @return float The Y coordinate
         */
        public function getY(): float {}

        /**
         * Gets the Z coordinate.
         *
         * @return float The Z coordinate
         */
        public function getZ(): float {}

        /**
         * Gets the floored X coordinate.
         *
         * @return int X coordinate rounded down
         */
        public function getFloorX(): int {}

        /**
         * Gets the floored Y coordinate.
         *
         * @return int Y coordinate rounded down
         */
        public function getFloorY(): int {}

        /**
         * Gets the floored Z coordinate.
         *
         * @return int Z coordinate rounded down
         */
        public function getFloorZ(): int {}

        /**
         * Gets the X coordinate (alias for getX).
         * Used in directional contexts where X represents right.
         *
         * @return float The X coordinate
         */
        public function getRight(): float {}

        /**
         * Gets the Y coordinate (alias for getY).
         * Used in directional contexts where Y represents up.
         *
         * @return float The Y coordinate
         */
        public function getUp(): float {}

        /**
         * Gets the Z coordinate (alias for getZ).
         * Used in directional contexts where Z represents forward.
         *
         * @return float The Z coordinate
         */
        public function getForward(): float {}

        /**
         * Gets the X coordinate (alias for getX).
         * Used in cardinal direction contexts where X represents south.
         *
         * @return float The X coordinate
         */
        public function getSouth(): float {}

        /**
         * Gets the Z coordinate (alias for getZ).
         * Used in cardinal direction contexts where Z represents west.
         *
         * @return float The Z coordinate
         */
        public function getWest(): float {}

        /**
         * Adds another vector or scalar values to this vector.
         * Returns a new Vector3 instance.
         *
         * @param Vector3|float $x Vector to add, or X value to add
         * @param float $y Y value to add (ignored if $x is Vector3)
         * @param float $z Z value to add (ignored if $x is Vector3)
         * @return Vector3 New vector with added values
         */
        public function add(Vector3|float $x, float $y = 0, float $z = 0): Vector3 {}

        /**
         * Subtracts another vector or scalar values from this vector.
         * Returns a new Vector3 instance.
         *
         * @param Vector3|float $x Vector to subtract, or X value to subtract
         * @param float $y Y value to subtract (ignored if $x is Vector3)
         * @param float $z Z value to subtract (ignored if $x is Vector3)
         * @return Vector3 New vector with subtracted values
         */
        public function subtract(Vector3|float $x, float $y = 0, float $z = 0): Vector3 {}

        /**
         * Multiplies this vector by a scalar value.
         * Returns a new Vector3 instance.
         *
         * @param float $number Multiplier
         * @return Vector3 New scaled vector
         */
        public function multiply(float $number): Vector3 {}

        /**
         * Divides this vector by a scalar value.
         * Returns a new Vector3 instance.
         *
         * @param float $number Divisor
         * @return Vector3 New divided vector
         */
        public function divide(float $number): Vector3 {}

        /**
         * Returns a new vector with all components rounded down.
         *
         * @return Vector3 New vector with floored components
         */
        public function floor(): Vector3 {}

        /**
         * Returns a new vector with all components rounded up.
         *
         * @return Vector3 New vector with ceiling components
         */
        public function ceil(): Vector3 {}

        /**
         * Returns a new vector with all components rounded.
         *
         * @param int $precision Number of decimal places (default: 0)
         * @param int $mode Rounding mode (default: PHP_ROUND_HALF_UP)
         * @return Vector3 New vector with rounded components
         */
        public function round(int $precision = 0, int $mode = 1): Vector3 {}

        /**
         * Returns a new vector with absolute values of all components.
         *
         * @return Vector3 New vector with absolute values
         */
        public function abs(): Vector3 {}

        /**
         * Gets a vector offset by a given side.
         *
         * @param int $side Side constant (SIDE_DOWN, SIDE_UP, etc.)
         * @param int $step Number of blocks to offset (default: 1)
         * @return Vector3 New offset vector
         */
        public function getSide(int $side, int $step = 1): Vector3 {}

        /**
         * Returns a vector offset downward.
         *
         * @param int $step Number of blocks down (default: 1)
         * @return Vector3 New vector offset down
         */
        public function down(int $step = 1): Vector3 {}

        /**
         * Returns a vector offset upward.
         *
         * @param int $step Number of blocks up (default: 1)
         * @return Vector3 New vector offset up
         */
        public function up(int $step = 1): Vector3 {}

        /**
         * Returns a vector offset to the north.
         *
         * @param int $step Number of blocks north (default: 1)
         * @return Vector3 New vector offset north
         */
        public function north(int $step = 1): Vector3 {}

        /**
         * Returns a vector offset to the south.
         *
         * @param int $step Number of blocks south (default: 1)
         * @return Vector3 New vector offset south
         */
        public function south(int $step = 1): Vector3 {}

        /**
         * Returns a vector offset to the west.
         *
         * @param int $step Number of blocks west (default: 1)
         * @return Vector3 New vector offset west
         */
        public function west(int $step = 1): Vector3 {}

        /**
         * Returns a vector offset to the east.
         *
         * @param int $step Number of blocks east (default: 1)
         * @return Vector3 New vector offset east
         */
        public function east(int $step = 1): Vector3 {}

        /**
         * Returns a copy of this vector as a new Vector3 instance.
         *
         * @return Vector3 Copy of this vector
         */
        public function asVector3(): Vector3 {}

        /**
         * Gets the opposite side constant.
         *
         * @param int $side Side constant
         * @return int Opposite side constant
         */
        public static function getOppositeSide(int $side): int {}

        /**
         * Calculates the distance to another vector.
         *
         * @param Vector3 $pos Target vector
         * @return float Distance
         */
        public function distance(Vector3 $pos): float {}

        /**
         * Calculates the squared distance to another vector.
         * Faster than distance() as it avoids sqrt().
         *
         * @param Vector3 $pos Target vector
         * @return float Squared distance
         */
        public function distanceSquared(Vector3 $pos): float {}

        /**
         * Gets the maximum distance on the XZ plane.
         *
         * @param Vector3|float $x Vector or X coordinate
         * @param float $z Z coordinate (ignored if $x is Vector3)
         * @return float Maximum plain distance
         */
        public function maxPlainDistance(Vector3|float $x, float $z = 0): float {}

        /**
         * Calculates the length (magnitude) of this vector.
         *
         * @return float Vector length
         */
        public function length(): float {}

        /**
         * Calculates the squared length of this vector.
         * Faster than length() as it avoids sqrt().
         *
         * @return float Squared vector length
         */
        public function lengthSquared(): float {}

        /**
         * Returns a normalized (unit) vector in the same direction.
         * A unit vector has length 1.
         *
         * @return Vector3 Normalized vector
         */
        public function normalize(): Vector3 {}

        /**
         * Calculates the dot product with another vector.
         * Useful for angle calculations and projections.
         *
         * @param Vector3 $v Other vector
         * @return float Dot product
         */
        public function dot(Vector3 $v): float {}

        /**
         * Calculates the cross product with another vector.
         * Returns a vector perpendicular to both input vectors.
         *
         * @param Vector3 $v Other vector
         * @return Vector3 Cross product vector
         */
        public function cross(Vector3 $v): Vector3 {}

        /**
         * Checks if this vector equals another vector.
         *
         * @param Vector3 $v Vector to compare
         * @return bool True if equal
         */
        public function equals(Vector3 $v): bool {}

        /**
         * Gets an intermediate point between this vector and another at a specific X.
         * Used for ray-line intersections.
         *
         * @param Vector3 $v Target vector
         * @param float $x X coordinate to find intermediate point at
         * @return Vector3|null Intermediate point, or null if not in range
         */
        public function getIntermediateWithXValue(Vector3 $v, float $x): ?Vector3 {}

        /**
         * Gets an intermediate point between this vector and another at a specific Y.
         * Used for ray-line intersections.
         *
         * @param Vector3 $v Target vector
         * @param float $y Y coordinate to find intermediate point at
         * @return Vector3|null Intermediate point, or null if not in range
         */
        public function getIntermediateWithYValue(Vector3 $v, float $y): ?Vector3 {}

        /**
         * Gets an intermediate point between this vector and another at a specific Z.
         * Used for ray-line intersections.
         *
         * @param Vector3 $v Target vector
         * @param float $z Z coordinate to find intermediate point at
         * @return Vector3|null Intermediate point, or null if not in range
         */
        public function getIntermediateWithZValue(Vector3 $v, float $z): ?Vector3 {}

        /**
         * Sets the components of this vector.
         * This method MODIFIES the current instance.
         *
         * @param float $x New X coordinate
         * @param float $y New Y coordinate
         * @param float $z New Z coordinate
         * @return $this This vector for method chaining
         */
        public function setComponents(float $x, float $y, float $z): static {}

        /**
         * Sets this vector's values from another vector plus offsets.
         * This method MODIFIES the current instance.
         *
         * @param Vector3 $pos Source vector
         * @param float $x X offset to add
         * @param float $y Y offset to add
         * @param float $z Z offset to add
         * @return $this This vector for method chaining
         */
        public function fromObjectAdd(Vector3 $pos, float $x, float $y, float $z): static {}

        /**
         * Returns a string representation of this vector.
         *
         * @return string String representation
         */
        public function __toString(): string {}
    }
}
