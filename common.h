#ifndef COMMON_H
#define COMMON_H

#define SW_MIN(a, b) ((a) < (b)) ? (a) : (b)

#define SW_CATCH_NULL_AND_RETURN_VALUE(x, ret) \
    do {                                       \
        if (!(x))                              \
            return (ret);                      \
    } while (0)

#define SW_CATCH_NULL_AND_RETURN(x) \
    do {                            \
        if (!(x))                   \
            return;                 \
    } while (0)

#endif
