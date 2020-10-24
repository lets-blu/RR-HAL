#include "hal_gpio.h"

GPIO_TypeDef GPIO_BASE[3];
int HAL_GPIO_InitCallCount;

void HAL_GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_InitTypeDef * GPIO_Init)
{
    (void)GPIOx;
    (void)GPIO_Init;
    HAL_GPIO_InitCallCount++;
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
    if ((GPIOx->IDR & GPIO_Pin) != 0)
    {
        return GPIO_PIN_SET;
    }
    else
    {
        return GPIO_PIN_RESET;
    }
}

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (PinState != GPIO_PIN_RESET)
    {
        GPIOx->ODR |= GPIO_Pin;
    }
    else
    {
        GPIOx->ODR &= ~GPIO_Pin;
    }
}

#if 0
#include "hal_gpio.h"

GPIO_TypeDef HAL_GPIO_BASE[3];
int HAL_GPIO_InitCallCount;

void HAL_GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_InitTypeDef * GPIO_Init)
{
    (void)GPIOx;
    (void)GPIO_Init;
    HAL_GPIO_InitCallCount++;
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
    if ((GPIOx->IDR & GPIO_Pin) != 0)
    {
        return GPIO_PIN_SET;
    }
    else
    {
        return GPIO_PIN_RESET;
    }
}

void HAL_GPIO_WritePin(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (PinState != GPIO_PIN_RESET)
    {
        GPIOx->ODR |= GPIO_Pin;
    }
    else
    {
        GPIOx->ODR &= ~GPIO_Pin;
    }
}
#endif
