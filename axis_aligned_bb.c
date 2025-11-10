#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_math.h"
#include "math.h"

zend_class_entry *axis_aligned_bb_ce;
zend_object_handlers axis_aligned_bb_handlers;

ZEND_BEGIN_ARG_INFO_EX(arginfo_axis_aligned_bb_construct, 0, 0, 6)
	ZEND_ARG_TYPE_INFO(0, minX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, minY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, minZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_one, 0, 0, pocketmine\\math\\AxisAlignedBB, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_setBounds, 0, 6, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, minX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, minY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, minZ, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxX, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxY, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxZ, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_addCoord, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_grow, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_expand, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_expandedCopy, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_offset, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_offsetCopy, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_shrink, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_contract, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_contractedCopy, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_equals, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, bb, pocketmine\\math\\AxisAlignedBB, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_setBB, 0, 1, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_OBJ_INFO(0, bb, pocketmine\\math\\AxisAlignedBB, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_axis_aligned_bb_getOffsetBoundingBox, 0, 3, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_calculateXOffset, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, bb, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_calculateYOffset, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, bb, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_calculateZOffset, 0, 2, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, bb, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_intersectsWith, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, bb, pocketmine\\math\\AxisAlignedBB, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, epsilon, IS_DOUBLE, 0, "0.00001")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_isVectorInside, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, vector, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_getAverageEdgeLength, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_isVectorInYZ, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, vector, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_isVectorInXZ, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, vector, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_isVectorInXY, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, vector, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_calculateIntercept, 0, 2, IS_MIXED, 1)
	ZEND_ARG_OBJ_INFO(0, pos1, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_OBJ_INFO(0, pos2, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_axis_aligned_bb_toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

zend_object *axis_aligned_bb_create_object(zend_class_entry *ce)
{
  axis_aligned_bb_object *obj = zend_object_alloc(sizeof(axis_aligned_bb_object), ce);
  obj->minX = 0.0;
  obj->minY = 0.0;
  obj->minZ = 0.0;
  obj->maxX = 0.0;
  obj->maxY = 0.0;
  obj->maxZ = 0.0;
  
  zend_object_std_init(&obj->std, ce);
  object_properties_init(&obj->std, ce);
  obj->std.handlers = &axis_aligned_bb_handlers;
  
  return &obj->std;
}

void axis_aligned_bb_free_object(zend_object *obj)
{
	zend_object_std_dtor(obj);
}

zval *axis_aligned_bb_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
  axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_OBJ(object);
  const char *name = ZSTR_VAL(member);
  
  if (strcmp(name, "minX") == 0) {
    ZVAL_DOUBLE(rv, obj->minX);
  } else if (strcmp(name, "minY") == 0) {
    ZVAL_DOUBLE(rv, obj->minY);
  } else if (strcmp(name, "minZ") == 0) {
    ZVAL_DOUBLE(rv, obj->minZ);
  } else if (strcmp(name, "maxX") == 0) {
    ZVAL_DOUBLE(rv, obj->maxX);
  } else if (strcmp(name, "maxY") == 0) {
    ZVAL_DOUBLE(rv, obj->maxY);
  } else if (strcmp(name, "maxZ") == 0) {
    ZVAL_DOUBLE(rv, obj->maxZ);
  } else {
    return zend_std_read_property(object, member, type, cache_slot, rv);
  }
  
  return rv;
}

HashTable *axis_aligned_bb_get_properties(zend_object *object)
{
  axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_OBJ(object);
  HashTable *props = zend_std_get_properties(object);
  zval zv;
  
  ZVAL_DOUBLE(&zv, obj->minX);
  zend_hash_str_update(props, "minX", sizeof("minX")-1, &zv);
  ZVAL_DOUBLE(&zv, obj->minY);
  zend_hash_str_update(props, "minY", sizeof("minY")-1, &zv);
  ZVAL_DOUBLE(&zv, obj->minZ);
  zend_hash_str_update(props, "minZ", sizeof("minZ")-1, &zv);
  ZVAL_DOUBLE(&zv, obj->maxX);
  zend_hash_str_update(props, "maxX", sizeof("maxX")-1, &zv);
  ZVAL_DOUBLE(&zv, obj->maxY);
  zend_hash_str_update(props, "maxY", sizeof("maxY")-1, &zv);
  ZVAL_DOUBLE(&zv, obj->maxZ);
  zend_hash_str_update(props, "maxZ", sizeof("maxZ")-1, &zv);
  
  return props;
}

zval *axis_aligned_bb_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
  axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_OBJ(object);
  const char *name = ZSTR_VAL(member);
  
  if (strcmp(name, "minX") == 0) {
    obj->minX = zval_get_double(value);
  } else if (strcmp(name, "minY") == 0) {
    obj->minY = zval_get_double(value);
  } else if (strcmp(name, "minZ") == 0) {
    obj->minZ = zval_get_double(value);
  } else if (strcmp(name, "maxX") == 0) {
    obj->maxX = zval_get_double(value);
  } else if (strcmp(name, "maxY") == 0) {
    obj->maxY = zval_get_double(value);
  } else if (strcmp(name, "maxZ") == 0) {
    obj->maxZ = zval_get_double(value);
  } else {
    return zend_std_write_property(object, member, value, cache_slot);
  }
  
  return value;
}

zend_object *axis_aligned_bb_clone_obj(zend_object *object)
{
  axis_aligned_bb_object *old_obj = AXIS_ALIGNED_BB_FROM_OBJ(object);
  
  zend_object *new_obj_zend = axis_aligned_bb_create_object(object->ce);
  axis_aligned_bb_object *new_obj = AXIS_ALIGNED_BB_FROM_OBJ(new_obj_zend);
  
  new_obj->minX = old_obj->minX;
  new_obj->minY = old_obj->minY;
  new_obj->minZ = old_obj->minZ;
  new_obj->maxX = old_obj->maxX;
  new_obj->maxY = old_obj->maxY;
  new_obj->maxZ = old_obj->maxZ;
  
  zend_objects_clone_members(new_obj_zend, object);
  
  return new_obj_zend;
}


PHP_METHOD(AxisAlignedBB, __construct)
{
	double minX, minY, minZ, maxX, maxY, maxZ;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_DOUBLE(minX)
		Z_PARAM_DOUBLE(minY)
		Z_PARAM_DOUBLE(minZ)
		Z_PARAM_DOUBLE(maxX)
		Z_PARAM_DOUBLE(maxY)
		Z_PARAM_DOUBLE(maxZ)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);

	obj->minX = minX;
	obj->minY = minY;
	obj->minZ = minZ;
	obj->maxX = maxX;
	obj->maxY = maxY;
	obj->maxZ = maxZ;
}

PHP_METHOD(AxisAlignedBB, one)
{
	ZEND_PARSE_PARAMETERS_NONE();

	object_init_ex(return_value, axis_aligned_bb_ce);
	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(return_value);
	obj->minX = 0.0;
	obj->minY = 0.0;
	obj->minZ = 0.0;
	obj->maxX = 1.0;
	obj->maxY = 1.0;
	obj->maxZ = 1.0;
}

PHP_METHOD(AxisAlignedBB, setBounds)
{
	double minX, minY, minZ, maxX, maxY, maxZ;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_DOUBLE(minX)
		Z_PARAM_DOUBLE(minY)
		Z_PARAM_DOUBLE(minZ)
		Z_PARAM_DOUBLE(maxX)
		Z_PARAM_DOUBLE(maxY)
		Z_PARAM_DOUBLE(maxZ)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	obj->minX = minX;
	obj->minY = minY;
	obj->minZ = minZ;
	obj->maxX = maxX;
	obj->maxY = maxY;
	obj->maxZ = maxZ;

	RETURN_ZVAL(ZEND_THIS, 1, 0);
}

PHP_METHOD(AxisAlignedBB, addCoord)
{
  double x, y, z;

  ZEND_PARSE_PARAMETERS_START(3, 3)
    Z_PARAM_DOUBLE(x)
    Z_PARAM_DOUBLE(y)
    Z_PARAM_DOUBLE(z)
  ZEND_PARSE_PARAMETERS_END();

  axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
  
  double minX = obj->minX;
  double minY = obj->minY;
  double minZ = obj->minZ;
  double maxX = obj->maxX;
  double maxY = obj->maxY;
  double maxZ = obj->maxZ;

  if (x < 0.0) {
    minX += x;
  } else if (x > 0.0) {
    maxX += x;
  }

  if (y < 0.0) {
    minY += y;
  } else if (y > 0.0) {
    maxY += y;
  }

  if (z < 0.0) {
    minZ += z;
  } else if (z > 0.0) {
    maxZ += z;
  }

  object_init_ex(return_value, axis_aligned_bb_ce);
  axis_aligned_bb_object *result = AXIS_ALIGNED_BB_FROM_Z(return_value);
  
  result->minX = minX;
  result->minY = minY;
  result->minZ = minZ;
  result->maxX = maxX;
  result->maxY = maxY;
  result->maxZ = maxZ;
}

PHP_METHOD(AxisAlignedBB, grow)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);

	object_init_ex(return_value, axis_aligned_bb_ce);
	axis_aligned_bb_object *result = AXIS_ALIGNED_BB_FROM_Z(return_value);
	result->minX = obj->minX - x;
	result->minY = obj->minY - y;
	result->minZ = obj->minZ - z;
	result->maxX = obj->maxX + x;
	result->maxY = obj->maxY + y;
	result->maxZ = obj->maxZ + z;
}

PHP_METHOD(AxisAlignedBB, expand)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	obj->minX -= x;
	obj->minY -= y;
	obj->minZ -= z;
	obj->maxX += x;
	obj->maxY += y;
	obj->maxZ += z;

	RETURN_ZVAL(ZEND_THIS, 1, 0);
}

PHP_METHOD(AxisAlignedBB, expandedCopy)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);

	object_init_ex(return_value, axis_aligned_bb_ce);
	axis_aligned_bb_object *result = AXIS_ALIGNED_BB_FROM_Z(return_value);
	result->minX = obj->minX - x;
	result->minY = obj->minY - y;
	result->minZ = obj->minZ - z;
	result->maxX = obj->maxX + x;
	result->maxY = obj->maxY + y;
	result->maxZ = obj->maxZ + z;
}

PHP_METHOD(AxisAlignedBB, offset)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	obj->minX += x;
	obj->minY += y;
	obj->minZ += z;
	obj->maxX += x;
	obj->maxY += y;
	obj->maxZ += z;

	RETURN_ZVAL(ZEND_THIS, 1, 0);
}

PHP_METHOD(AxisAlignedBB, offsetCopy)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);

	object_init_ex(return_value, axis_aligned_bb_ce);
	axis_aligned_bb_object *result = AXIS_ALIGNED_BB_FROM_Z(return_value);
	result->minX = obj->minX + x;
	result->minY = obj->minY + y;
	result->minZ = obj->minZ + z;
	result->maxX = obj->maxX + x;
	result->maxY = obj->maxY + y;
	result->maxZ = obj->maxZ + z;
}

PHP_METHOD(AxisAlignedBB, shrink)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);

	object_init_ex(return_value, axis_aligned_bb_ce);
	axis_aligned_bb_object *result = AXIS_ALIGNED_BB_FROM_Z(return_value);
	result->minX = obj->minX + x;
	result->minY = obj->minY + y;
	result->minZ = obj->minZ + z;
	result->maxX = obj->maxX - x;
	result->maxY = obj->maxY - y;
	result->maxZ = obj->maxZ - z;
}

PHP_METHOD(AxisAlignedBB, contract)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	obj->minX += x;
	obj->minY += y;
	obj->minZ += z;
	obj->maxX -= x;
	obj->maxY -= y;
	obj->maxZ -= z;

	RETURN_ZVAL(ZEND_THIS, 1, 0);
}

PHP_METHOD(AxisAlignedBB, contractedCopy)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);

	object_init_ex(return_value, axis_aligned_bb_ce);
	axis_aligned_bb_object *result = AXIS_ALIGNED_BB_FROM_Z(return_value);
	result->minX = obj->minX + x;
	result->minY = obj->minY + y;
	result->minZ = obj->minZ + z;
	result->maxX = obj->maxX - x;
	result->maxY = obj->maxY - y;
	result->maxZ = obj->maxZ - z;
}

PHP_METHOD(AxisAlignedBB, equals)
{
	zval *bb_zval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(bb_zval)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	axis_aligned_bb_object *bb = AXIS_ALIGNED_BB_FROM_Z(bb_zval);

	if (obj->minX == bb->minX &&
		obj->minY == bb->minY &&
		obj->minZ == bb->minZ &&
		obj->maxX == bb->maxX &&
		obj->maxY == bb->maxY &&
		obj->maxZ == bb->maxZ) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

PHP_METHOD(AxisAlignedBB, setBB)
{
	zval *bb_zval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(bb_zval)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	axis_aligned_bb_object *bb = AXIS_ALIGNED_BB_FROM_Z(bb_zval);

	obj->minX = bb->minX;
	obj->minY = bb->minY;
	obj->minZ = bb->minZ;
	obj->maxX = bb->maxX;
	obj->maxY = bb->maxY;
	obj->maxZ = bb->maxZ;

	RETURN_ZVAL(ZEND_THIS, 1, 0);
}

PHP_METHOD(AxisAlignedBB, getOffsetBoundingBox)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);

	object_init_ex(return_value, axis_aligned_bb_ce);
	axis_aligned_bb_object *result = AXIS_ALIGNED_BB_FROM_Z(return_value);
	result->minX = obj->minX + x;
	result->minY = obj->minY + y;
	result->minZ = obj->minZ + z;
	result->maxX = obj->maxX + x;
	result->maxY = obj->maxY + y;
	result->maxZ = obj->maxZ + z;
}

PHP_METHOD(AxisAlignedBB, calculateXOffset)
{
	zval *bb_zval;
	double x;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(bb_zval)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	axis_aligned_bb_object *bb = AXIS_ALIGNED_BB_FROM_Z(bb_zval);

	if (bb->maxY <= obj->minY || bb->minY >= obj->maxY) {
		RETURN_DOUBLE(x);
	}

	if (bb->maxZ <= obj->minZ || bb->minZ >= obj->maxZ) {
		RETURN_DOUBLE(x);
	}

	if (x > 0 && bb->maxX <= obj->minX) {
		double x1 = obj->minX - bb->maxX;
		if (x1 < x) {
			x = x1;
		}
	} else if (x < 0 && bb->minX >= obj->maxX) {
		double x2 = obj->maxX - bb->minX;
		if (x2 > x) {
			x = x2;
		}
	}

	RETURN_DOUBLE(x);
}

PHP_METHOD(AxisAlignedBB, calculateYOffset)
{
	zval *bb_zval;
	double y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(bb_zval)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	axis_aligned_bb_object *bb = AXIS_ALIGNED_BB_FROM_Z(bb_zval);

	if (bb->maxX <= obj->minX || bb->minX >= obj->maxX) {
		RETURN_DOUBLE(y);
	}

	if (bb->maxZ <= obj->minZ || bb->minZ >= obj->maxZ) {
		RETURN_DOUBLE(y);
	}

	if (y > 0 && bb->maxY <= obj->minY) {
		double y1 = obj->minY - bb->maxY;
		if (y1 < y) {
			y = y1;
		}
	} else if (y < 0 && bb->minY >= obj->maxY) {
		double y2 = obj->maxY - bb->minY;
		if (y2 > y) {
			y = y2;
		}
	}

	RETURN_DOUBLE(y);
}

PHP_METHOD(AxisAlignedBB, calculateZOffset)
{
	zval *bb_zval;
	double z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(bb_zval)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	axis_aligned_bb_object *bb = AXIS_ALIGNED_BB_FROM_Z(bb_zval);

	if (bb->maxX <= obj->minX || bb->minX >= obj->maxX) {
		RETURN_DOUBLE(z);
	}

	if (bb->maxY <= obj->minY || bb->minY >= obj->maxY) {
		RETURN_DOUBLE(z);
	}

	if (z > 0 && bb->maxZ <= obj->minZ) {
		double z1 = obj->minZ - bb->maxZ;
		if (z1 < z) {
			z = z1;
		}
	} else if (z < 0 && bb->minZ >= obj->maxZ) {
		double z2 = obj->maxZ - bb->minZ;
		if (z2 > z) {
			z = z2;
		}
	}

	RETURN_DOUBLE(z);
}

PHP_METHOD(AxisAlignedBB, intersectsWith)
{
	zval *bb_zval;
	double epsilon = 0.00001;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT(bb_zval)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(epsilon)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	axis_aligned_bb_object *bb = AXIS_ALIGNED_BB_FROM_Z(bb_zval);

	if (bb->maxX - obj->minX > epsilon && obj->maxX - bb->minX > epsilon) {
		if (bb->maxY - obj->minY > epsilon && obj->maxY - bb->minY > epsilon) {
			if (bb->maxZ - obj->minZ > epsilon && obj->maxZ - bb->minZ > epsilon) {
				RETURN_TRUE;
			}
		}
	}

	RETURN_FALSE;
}

PHP_METHOD(AxisAlignedBB, isVectorInside)
{
	zval *vector_zval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(vector_zval)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);	
	vector3_object *vec = vector3_fetch_object(Z_OBJ_P(vector_zval));
	
	double x = vec->x;
	double y = vec->y;
	double z = vec->z;

	if (x <= obj->minX || x >= obj->maxX) {
		RETURN_FALSE;
	}

	if (y <= obj->minY || y >= obj->maxY) {
		RETURN_FALSE;
	}

	if (z > obj->minZ && z < obj->maxZ) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

PHP_METHOD(AxisAlignedBB, getAverageEdgeLength)
{
	ZEND_PARSE_PARAMETERS_NONE();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	double result = (obj->maxX - obj->minX + obj->maxY - obj->minY + obj->maxZ - obj->minZ) / 3.0;

	RETURN_DOUBLE(result);
}

PHP_METHOD(AxisAlignedBB, isVectorInYZ)
{
	zval *vector_zval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(vector_zval)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	vector3_object *vec = vector3_fetch_object(Z_OBJ_P(vector_zval));

	double y = vec->y;
	double z = vec->z;

	if (y >= obj->minY && y <= obj->maxY && z >= obj->minZ && z <= obj->maxZ) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

PHP_METHOD(AxisAlignedBB, isVectorInXZ)
{
	zval *vector_zval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(vector_zval)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	vector3_object *vec = vector3_fetch_object(Z_OBJ_P(vector_zval));

	double x = vec->x;
	double z = vec->z;

	if (x >= obj->minX && x <= obj->maxX && z >= obj->minZ && z <= obj->maxZ) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

PHP_METHOD(AxisAlignedBB, isVectorInXY)
{
	zval *vector_zval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(vector_zval)
	ZEND_PARSE_PARAMETERS_END();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	vector3_object *vec = vector3_fetch_object(Z_OBJ_P(vector_zval));

	double x = vec->x;
	double y = vec->y;

	if (x >= obj->minX && x <= obj->maxX && y >= obj->minY && y <= obj->maxY) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}

PHP_METHOD(AxisAlignedBB, calculateIntercept)
{
	zval *pos1_zval, *pos2_zval;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(pos1_zval)
		Z_PARAM_OBJECT(pos2_zval)
	ZEND_PARSE_PARAMETERS_END();

	//TODO: this method requires implementation of RayTraceResult. This is a placeholder that returns null.
	RETURN_NULL();
}

PHP_METHOD(AxisAlignedBB, __toString)
{
	ZEND_PARSE_PARAMETERS_NONE();

	axis_aligned_bb_object *obj = AXIS_ALIGNED_BB_FROM_Z(ZEND_THIS);
	zend_string *str = zend_strpprintf(0, "AxisAlignedBB(%g, %g, %g, %g, %g, %g)",
		obj->minX, obj->minY, obj->minZ, obj->maxX, obj->maxY, obj->maxZ);

	RETURN_STR(str);
}

const zend_function_entry axis_aligned_bb_methods[] = {
    PHP_ME(AxisAlignedBB, __construct, arginfo_axis_aligned_bb_construct, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, one, arginfo_axis_aligned_bb_one, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(AxisAlignedBB, setBounds, arginfo_axis_aligned_bb_setBounds, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, addCoord, arginfo_axis_aligned_bb_addCoord, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, grow, arginfo_axis_aligned_bb_grow, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, expand, arginfo_axis_aligned_bb_expand, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, expandedCopy, arginfo_axis_aligned_bb_expandedCopy, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, offset, arginfo_axis_aligned_bb_offset, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, offsetCopy, arginfo_axis_aligned_bb_offsetCopy, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, shrink, arginfo_axis_aligned_bb_shrink, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, contract, arginfo_axis_aligned_bb_contract, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, contractedCopy, arginfo_axis_aligned_bb_contractedCopy, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, equals, arginfo_axis_aligned_bb_equals, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, setBB, arginfo_axis_aligned_bb_setBB, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, getOffsetBoundingBox, arginfo_axis_aligned_bb_getOffsetBoundingBox, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, calculateXOffset, arginfo_axis_aligned_bb_calculateXOffset, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, calculateYOffset, arginfo_axis_aligned_bb_calculateYOffset, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, calculateZOffset, arginfo_axis_aligned_bb_calculateZOffset, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, intersectsWith, arginfo_axis_aligned_bb_intersectsWith, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, isVectorInside, arginfo_axis_aligned_bb_isVectorInside, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, getAverageEdgeLength, arginfo_axis_aligned_bb_getAverageEdgeLength, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, isVectorInYZ, arginfo_axis_aligned_bb_isVectorInYZ, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, isVectorInXZ, arginfo_axis_aligned_bb_isVectorInXZ, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, isVectorInXY, arginfo_axis_aligned_bb_isVectorInXY, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, calculateIntercept, arginfo_axis_aligned_bb_calculateIntercept, ZEND_ACC_PUBLIC)
    PHP_ME(AxisAlignedBB, __toString, arginfo_axis_aligned_bb_toString, ZEND_ACC_PUBLIC)
    PHP_FE_END
};
