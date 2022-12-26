#ifndef OBJECT_H
#define OBJECT_H

#include "MemberList.r"

// Forward declaration of incomplete type
typedef struct object Object;

struct object {

    /// `Object` implements `Legacy_Object`.
    Legacy_Object *object;

    MemberList *memberList;

    Legacy_ObjectContainer *(*addMemberWhichIsLegacy_ObjectContainer)(
            Object *self, char *memberName,
            Legacy_ObjectContainer *legacyObjectContainer);
    Legacy_ObjectContainer *(*addMemberWhichIsPrimitive)(
            Object *self, char *memberName,
            void *dynamicallyAllocatedPrimitive);
};

Object *ObjectConstructor(const char *className);

#endif //OBJECT_H