#include "hal_iwdg.h"

int HAL_IWDG_InitCallCount;
int HAL_IWDG_RefreshCallCount;

HAL_StatusTypeDef HAL_IWDG_Init(IWDG_HandleTypeDef * hiwdg)
{
    (void)hiwdg;
    HAL_IWDG_InitCallCount++;
    return HAL_OK;
}

HAL_StatusTypeDef HAL_IWDG_Refresh(IWDG_HandleTypeDef * hiwdg)
{
    (void)hiwdg;
    HAL_IWDG_RefreshCallCount++;
    return HAL_OK;
}
