#ifndef __HAL_CORTEX_H__
#define __HAL_CORTEX_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "stdint.h"

typedef enum {
    EXTI0_IRQn      = 6,
    EXTI1_IRQn      = 7,
    EXTI2_IRQn      = 8,
    EXTI3_IRQn      = 9,
    EXTI4_IRQn      = 10,
    EXTI9_5_IRQn    = 23,
    EXTI15_10_IRQn  = 40
} IRQn_Type;

extern int HAL_NVIC_SetPriorityCallCount;
extern int HAL_NVIC_EnableIRQCallCount;
extern int HAL_NVIC_DisableIRQCallCount;

void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __HAL_CORTEX_H__
