#include "MemberList.r"

BOOLEAN predicateFindLegacy_StringEntryByMemberName(
        const Legacy_Node *nodeThatPointsToAllocationTable,
        const char *const  memberName) {
    return strcmp(((Legacy_StringEntry *) (nodeThatPointsToAllocationTable
                                                   ->data))
                          ->key,
                  memberName) == 0;
}

Legacy_Node *getMemberNodeByName(MemberList *memberList, char *memberName) {
    return memberList->memberEntryList->findNodeByPredicateOfConstString(
            memberList->memberEntryList,
            predicateFindLegacy_StringEntryByMemberName, memberName);
}

Legacy_StringEntry *
getMemberStringObjectContainerEntryByName(MemberList *memberList,
                                          char *      memberName) {
    return (getMemberNodeByName(memberList, memberName))->data;
}

ObjectContainer *
getMemberStringObjectContainerEntryValueByName(MemberList *memberList,
                                               char *      memberName) {
    return getMemberStringObjectContainerEntryByName(memberList, memberName)
            ->value;
}

ObjectContainer *getMemberByName(MemberList *memberList, char *memberName) {
    return getMemberStringObjectContainerEntryValueByName(memberList,
                                                          memberName);
}

ObjectContainer *addMember(MemberList *memberList, char *memberName,
                           ObjectContainer *member) {
    Legacy_Node *objectEntryNode = Legacy_NodeConstructorWithDataAndDataSize(
            Legacy_StringEntryConstructorWithKeyAndValue(memberName, member),
            sizeof(Legacy_StringEntry *));

    memberList->memberEntryList->addAsUnique(
            memberList->memberEntryList, objectEntryNode,
            predicateFindLegacy_StringEntryByMemberName, memberName);

    return member;
}

MemberList *MemberListDestructor(MemberList *memberList) {
    memberList->memberEntryList
            ->Legacy_ListDestructorWithInvokingDeconstructorOfEachNodeData(
                    memberList->memberEntryList);

    free(memberList->object);
    free(memberList);

    return NULL;
}

MemberList *MemberListConstructor() {
    MemberList *instance = calloc(1, sizeof *instance);
    if (instance == NULL) { /* error handling here */
    }

    instance->addMember       = &addMember;
    instance->getMemberByName = &getMemberByName;

    instance->memberEntryList = Legacy_ListConstructor();

    instance->object = ObjectConstructorClassName("MemberList");

    addMember(instance, "autoDestructable",
              (ObjectContainer *) AutoDestructableConstructorWithClassName(
                      (ObjectContainer *) instance,
                      instance->object->CLASS_NAME));

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&MemberListConstructor)};
    instance->object->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&MemberListDestructor)};
    instance->object->destructable = &destructable;

    return instance;
}
