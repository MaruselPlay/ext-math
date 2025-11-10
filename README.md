This is a PHP extension that replaces PMMP math classes which slighly increases performance when working with those classes.
Currently in tests, when working with physics (movements, gravity etc.) there is x2-x3 increase in performance. Tested on PHP 8.3.

### Currently implemented:
- ✅ `pocketmine\math\Vector3`
- ✅ `pocketmine\math\AxisAlignedBB`
- ❌ `pocketmine\math\Vector2`
- ❌ `pocketmine\math\Math`
- ❌ `pocketmine\math\VectorMath`
- ❌ `pocketmine\math\RayTraceResult`
- ❌ `pocketmine\math\VoxelRayTrace`