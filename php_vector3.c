#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_math.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"
#include <math.h>

#ifndef PHP_ROUND_HALF_UP
#define PHP_ROUND_HALF_UP 1
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

zend_class_entry *vector3_ce;
zend_class_entry *vector2_ce;

zend_object_handlers vector3_object_handlers;

ZEND_BEGIN_ARG_INFO_EX(arginfo_vector3_construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x, IS_DOUBLE, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, z, IS_DOUBLE, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getX, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getY, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getZ, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getFloorX, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getFloorY, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getFloorZ, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getRight, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getUp, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getForward, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getSouth, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getWest, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_add, 0, 1, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, z, IS_DOUBLE, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_subtract, 0, 1, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, z, IS_DOUBLE, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_multiply, 0, 1, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO(0, number, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_divide, 0, 1, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO(0, number, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_floor, 0, 0, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_ceil, 0, 0, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_round, 0, 0, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, precision, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mode, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_abs, 0, 0, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_getSide, 0, 1, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO(0, side, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_down, 0, 0, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_up, 0, 0, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_north, 0, 0, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_south, 0, 0, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_west, 0, 0, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_east, 0, 0, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_asVector3, 0, 0, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_getOppositeSide, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, side, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_distance, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, pos, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_distanceSquared, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, pos, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_maxPlainDistance, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, z, IS_DOUBLE, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_length, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_lengthSquared, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_normalize, 0, 0, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_dot, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_OBJ_INFO(0, v, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_cross, 0, 1, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_OBJ_INFO(0, v, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_equals, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, v, pocketmine\\math\\Vector3, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_getIntermediateWithXValue, 0, 2, pocketmine\\math\\Vector3, 1)
	ZEND_ARG_OBJ_INFO(0, v, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_getIntermediateWithYValue, 0, 2, pocketmine\\math\\Vector3, 1)
	ZEND_ARG_OBJ_INFO(0, v, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_vector3_getIntermediateWithZValue, 0, 2, pocketmine\\math\\Vector3, 1)
	ZEND_ARG_OBJ_INFO(0, v, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_setComponents, 0, 3, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_fromObjectAdd, 0, 4, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, pos, pocketmine\\math\\Vector3, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3_toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3___serialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_vector3___unserialize, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

zval *vector3_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
	vector3_object *obj = vector3_fetch_object(object);
	const char *name = ZSTR_VAL(member);

	if (strcmp(name, "x") == 0) {
		ZVAL_DOUBLE(rv, obj->x);
		return rv;
	} else if (strcmp(name, "y") == 0) {
		ZVAL_DOUBLE(rv, obj->y);
		return rv;
	} else if (strcmp(name, "z") == 0) {
		ZVAL_DOUBLE(rv, obj->z);
		return rv;
	}

	return zend_std_read_property(object, member, type, cache_slot, rv);
}

HashTable *vector3_get_properties(zend_object *object)
{
	vector3_object *obj = vector3_fetch_object(object);
	HashTable *props = zend_std_get_properties(object);

	zval *zv;

	zv = zend_hash_str_find(props, "x", sizeof("x")-1);
	if (EXPECTED(zv)) {
		ZVAL_DOUBLE(zv, obj->x);
	} else {
		zval tmp;
		ZVAL_DOUBLE(&tmp, obj->x);
		zend_hash_str_add_new(props, "x", sizeof("x")-1, &tmp);
	}

	zv = zend_hash_str_find(props, "y", sizeof("y")-1);
	if (EXPECTED(zv)) {
		ZVAL_DOUBLE(zv, obj->y);
	} else {
		zval tmp;
		ZVAL_DOUBLE(&tmp, obj->y);
		zend_hash_str_add_new(props, "y", sizeof("y")-1, &tmp);
	}

	zv = zend_hash_str_find(props, "z", sizeof("z")-1);
	if (EXPECTED(zv)) {
		ZVAL_DOUBLE(zv, obj->z);
	} else {
		zval tmp;
		ZVAL_DOUBLE(&tmp, obj->z);
		zend_hash_str_add_new(props, "z", sizeof("z")-1, &tmp);
	}

	return props;
}

zval *vector3_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
	vector3_object *obj = vector3_fetch_object(object);
	const char *name = ZSTR_VAL(member);

	if (strcmp(name, "x") == 0) {
		obj->x = zval_get_double(value);
		return value;
	} else if (strcmp(name, "y") == 0) {
		obj->y = zval_get_double(value);
		return value;
	} else if (strcmp(name, "z") == 0) {
		obj->z = zval_get_double(value);
		return value;
	}

	return zend_std_write_property(object, member, value, cache_slot);
}

zend_object *vector3_create_object(zend_class_entry *ce) {
    vector3_object *intern = zend_object_alloc(sizeof(vector3_object), ce);
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);
    intern->x = 0.0;
    intern->y = 0.0;
    intern->z = 0.0;
    intern->std.handlers = &vector3_object_handlers;
    return &intern->std;
}


void vector3_free_object(zend_object *object) {
	vector3_object *intern = vector3_fetch_object(object);
	zend_object_std_dtor(&intern->std);
}

zend_object *vector3_clone_obj(zend_object *object){
	vector3_object *old_obj = vector3_fetch_object(object);
	if (!old_obj) {
		return NULL;
	}

	zend_object *new_obj_zend = vector3_create_object(object->ce);
	if (!new_obj_zend) {
		return NULL;
	}

	vector3_object *new_obj = vector3_fetch_object(new_obj_zend);
	if (!new_obj) {
		zend_object_std_dtor(new_obj_zend);
		return NULL;
	}

	new_obj->x = old_obj->x;
	new_obj->y = old_obj->y;
	new_obj->z = old_obj->z;

	zend_objects_clone_members(new_obj_zend, object);

	return new_obj_zend;
}

PHP_METHOD(Vector3, __construct) {
	double x = 0, y = 0, z = 0;

	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	intern->x = x;
	intern->y = y;
	intern->z = z;
}

PHP_METHOD(Vector3, getX) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->x);
}

PHP_METHOD(Vector3, getY) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->y);
}

PHP_METHOD(Vector3, getZ) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->z);
}

PHP_METHOD(Vector3, getFloorX) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_LONG((zend_long)floor(intern->x));
}

PHP_METHOD(Vector3, getFloorY) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_LONG((zend_long)floor(intern->y));
}

PHP_METHOD(Vector3, getFloorZ) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_LONG((zend_long)floor(intern->z));
}

PHP_METHOD(Vector3, getRight) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->x);
}

PHP_METHOD(Vector3, getUp) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->y);
}

PHP_METHOD(Vector3, getForward) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->z);
}

PHP_METHOD(Vector3, getSouth) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->x);
}

PHP_METHOD(Vector3, getWest) {
	ZEND_PARSE_PARAMETERS_NONE();
	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->z);
}

PHP_METHOD(Vector3, add) {
	zval *arg1 = NULL;
	double y = 0, z = 0;

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(arg1)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	double new_x, new_y, new_z;

	if (Z_TYPE_P(arg1) == IS_OBJECT && instanceof_function(Z_OBJCE_P(arg1), vector3_ce)) {
		vector3_object *other = Z_VECTOR3_OBJ_P(arg1);
		new_x = intern->x + other->x;
		new_y = intern->y + other->y;
		new_z = intern->z + other->z;
	} else {
		convert_to_double(arg1);
		new_x = intern->x + Z_DVAL_P(arg1);
		new_y = intern->y + y;
		new_z = intern->z + z;
	}

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = new_x;
	result->y = new_y;
	result->z = new_z;
}

PHP_METHOD(Vector3, subtract) {
	zval *arg1 = NULL;
	double y = 0, z = 0;

	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(arg1)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	double new_x, new_y, new_z;

	if (Z_TYPE_P(arg1) == IS_OBJECT && instanceof_function(Z_OBJCE_P(arg1), vector3_ce)) {
		vector3_object *other = Z_VECTOR3_OBJ_P(arg1);
		new_x = intern->x - other->x;
		new_y = intern->y - other->y;
		new_z = intern->z - other->z;
	} else {
		convert_to_double(arg1);
		new_x = intern->x - Z_DVAL_P(arg1);
		new_y = intern->y - y;
		new_z = intern->z - z;
	}

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = new_x;
	result->y = new_y;
	result->z = new_z;
}

PHP_METHOD(Vector3, multiply) {
	double number;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(number)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x * number;
	result->y = intern->y * number;
	result->z = intern->z * number;
}

PHP_METHOD(Vector3, divide) {
	double number;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(number)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x / number;
	result->y = intern->y / number;
	result->z = intern->z / number;
}

PHP_METHOD(Vector3, floor) {
	ZEND_PARSE_PARAMETERS_NONE();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = (double)(zend_long)floor(intern->x);
	result->y = (double)(zend_long)floor(intern->y);
	result->z = (double)(zend_long)floor(intern->z);
}

PHP_METHOD(Vector3, ceil) {
	ZEND_PARSE_PARAMETERS_NONE();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = (double)(zend_long)ceil(intern->x);
	result->y = (double)(zend_long)ceil(intern->y);
	result->z = (double)(zend_long)ceil(intern->z);
}

PHP_METHOD(Vector3, round) {
	zend_long precision = 0;
	zend_long mode = PHP_ROUND_HALF_UP;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(precision)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);

	if (precision > 0) {
		double multiplier = pow(10.0, (double)precision);
		double inv_multiplier = 1.0 / multiplier;
		result->x = round(intern->x * multiplier) * inv_multiplier;
		result->y = round(intern->y * multiplier) * inv_multiplier;
		result->z = round(intern->z * multiplier) * inv_multiplier;
	} else {
		result->x = round(intern->x);
		result->y = round(intern->y);
		result->z = round(intern->z);
	}
}

PHP_METHOD(Vector3, abs) {
	ZEND_PARSE_PARAMETERS_NONE();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = fabs(intern->x);
	result->y = fabs(intern->y);
	result->z = fabs(intern->z);
}

PHP_METHOD(Vector3, getSide) {
	zend_long side;
	zend_long step = 1;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_LONG(side)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);

	switch(side) {
		case 0: // SIDE_DOWN
			result->x = intern->x;
			result->y = intern->y - step;
			result->z = intern->z;
			break;
		case 1: // SIDE_UP
			result->x = intern->x;
			result->y = intern->y + step;
			result->z = intern->z;
			break;
		case 2: // SIDE_NORTH
			result->x = intern->x;
			result->y = intern->y;
			result->z = intern->z - step;
			break;
		case 3: // SIDE_SOUTH
			result->x = intern->x;
			result->y = intern->y;
			result->z = intern->z + step;
			break;
		case 4: // SIDE_WEST
			result->x = intern->x - step;
			result->y = intern->y;
			result->z = intern->z;
			break;
		case 5: // SIDE_EAST
			result->x = intern->x + step;
			result->y = intern->y;
			result->z = intern->z;
			break;
		default:
			result->x = intern->x;
			result->y = intern->y;
			result->z = intern->z;
			break;
	}
}

PHP_METHOD(Vector3, down) {
	zend_long step = 1;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x;
	result->y = intern->y - step;
	result->z = intern->z;
}

PHP_METHOD(Vector3, up) {
	zend_long step = 1;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x;
	result->y = intern->y + step;
	result->z = intern->z;
}

PHP_METHOD(Vector3, north) {
	zend_long step = 1;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x;
	result->y = intern->y;
	result->z = intern->z - step;
}

PHP_METHOD(Vector3, south) {
	zend_long step = 1;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x;
	result->y = intern->y;
	result->z = intern->z + step;
}

PHP_METHOD(Vector3, west) {
	zend_long step = 1;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x - step;
	result->y = intern->y;
	result->z = intern->z;
}

PHP_METHOD(Vector3, east) {
	zend_long step = 1;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x + step;
	result->y = intern->y;
	result->z = intern->z;
}

PHP_METHOD(Vector3, asVector3) {
	ZEND_PARSE_PARAMETERS_NONE();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x;
	result->y = intern->y;
	result->z = intern->z;
}

PHP_METHOD(Vector3, getOppositeSide) {
	zend_long side;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(side)
	ZEND_PARSE_PARAMETERS_END();

	switch(side) {
		case 0: RETURN_LONG(1); // DOWN -> UP
		case 1: RETURN_LONG(0); // UP -> DOWN
		case 2: RETURN_LONG(3); // NORTH -> SOUTH
		case 3: RETURN_LONG(2); // SOUTH -> NORTH
		case 4: RETURN_LONG(5); // WEST -> EAST
		case 5: RETURN_LONG(4); // EAST -> WEST
		default: RETURN_LONG(-1);
	}
}

PHP_METHOD(Vector3, distance) {
	zval *pos;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(pos, vector3_ce)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(pos);

	double dx = intern->x - other->x;
	double dy = intern->y - other->y;
	double dz = intern->z - other->z;

	RETURN_DOUBLE(sqrt(dx*dx + dy*dy + dz*dz));
}

PHP_METHOD(Vector3, distanceSquared) {
	zval *pos;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(pos, vector3_ce)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(pos);

	double dx = intern->x - other->x;
	double dy = intern->y - other->y;
	double dz = intern->z - other->z;

	RETURN_DOUBLE(dx*dx + dy*dy + dz*dz);
}

PHP_METHOD(Vector3, maxPlainDistance) {
	zval *arg1 = NULL;
	double z = 0;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(arg1)
		Z_PARAM_OPTIONAL
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	double x_val, z_val;

	if (Z_TYPE_P(arg1) == IS_OBJECT && instanceof_function(Z_OBJCE_P(arg1), vector3_ce)) {
		vector3_object *other = Z_VECTOR3_OBJ_P(arg1);
		x_val = other->x;
		z_val = other->z;
	} else {
		convert_to_double(arg1);
		x_val = Z_DVAL_P(arg1);
		z_val = z;
	}

	double dx = fabs(intern->x - x_val);
	double dz = fabs(intern->z - z_val);

	RETURN_DOUBLE(dx > dz ? dx : dz);
}

PHP_METHOD(Vector3, length) {
	ZEND_PARSE_PARAMETERS_NONE();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	double len_sq = intern->x * intern->x + intern->y * intern->y + intern->z * intern->z;

	RETURN_DOUBLE(sqrt(len_sq));
}

PHP_METHOD(Vector3, lengthSquared) {
	ZEND_PARSE_PARAMETERS_NONE();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	RETURN_DOUBLE(intern->x * intern->x + intern->y * intern->y + intern->z * intern->z);
}

PHP_METHOD(Vector3, normalize) {
	ZEND_PARSE_PARAMETERS_NONE();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	
	double x = intern->x;
	double y = intern->y;
	double z = intern->z;
	double len_sq = x * x + y * y + z * z;

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);

	if (UNEXPECTED(len_sq <= 1e-10)) {
		result->x = 0;
		result->y = 0;
		result->z = 0;
	} else {
		double inv_len = 1.0 / sqrt(len_sq);
		result->x = x * inv_len;
		result->y = y * inv_len;
		result->z = z * inv_len;
	}
}

PHP_METHOD(Vector3, dot) {
	zval *v;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v, vector3_ce)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(v);

	RETURN_DOUBLE(intern->x * other->x + intern->y * other->y + intern->z * other->z);
}

PHP_METHOD(Vector3, cross) {
	zval *v;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v, vector3_ce)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(v);

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->y * other->z - intern->z * other->y;
	result->y = intern->z * other->x - intern->x * other->z;
	result->z = intern->x * other->y - intern->y * other->x;
}

PHP_METHOD(Vector3, equals) {
	zval *v;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(v, vector3_ce)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(v);

	RETURN_BOOL(
		fabs(intern->x - other->x) < FLOAT_EPSILON &&
		fabs(intern->y - other->y) < FLOAT_EPSILON &&
		fabs(intern->z - other->z) < FLOAT_EPSILON
	);
}

PHP_METHOD(Vector3, getIntermediateWithXValue) {
	zval *v;
	double x;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(v, vector3_ce)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(v);

	double xDiff = other->x - intern->x;
	if ((xDiff * xDiff) < 0.0000001) {
		RETURN_NULL();
	}

	double f = (x - intern->x) / xDiff;
	if (f < 0 || f > 1) {
		RETURN_NULL();
	}

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = x;
	result->y = intern->y + (other->y - intern->y) * f;
	result->z = intern->z + (other->z - intern->z) * f;
}

PHP_METHOD(Vector3, getIntermediateWithYValue) {
	zval *v;
	double y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(v, vector3_ce)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(v);

	double yDiff = other->y - intern->y;
	if ((yDiff * yDiff) < 0.0000001) {
		RETURN_NULL();
	}

	double f = (y - intern->y) / yDiff;
	if (f < 0 || f > 1) {
		RETURN_NULL();
	}

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x + (other->x - intern->x) * f;
	result->y = y;
	result->z = intern->z + (other->z - intern->z) * f;
}

PHP_METHOD(Vector3, getIntermediateWithZValue) {
	zval *v;
	double z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(v, vector3_ce)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(v);

	double zDiff = other->z - intern->z;
	if ((zDiff * zDiff) < 0.0000001) {
		RETURN_NULL();
	}

	double f = (z - intern->z) / zDiff;
	if (f < 0 || f > 1) {
		RETURN_NULL();
	}

	object_init_ex(return_value, vector3_ce);
	vector3_object *result = Z_VECTOR3_OBJ_P(return_value);
	result->x = intern->x + (other->x - intern->x) * f;
	result->y = intern->y + (other->y - intern->y) * f;
	result->z = z;
}

PHP_METHOD(Vector3, setComponents) {
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	intern->x = x;
	intern->y = y;
	intern->z = z;

	RETURN_ZVAL(ZEND_THIS, 1, 0);
}

PHP_METHOD(Vector3, fromObjectAdd) {
	zval *pos;
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(pos, vector3_ce)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	vector3_object *other = Z_VECTOR3_OBJ_P(pos);

	intern->x = other->x + x;
	intern->y = other->y + y;
	intern->z = other->z + z;

	RETURN_ZVAL(ZEND_THIS, 1, 0);
}

PHP_METHOD(Vector3, __toString) {
	ZEND_PARSE_PARAMETERS_NONE();

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);
	zend_string *str = strpprintf(0, "Vector3(x=%g,y=%g,z=%g)", intern->x, intern->y, intern->z);

	RETURN_STR(str);
}

PHP_METHOD(Vector3, __serialize)
{
    ZEND_PARSE_PARAMETERS_NONE();

    vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);

    array_init(return_value);

    zval native;
    array_init_size(&native, 3);
    add_assoc_double(&native, "x", intern->x);
    add_assoc_double(&native, "y", intern->y);
    add_assoc_double(&native, "z", intern->z);
    zend_hash_next_index_insert(Z_ARRVAL_P(return_value), &native);

    zval members;
    ZVAL_ARR(&members, zend_proptable_to_symtable(
			zend_std_get_properties(&intern->std), /* always_duplicate */ 1));
    zend_hash_next_index_insert(Z_ARRVAL_P(return_value), &members);
}

PHP_METHOD(Vector3, __unserialize)
{
	HashTable *data;
	zval *native_zv, *members_zv, *val;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "h", &data) == FAILURE) {
		RETURN_THROWS();
	}

	vector3_object *intern = Z_VECTOR3_OBJ_P(ZEND_THIS);

	native_zv  = zend_hash_index_find(data, 0);
	members_zv = zend_hash_index_find(data, 1);

	if (!native_zv || !members_zv ||
		Z_TYPE_P(native_zv) != IS_ARRAY || Z_TYPE_P(members_zv) != IS_ARRAY) {
		zend_value_error("Incomplete or ill-typed serialization data");
		RETURN_THROWS();
	}

	if ((val = zend_hash_str_find(Z_ARRVAL_P(native_zv), "x", sizeof("x") - 1)) != NULL) {
		intern->x = zval_get_double(val);
	}
	if ((val = zend_hash_str_find(Z_ARRVAL_P(native_zv), "y", sizeof("y") - 1)) != NULL) {
		intern->y = zval_get_double(val);
	}
	if ((val = zend_hash_str_find(Z_ARRVAL_P(native_zv), "z", sizeof("z") - 1)) != NULL) {
		intern->z = zval_get_double(val);
	}

	object_properties_load(&intern->std, Z_ARRVAL_P(members_zv));
}

static const zend_function_entry vector3_methods[] = {
    PHP_ME(Vector3, __construct, arginfo_vector3_construct, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getX, arginfo_vector3_getX, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getY, arginfo_vector3_getY, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getZ, arginfo_vector3_getZ, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getFloorX, arginfo_vector3_getFloorX, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getFloorY, arginfo_vector3_getFloorY, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getFloorZ, arginfo_vector3_getFloorZ, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getRight, arginfo_vector3_getRight, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getUp, arginfo_vector3_getUp, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getForward, arginfo_vector3_getForward, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getSouth, arginfo_vector3_getSouth, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getWest, arginfo_vector3_getWest, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, add, arginfo_vector3_add, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, subtract, arginfo_vector3_subtract, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, multiply, arginfo_vector3_multiply, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, divide, arginfo_vector3_divide, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, floor, arginfo_vector3_floor, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, ceil, arginfo_vector3_ceil, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, round, arginfo_vector3_round, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, abs, arginfo_vector3_abs, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getSide, arginfo_vector3_getSide, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, down, arginfo_vector3_down, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, up, arginfo_vector3_up, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, north, arginfo_vector3_north, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, south, arginfo_vector3_south, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, west, arginfo_vector3_west, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, east, arginfo_vector3_east, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, asVector3, arginfo_vector3_asVector3, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getOppositeSide, arginfo_vector3_getOppositeSide, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(Vector3, distance, arginfo_vector3_distance, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, distanceSquared, arginfo_vector3_distanceSquared, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, maxPlainDistance, arginfo_vector3_maxPlainDistance, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, length, arginfo_vector3_length, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, lengthSquared, arginfo_vector3_lengthSquared, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, normalize, arginfo_vector3_normalize, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, dot, arginfo_vector3_dot, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, cross, arginfo_vector3_cross, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, equals, arginfo_vector3_equals, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getIntermediateWithXValue, arginfo_vector3_getIntermediateWithXValue, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getIntermediateWithYValue, arginfo_vector3_getIntermediateWithYValue, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, getIntermediateWithZValue, arginfo_vector3_getIntermediateWithZValue, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, setComponents, arginfo_vector3_setComponents, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, fromObjectAdd, arginfo_vector3_fromObjectAdd, ZEND_ACC_PUBLIC)
    PHP_ME(Vector3, __toString, arginfo_vector3_toString, ZEND_ACC_PUBLIC)
		PHP_ME(Vector3, __serialize, arginfo_vector3___serialize, ZEND_ACC_PUBLIC)
		PHP_ME(Vector3, __unserialize, arginfo_vector3___unserialize, ZEND_ACC_PUBLIC)

	PHP_FE_END
};

PHP_MINIT_FUNCTION(math)
{
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "pocketmine\\math\\Vector3", vector3_methods);
    vector3_ce = zend_register_internal_class(&ce);
    vector3_ce->create_object = vector3_create_object;

    memcpy(&vector3_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    vector3_object_handlers.offset = XtOffsetOf(vector3_object, std);
    vector3_object_handlers.free_obj = vector3_free_object;
    vector3_object_handlers.read_property = vector3_read_property;
    vector3_object_handlers.write_property = vector3_write_property;
    vector3_object_handlers.get_properties = vector3_get_properties;
		vector3_object_handlers.clone_obj = vector3_clone_obj;

    zend_declare_property_double(vector3_ce, "x", sizeof("x")-1, 0, ZEND_ACC_PUBLIC);
    zend_declare_property_double(vector3_ce, "y", sizeof("y")-1, 0, ZEND_ACC_PUBLIC);
    zend_declare_property_double(vector3_ce, "z", sizeof("z")-1, 0, ZEND_ACC_PUBLIC);

    zend_declare_class_constant_long(vector3_ce, "SIDE_DOWN", sizeof("SIDE_DOWN")-1, 0);
    zend_declare_class_constant_long(vector3_ce, "SIDE_UP", sizeof("SIDE_UP")-1, 1);
    zend_declare_class_constant_long(vector3_ce, "SIDE_NORTH", sizeof("SIDE_NORTH")-1, 2);
    zend_declare_class_constant_long(vector3_ce, "SIDE_SOUTH", sizeof("SIDE_SOUTH")-1, 3);
    zend_declare_class_constant_long(vector3_ce, "SIDE_WEST", sizeof("SIDE_WEST")-1, 4);
    zend_declare_class_constant_long(vector3_ce, "SIDE_EAST", sizeof("SIDE_EAST")-1, 5);

    extern const zend_function_entry axis_aligned_bb_methods[];
    INIT_CLASS_ENTRY(ce, "pocketmine\\math\\AxisAlignedBB", axis_aligned_bb_methods);
    axis_aligned_bb_ce = zend_register_internal_class(&ce);
    axis_aligned_bb_ce->create_object = axis_aligned_bb_create_object;

    memcpy(&axis_aligned_bb_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
		axis_aligned_bb_handlers.offset = XtOffsetOf(axis_aligned_bb_object, std);
		axis_aligned_bb_handlers.free_obj = axis_aligned_bb_free_object;
		axis_aligned_bb_handlers.read_property = axis_aligned_bb_read_property;
		axis_aligned_bb_handlers.write_property = axis_aligned_bb_write_property;
		axis_aligned_bb_handlers.get_properties = axis_aligned_bb_get_properties;
		axis_aligned_bb_handlers.clone_obj = axis_aligned_bb_clone_obj;

    zend_declare_property_double(axis_aligned_bb_ce, "minX", sizeof("minX")-1, 0, ZEND_ACC_PUBLIC);
    zend_declare_property_double(axis_aligned_bb_ce, "minY", sizeof("minY")-1, 0, ZEND_ACC_PUBLIC);
    zend_declare_property_double(axis_aligned_bb_ce, "minZ", sizeof("minZ")-1, 0, ZEND_ACC_PUBLIC);
    zend_declare_property_double(axis_aligned_bb_ce, "maxX", sizeof("maxX")-1, 0, ZEND_ACC_PUBLIC);
    zend_declare_property_double(axis_aligned_bb_ce, "maxY", sizeof("maxY")-1, 0, ZEND_ACC_PUBLIC);
    zend_declare_property_double(axis_aligned_bb_ce, "maxZ", sizeof("maxZ")-1, 0, ZEND_ACC_PUBLIC);

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(math)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(math)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "Math Extension", "enabled");
    php_info_print_table_row(2, "Version", PHP_MATH_VERSION);
		php_info_print_table_row(2, "Author", "MaruselPlay");
    php_info_print_table_row(2, "Vector3", "enabled");
    php_info_print_table_row(2, "AxisAlignedBB", "enabled");
    php_info_print_table_end();
}

zend_module_entry math_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_MATH_EXTNAME,
    NULL,
    PHP_MINIT(math),
    PHP_MSHUTDOWN(math),
    NULL,
    NULL,
    PHP_MINFO(math),
    PHP_MATH_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_MATH
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(math)
#endif
