#ifndef _POINT_H_
#define _POINT_H_

#include <stdint.h>

struct point {
    uint32_t x;
    uint32_t y;
};

/* On fournit le prototype de la fonction distance_origine pour
 * qu'elle puisse être utilisée à l'extérieur du module point, ce qui
 * corrige le problème "implicit declaration". */
extern double distance_origine(struct point p);

#endif /* _POINT_H_ */
