PHP_ARG_ENABLE(math, whether to enable math support,
[  --enable-math   Enable math support], no)

if test "$PHP_MATH" != "no"; then
  PHP_NEW_EXTENSION(math, php_vector3.c axis_aligned_bb.c, $ext_shared)
fi
