#ifndef __HAL_GPIO_H__
#define __HAL_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "stdint.h"

#define GPIOA                           (GPIO_BASE)
#define GPIOB                           (GPIO_BASE + 1)
#define GPIOC                           (GPIO_BASE + 2)

#define GPIO_PIN_0                      ((uint16_t)0x0001)
#define GPIO_PIN_1                      ((uint16_t)0x0002)
#define GPIO_PIN_2                      ((uint16_t)0x0004)
#define GPIO_PIN_3                      ((uint16_t)0x0008)
#define GPIO_PIN_4                      ((uint16_t)0x0010)
#define GPIO_PIN_5                      ((uint16_t)0x0020)
#define GPIO_PIN_6                      ((uint16_t)0x0040)
#define GPIO_PIN_7                      ((uint16_t)0x0080)
#define GPIO_PIN_8                      ((uint16_t)0x0100)
#define GPIO_PIN_9                      ((uint16_t)0x0200)
#define GPIO_PIN_10                     ((uint16_t)0x0400)
#define GPIO_PIN_11                     ((uint16_t)0x0800)
#define GPIO_PIN_12                     ((uint16_t)0x1000)
#define GPIO_PIN_13                     ((uint16_t)0x2000)
#define GPIO_PIN_14                     ((uint16_t)0x4000)
#define GPIO_PIN_15                     ((uint16_t)0x8000)
#define GPIO_PIN_All                    ((uint16_t)0xFFFF)

#define GPIO_PIN_MASK                   0x0000FFFFU

#define GPIO_MODE_INPUT                 0x00000000U
#define GPIO_MODE_OUTPUT_PP             0x00000001U
#define GPIO_MODE_IT_RISING             0x10110000U
#define GPIO_MODE_IT_FALLING            0x10210000U
#define GPIO_MODE_IT_RISING_FALLING     0x10310000U

#define GPIO_NOPULL                     0x00000000U
#define GPIO_PULLUP                     0x00000001U

#define GPIO_SPEED_FREQ_LOW             0x00000002U

typedef struct {
    uint32_t IDR;
    uint32_t ODR;
} GPIO_TypeDef;

typedef struct {
    uint32_t Pin;
    uint32_t Mode;
    uint32_t Pull;
    uint32_t Speed;
} GPIO_InitTypeDef;

typedef enum {
    GPIO_PIN_RESET,
    GPIO_PIN_SET
} GPIO_PinState;

extern GPIO_TypeDef GPIO_BASE[];
extern int HAL_GPIO_InitCallCount;

#define IS_GPIO_ALL_INSTANCE(INSTANCE) \
    (((INSTANCE) == GPIOA) || ((INSTANCE) == GPIOB) || ((INSTANCE) == GPIOC))

#define IS_GPIO_PIN(PIN) \
    ((((PIN) & GPIO_PIN_MASK) != 0x00U) && (((PIN) & ~GPIO_PIN_MASK) == 0x00U))

#define IS_GPIO_MODE(MODE) \
    (((MODE) == GPIO_MODE_INPUT) || \
     ((MODE) == GPIO_MODE_OUTPUT_PP) || \
     ((MODE) == GPIO_MODE_IT_RISING) || \
     ((MODE) == GPIO_MODE_IT_FALLING) || \
     ((MODE) == GPIO_MODE_IT_RISING_FALLING))

void HAL_GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_InitTypeDef * GPIO_Init);
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __HAL_GPIO_H__
