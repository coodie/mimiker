#ifndef _MIPS_INTR_H_
#define _MIPS_INTR_H_

#include <stdbool.h>

typedef enum {
  MIPS_SWINT0,
  MIPS_SWINT1,
  MIPS_HWINT0,
  MIPS_HWINT1,
  MIPS_HWINT2,
  MIPS_HWINT3,
  MIPS_HWINT4,
  MIPS_HWINT5,
} mips_intr_t;

typedef struct intr_handler intr_handler_t;
typedef struct exc_frame exc_frame_t;

/* Do not use these! Consider critical_enter / critical_leave instead. */
void mips_intr_enable(void);
void mips_intr_disable(void);
bool mips_intr_disabled(void);

void mips_intr_init(void);
void mips_intr_handler(exc_frame_t *frame);
void mips_intr_setup(intr_handler_t *ih, mips_intr_t irq);
void mips_intr_teardown(intr_handler_t *ih);

#endif
