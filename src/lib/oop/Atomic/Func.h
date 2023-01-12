#ifndef FUNC_H
#define FUNC_H

#include "../Object/Object.h"

// TODO: maybe this is a redundant file, and should be removed.

typedef void (*Action0p)();
typedef void (*Action1p)(TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action2p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action3p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action4p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action5p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action6p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action7p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action8p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action9p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                         TYPEOF_ANONYMOUS_POINTER);
typedef void (*Action10p)(TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                          TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                          TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                          TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
                          TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER);

typedef TYPEOF_ANONYMOUS_POINTER (*Func0p)();
typedef TYPEOF_ANONYMOUS_POINTER (*Func1p)(TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func2p)(TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func3p)(TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func4p)(TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func5p)(TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func6p)(TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func7p)(TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER,
                                           TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func8p)(
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func9p)(
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER);
typedef TYPEOF_ANONYMOUS_POINTER (*Func10p)(
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER,
        TYPEOF_ANONYMOUS_POINTER, TYPEOF_ANONYMOUS_POINTER);


//#define FUNC1P(funcByRef, typeofP1) (*((Func1p)(funcByRef)))()

#define INVOKE_FUNC1P(Func1pByRef, p1) ({(*Func1pByRef)(p1)})

#endif //FUNC_H