#include "hal_cortex.h"

int HAL_NVIC_SetPriorityCallCount;
int HAL_NVIC_EnableIRQCallCount;
int HAL_NVIC_DisableIRQCallCount;

void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority)
{
    (void)IRQn;
    (void)PreemptPriority;
    (void)SubPriority;
    HAL_NVIC_SetPriorityCallCount++;
}

void HAL_NVIC_EnableIRQ(IRQn_Type IRQn)
{
    (void)IRQn;
    HAL_NVIC_EnableIRQCallCount++;
}

void HAL_NVIC_DisableIRQ(IRQn_Type IRQn)
{
    (void)IRQn;
    HAL_NVIC_DisableIRQCallCount++;
}
