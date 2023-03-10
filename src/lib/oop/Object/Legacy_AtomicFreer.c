#include "Legacy_AtomicFreer.r"

/**
 * @brief `Destructs`s the given legacy_atomicFreer, and `free`s its
 *        `legacy_atomicFreer->data`.
 */
void *Legacy_AtomicFreerDestructor(Legacy_AtomicFreer *atomicFreer) {
    if (atomicFreer == NULL) { return NULL; }

    if (atomicFreer->legacyObjectComponent->destructorInvocationStatus ==
        WAS_NOT_INVOKED) {
        atomicFreer->legacyObjectComponent->destructorInvocationStatus =
                WAS_INVOKED_ONCE;
        free(atomicFreer->data);

        free(atomicFreer->legacyObjectComponent);

        free(atomicFreer);
    }

    return NULL;
}

Legacy_AtomicFreer *Legacy_AtomicFreerConstructor() {
    Legacy_AtomicFreer *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("Legacy_AtomicFreer");

    static Destructable const destructable = {
            .destructor =
                    (void *(*const)(void *) )(&Legacy_AtomicFreerDestructor)};
    instance->legacyObjectComponent->destructable = &destructable;

    instance->data = NULL;

    return instance;
}

Legacy_AtomicFreer *Legacy_AtomicFreerConstructorWithData(void *data) {
    Legacy_AtomicFreer *instance = Legacy_AtomicFreerConstructor();

    instance->data = data;

    return instance;
}