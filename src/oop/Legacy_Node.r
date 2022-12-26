#ifndef CLASS_LEGACY_NODE_R
#define CLASS_LEGACY_NODE_R

#include "Constructable.r"
#include "Destructable.r"
#include "Legacy_Object.r"
#include <stdlib.h>

// Forward declaration of incomplete type
typedef struct legacy_node Legacy_Node;

struct legacy_node {

    /// `Legacy_Node` implements `Legacy_Object`.
    Legacy_Object *object;

    void *       data;
    size_t       dataSize;
    Legacy_Node *next;
};

Legacy_Node *Legacy_NodeConstructor();

Legacy_Node *Legacy_NodeConstructorWithDataAndDataSize(void * data,
                                                       size_t dataSize);

#endif //CLASS_LEGACY_NODE_R
