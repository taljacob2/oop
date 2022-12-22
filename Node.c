#include "Node.h"

/**
 * @brief `free`s the given node, and returns its `node->data`.
 *
 * @param node
 * @return
 */
void *NodeDestructor(Node *node) {
    if (node == NULL) { return NULL; }

    void *nodeData = node->data;
    free(node);
    return nodeData;
}

void constructor_Node_fields(Node *node) {
    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&NodeConstructor)};
    node->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&NodeDestructor)};
    node->destructable = &destructable;

    node->data     = NULL;
    node->dataSize = 0;
    node->next     = NULL;
}

Node *NodeConstructor() {
    Node *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Node_fields(obj);

    return obj;
}

Node *NodeConstructorWithDataAndDataSize(void *data, size_t dataSize) {
    Node *obj = NodeConstructor();

    obj->data     = data;
    obj->dataSize = dataSize;

    return obj;
}