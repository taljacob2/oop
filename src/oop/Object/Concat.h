#ifndef CONCAT_H
#define CONCAT_H

#define __CONCAT_NOT_EXPANDED__(A, B) A##B
#define CONCAT(A, B)                  __CONCAT_NOT_EXPANDED__(A, B)
#define CONCAT_SURROUND(middle, whatToSurround) \
    CONCAT(whatToSurround, CONCAT(middle, whatToSurround))

#endif //CONCAT_H