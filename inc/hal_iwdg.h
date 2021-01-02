#ifndef __HAL_IWDG_H__
#define __HAL_IWDG_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "stddef.h"
#include "stdint.h"

#include "hal.h"

#define IWDG                (NULL)

#define IWDG_PRESCALER_64   0x00000004U

typedef struct {
    uint32_t dummy;
} IWDG_TypeDef;

typedef struct {
    uint32_t Prescaler;
    uint32_t Reload;
} IWDG_InitTypeDef;

typedef struct {
    IWDG_TypeDef * Instance;
    IWDG_InitTypeDef Init;
} IWDG_HandleTypeDef;

extern int HAL_IWDG_InitCallCount;
extern int HAL_IWDG_RefreshCallCount;

HAL_StatusTypeDef HAL_IWDG_Init(IWDG_HandleTypeDef * hiwdg);
HAL_StatusTypeDef HAL_IWDG_Refresh(IWDG_HandleTypeDef * hiwdg);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __HAL_IWDG_H__
