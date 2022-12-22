#include "Class1.h"

void print(Class1 *class1) { printf("x = %d\n", class1->x); }

void addOneToX(Class1 *class1) { class1->x += 1; }

void *Class1Destructor(Class1 *class1) {
    if (class1 == NULL) { return NULL; }

    deleteNodeThatHasTheGivenData(
            class1->CLASS_ALLOCATION_TABLE->allocationAddressList,
            class1->ALLOCATION_ADDRESS);

    free(class1);

    return NULL;
}

void constructor_Class1_fields(Class1 *class1) {
    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&Class1Constructor)};
    class1->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&Class1Destructor)};
    class1->destructable = &destructable;

    class1->x         = 1;
    class1->print     = &print;
    class1->addOneToX = &addOneToX;
}

Class1 *Class1Constructor() {
    Class1 *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Class1_fields(obj);
    obj->CLASS_NAME         = CLASS1_CLASSNAME_AS_STRING;
    obj->ALLOCATION_ADDRESS = obj;
    obj->CLASS_ALLOCATION_TABLE =
            findAllocationTableByClassName(obj->CLASS_NAME);
    if (obj->CLASS_ALLOCATION_TABLE == NULL) {
        obj->CLASS_ALLOCATION_TABLE =
                AllocationTableConstructorWithClassName(obj->CLASS_NAME);

        // Create a node that its data points to `obj->CLASS_ALLOCATION_TABLE`.
        Node *nodeThatItsDataPointsClassAllocationTable =
                NodeConstructorWithDataAndDataSize(obj->CLASS_ALLOCATION_TABLE,
                                                   sizeof(AllocationTable *));

        // Add this node to `GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList`.
        add(GLOBAL_ALLOCATION_TABLE_LIST->allocationTableList,
            nodeThatItsDataPointsClassAllocationTable);
    }

    // Create a node that its data points to the "pointer of `obj`".
    Node *nodeThatItsDataPointsToThePointerOfObj =
            NodeConstructorWithDataAndDataSize(obj->ALLOCATION_ADDRESS,
                                               sizeof(void *));

    // Add this node to `obj->CLASS_ALLOCATION_TABLE->allocationAddressList`.
    add(obj->CLASS_ALLOCATION_TABLE->allocationAddressList,
        nodeThatItsDataPointsToThePointerOfObj);

    return obj;
}
