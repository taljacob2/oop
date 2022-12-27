#include "Legacy_MemberList.r"

BOOLEAN predicateFindLegacy_StringEntryByMemberName(
        const Legacy_Node *nodeThatPointsToAllocationTable,
        const char *const  memberName) {
    return strcmp(((Legacy_StringObjectContainerEntry
                            *) (nodeThatPointsToAllocationTable->data))
                          ->key,
                  memberName) == 0;
}

Legacy_Node *getMemberNodeByName(Legacy_MemberList *legacy_memberList, char *memberName) {
    return legacy_memberList->memberEntryList->findNodeByPredicateOfConstString(
            legacy_memberList->memberEntryList,
            predicateFindLegacy_StringEntryByMemberName, memberName);
}

Legacy_StringObjectContainerEntry *
getMemberStringObjectContainerEntryByName(Legacy_MemberList *legacy_memberList,
                                          char *      memberName) {
    return (getMemberNodeByName(legacy_memberList, memberName))->data;
}

Legacy_Object *
getMemberStringObjectContainerEntryValueByName(Legacy_MemberList *legacy_memberList,
                                               char *      memberName) {
    return getMemberStringObjectContainerEntryByName(legacy_memberList, memberName)
            ->value;
}

Legacy_Object *getMemberByName_Legacy_MemberList(Legacy_MemberList *legacy_memberList,
                                                   char *      memberName) {
    return getMemberStringObjectContainerEntryValueByName(legacy_memberList,
                                                          memberName);
}

Legacy_Object *addMember(Legacy_MemberList *legacy_memberList, char *memberName,
                         Legacy_Object *member) {
    Legacy_Node *objectEntryNode = Legacy_NodeConstructorWithData(
            Legacy_StringObjectContainerEntryConstructorWithKeyAndValue(
                    memberName, member));

    legacy_memberList->memberEntryList->addAsUnique(
            legacy_memberList->memberEntryList, objectEntryNode,
            predicateFindLegacy_StringEntryByMemberName, memberName);

    return member;
}

// TODO: "public" "setMember".

Legacy_MemberList *Legacy_MemberListDestructor(Legacy_MemberList *legacy_memberList) {
    legacy_memberList->memberEntryList
            ->Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData(
                    legacy_memberList->memberEntryList);

    free(legacy_memberList->legacyObjectComponent);
    free(legacy_memberList);

    return NULL;
}

/// @deprecated
Legacy_MemberList *Legacy_MemberListConstructor() {
    Legacy_MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMember       = &addMember;
    instance->getMemberByName = &getMemberByName_Legacy_MemberList;

    instance->memberEntryList = Legacy_ListConstructor();

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("Legacy_MemberList");

    addMember(
            instance, "autoDestructable",
            (Legacy_Object *) AutoDestructableConstructorWithClassName(
                    (Legacy_Object *) instance,
                    instance->legacyObjectComponent->CLASS_NAME));

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&Legacy_MemberListConstructor)};
    instance->legacyObjectComponent->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&Legacy_MemberListDestructor)};
    instance->legacyObjectComponent->destructable = &destructable;

    return instance;
}

Legacy_MemberList *Legacy_MemberListConstructorWithObjectContainer(
        Legacy_Object *objectContainerThatContainsThisLegacy_MemberList) {
    Legacy_MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMember       = &addMember;
    instance->getMemberByName = &getMemberByName_Legacy_MemberList;

    instance->memberEntryList = Legacy_ListConstructor();

    instance->legacyObjectComponent =
            Legacy_ObjectComponentConstructorClassName("Legacy_MemberList");

    addMember(
            instance, "autoDestructable",
            (Legacy_Object *) AutoDestructableConstructorWithClassName(
                    (Legacy_Object *)
                            objectContainerThatContainsThisLegacy_MemberList,
                    objectContainerThatContainsThisLegacy_MemberList->legacyObjectComponent->CLASS_NAME));

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&Legacy_MemberListConstructor)};
    instance->legacyObjectComponent->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&Legacy_MemberListDestructor)};
    instance->legacyObjectComponent->destructable = &destructable;

    return instance;
}
