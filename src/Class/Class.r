#ifndef CLASS_H
#define CLASS_H

#include "Constructable.r"
#include "Destructable.r"
#include "Legacy_AllocationTable.r"
#include "Legacy_AllocationTableList.r"
#include "ObjectBase.r"
#include <stdio.h>
#include <stdlib.h>

enum StatusCode { DESTRUCTOR_WAS_NOT_INVOKED, DESTRUCTOR_WAS_INVOKED_ONCE };

// Forward declaration of incomplete type
typedef struct class Class;

struct class {

    /// `Class` implements `ObjectBase`.
    ObjectBase *thisObjectBase;

    /// Singleton for the whole class. Sensitive data. DO NOT TOUCH!
    Legacy_AllocationTable *CLASS_ALLOCATION_TABLE;

    /// Sensitive data. DO NOT TOUCH!
    void *allocatedAddress;

    enum StatusCode statusCode;

    int x;

    /// Printing method.
    void (*print)();

    /// A logic method.
    void (*addOneToX)();
};

Class *
ClassConstructorWithClassName(void *objectToSaveItsAddressToAllocationTable,
                              const char *className);

/**
 * @brief Creates a `new` "heap-allocated" instance of `Class` and initializes
 *        it.
 *
 * @attention Remember to `free` the returned value of this function.
 *
 * For example:
 * @code
 *
 * // Construct.
 * Class *class = ClassConstructor();
 *
 * // Do something...
 * (*class->print)(class);
 * (*class->addOneToX)(class);
 * (*class->print)(class);
 *
 * // Remember to `free`.
 * free(class);
 * @endcode
 *
 * @return A pointer to a `new` "heap-allocated" instance of `Class`.
 */
Class *ClassConstructor();

void *ClassDestructor(Class *class);

#endif //CLASS_H
