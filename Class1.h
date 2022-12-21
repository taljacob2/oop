#ifndef CLASS1_H
#define CLASS1_H

#include "AllocationTable.h"
#include "Quote.h"
#include <stdio.h>
#include <stdlib.h>

#define CLASS1_CLASSNAME           Class1
#define CLASS1_CLASSNAME_AS_STRING EXPAND_AND_QUOTE(CLASS1_CLASSNAME)

typedef struct class1
        CLASS1_CLASSNAME; // Forward declaration of incomplete type

struct class1 {
    int x;

    /// Printing method.
    void (*print)();

    /// A logic method.
    void (*addOneToX)();
};

static void print(Class1 *class1) { printf("x = %d\n", class1->x); }

static void addOneToX(Class1 *class1) { class1->x += 1; }

static void constructor_Class1_fields(Class1 *class1) {
    class1->x         = 1;
    class1->print     = &print;
    class1->addOneToX = &addOneToX;
}

/**
 * @brief Creates a `new` "heap-allocated" instance of `Class1` and initializes
 *        it.
 *
 * @attention Remember to `free` the returned value of this function.
 *
 * For example:
 * @code
 *
 * // Construct.
 * Class1 *class1 = Class1Constructor();
 *
 * // Do something...
 * (*class1->print)(class1);
 * (*class1->addOneToX)(class1);
 * (*class1->print)(class1);
 *
 * // Remember to `free`.
 * free(class1);
 * @endcode
 *
 * @return A pointer to a `new` "heap-allocated" instance of `Class1`.
 */
Class1 *Class1Constructor() {
    Class1 *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Class1_fields(obj);

    return obj;
}

/**
 * Singleton implementation.
 *
 * @return
 * @see https://stackoverflow.com/a/803699/14427765
 */
AllocationTable *getClass1AllocationTable() {
    static AllocationTable *instance = NULL;

    // Do lock here.
    if (instance == NULL) {
        instance = AllocationTableConstructorWithClassName(
                CLASS1_CLASSNAME_AS_STRING);
    }
    // Do unlock.

    return instance;
}


#endif //CLASS1_H
