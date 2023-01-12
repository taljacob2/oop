#include "../lib/oop/oop.h"
#include "Circle.h"
#include "CircleV2.h"
#include "CircleV4.h"
#include "CircleV5.h"
#include "CircleV7.h"

int main() {
    //    Circle *circle = CircleConstructor();
    //
    //    CircleV2 *circleV2 = CircleV2Constructor();
    //

    //    Legacy_MemberListConstructor();
    //    MemberList *memberList = MemberListConstructor("MemberList");
    //    memberList->legacyObjectComponent->destructable->destructor(memberList);

    //    methodsLegacy_MemberList->methodsLegacy_MemberList->destructable->destructor(methodsLegacy_MemberList);

    //    AtomicInteger *atomicInteger = AtomicIntegerConstructor();

    //    atomicInteger->methodsLegacy_MemberList->methodsLegacy_MemberList->destructable->destructor(atomicInteger);

    //    CircleV4 *circleV4 = CircleV4Constructor();

    //    AnonymousObjectConstructor();

    //        CircleV5 *circleV5 = CircleV5Constructor();


    //        Legacy_MemberList *legacyMemberList =
    //                Legacy_MemberListConstructorWithLegacy_Object(
    //                        (Legacy_Object *) MemberListConstructor());

    //    Legacy_MemberList *legacyMemberList =
    //            Legacy_MemberListConstructorWithLegacy_Object(
    //                    (Legacy_Object *) Legacy_ListConstructor());
    //    legacyMemberList->legacyObjectComponent->destructable->destructor(legacyMemberList);


    //    MemberList * memberList1 = MemberListConstructor();
    //
    //    memberList1->addMemberWhichIsLegacy_Object(memberList1, "legacyList",
    //            (Legacy_Object *) Legacy_ListConstructor());

    //    memberList1->legacyObjectComponent->destructable->destructor(memberList1);

    //    Legacy_List *legacyList = Legacy_ListConstructor();
    //    legacyList->legacyObjectComponent->destructable->destructor(legacyList);


    //
    //        Object *object= ObjectConstructor("Object");
    //
    //        ObjectDestructor(object);


    //    // TODO: FIXME:
    //    //  Conclusion: allocationTableList doesn't receive the correct address!!!
    //    ObjectDestructor(object);

    //    Object *object = ObjectConstructor("Object");

    //    object->addPublicField(object, "legacyList",
    //                           (Legacy_Object *) Legacy_ListConstructor());

    //    object->addPublicField(object, "nestedObject",
    //                           ObjectConstructor("Object2"));
    //    ObjectDestructor((Object *) object->getPublicField(object, "nestedObject"));
    //
    //    Legacy_List *legacyList =
    //            (Legacy_List *) object->getPublicField(object, "legacyList");
    //    legacyList->legacyObjectComponent->destructable->destructor(legacyList);

    //            ObjectDestructor(object);


    //#define STRING_SIZE 5
    //    char *string = malloc(sizeof(char) * STRING_SIZE);
    //    for (char i = 0; i < STRING_SIZE - 1; i++) { string[i] = (char) (i + '0'); }
    //    string[STRING_SIZE - 1] = 0;
    //
    //    AtomicLValue *atomicLValue = AtomicLValueConstructor(string, TRUE);
    //
    //    AtomicLValue *atomicLValue2 = AtomicLValueConstructor("hello!!!", FALSE);
    //
    //    printf("%s\n", (char *) getData_AtomicLValue(atomicLValue));
    //    printf("%s\n", (char *) getData_AtomicLValue(atomicLValue2));
    //
    //    printf("%s\n", (char *) getData_AtomicRValue(AtomicRValueConstructor(
    //                           (RValue) "Hi PrimitiveTesting!!!")));
    //
    //    printf("%d\n", (int) getData_AtomicRValue(AtomicRValueConstructor(-4)));


    //    CircleV7 *circleV7 = CircleV7Constructor();


    // TODO: Problem found. `addMemberValue` does not work properly.
    Object *object = ObjectConstructor("Object");
    object->addMemberValue(object, PUBLIC, FIELD, "nestedObject",
                           ObjectConstructor("Object2"));


    return 0;
}
