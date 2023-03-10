#ifndef CLASS_ATOMICDOUBLERVALUE_H
#define CLASS_ATOMICDOUBLERVALUE_H

#include "AtomicIntegerRValue.h"

DEFINE_CLASS_H(AtomicDoubleRValue)

AtomicDoubleRValue *AtomicDoubleRValueConstructor(DoubleRValue doubleRValue);

#define __DOUBLE_RVALUE_MEMBER_NAME__ \
    "__DOUBLE_RVALUE_MEMBER_NAME__"

#define __DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__ \
    "__DOUBLE_RVALUE_MANTISSA_NUMBER_MEMBER_NAME__"

#endif //CLASS_ATOMICDOUBLERVALUE_H
