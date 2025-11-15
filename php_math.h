#ifndef PHP_VECTOR3_H
#define PHP_VECTOR3_H

extern zend_module_entry math_module_entry;

#define PHP_MATH_VERSION "1.0.0"
#define PHP_MATH_EXTNAME "math"

#ifdef PHP_WIN32
# define PHP_MATH_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
# define PHP_MATH_API __attribute__ ((visibility("default")))
#else
# define PHP_MATH_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include "php.h"

#define FLOAT_EPSILON 0.00001

typedef struct {
  double x;
  double y;
  double z;
  zend_object std;
} vector3_object;

extern zend_class_entry *vector3_ce;
extern zend_object_handlers vector3_object_handlers;

static inline vector3_object *vector3_fetch_object(zend_object *obj) {
  return (vector3_object *)((char *)obj - XtOffsetOf(vector3_object, std));
}

#define Z_VECTOR3_OBJ_P(zv) vector3_fetch_object(Z_OBJ_P(zv))

typedef struct {
  double minX;
  double minY;
  double minZ;
  double maxX;
  double maxY;
  double maxZ;
  zend_object std;
} axis_aligned_bb_object;

extern zend_class_entry *axis_aligned_bb_ce;
extern zend_object_handlers axis_aligned_bb_handlers;

static inline axis_aligned_bb_object *axis_aligned_bb_fetch_object(zend_object *obj) {
  return (axis_aligned_bb_object *)((char *)obj - XtOffsetOf(axis_aligned_bb_object, std));
}

#define AXIS_ALIGNED_BB_FROM_Z(zv) axis_aligned_bb_fetch_object(Z_OBJ_P(zv))

zend_object *vector3_create_object(zend_class_entry *ce);
void vector3_free_object(zend_object *obj);
zval *vector3_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv);
zval *vector3_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot);
zval *vector3_get_property_ptr_ptr(zend_object *object, zend_string *member, zval *value, void **cache_slot);
HashTable *vector3_get_properties(zend_object *object);
zend_object *vector3_clone_obj(zend_object *object);

zend_object *axis_aligned_bb_create_object(zend_class_entry *ce);
void axis_aligned_bb_free_object(zend_object *obj);
zval *axis_aligned_bb_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv);
zval *axis_aligned_bb_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot);
zval *axis_aligned_bb_get_property_ptr_ptr(zend_object *object);
HashTable *axis_aligned_bb_get_properties(zend_object *object);
zend_object *axis_aligned_bb_clone_obj(zend_object *object);

#if defined(ZTS) && defined(COMPILE_DL_MATH)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

// Property cache structures for fast property access
typedef struct {
    zend_string *name;
    zend_property_info *info;
} property_cache_slot;

typedef struct {
    property_cache_slot x;
    property_cache_slot y;
    property_cache_slot z;
} vector3_property_cache;

typedef struct {
    property_cache_slot minX;
    property_cache_slot minY;
    property_cache_slot minZ;
    property_cache_slot maxX;
    property_cache_slot maxY;
    property_cache_slot maxZ;
} aabb_property_cache;

// Global immutable caches (ZTS-safe, initialized at MINIT)
extern vector3_property_cache vec3_prop_cache;
extern aabb_property_cache aabb_prop_cache;

// Power of 10 lookup table for round optimization
extern const double pow10_table[10];

#endif