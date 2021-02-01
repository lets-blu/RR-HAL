#ifndef __CMSIS_OS_H__
#define __CMSIS_OS_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "stdint.h"

#define osWaitForever 0xFFFFFFFF

typedef enum {
    osOK = 0
} osStatus;

typedef enum {
    osPriorityNormal    =  0,
    osPriorityRealtime  = +3
} osPriority;

typedef struct {
    char * name;
    osPriority tpriority;
    uint32_t instances;
    uint32_t stacksize;
    void (*pthread)(const void * argument);
} osThreadDef_t;

typedef enum {
    osThreadReady   = 0x1,
    osThreadDeleted = 0x4
} osThreadState;

typedef struct {
    osThreadState state;
} osThread_t;

typedef struct {
    uint32_t dummy;
} osSemaphoreDef_t;

typedef struct {
    uint32_t count;
} osSemaphore_t;

typedef osThread_t * osThreadId;
typedef osSemaphore_t * osSemaphoreId;

#define osThreadDef(name, thread, priority, instances, stacksz) \
    const osThreadDef_t os_thread_def_##name = \
    {#name, (priority), (instances), (stacksz), (thread)}

#define osThread(name) \
    &os_thread_def_##name

#define osSemaphoreDef(name) \
    const osSemaphoreDef_t os_semaphore_def_##name = \
    {0}

#define osSemaphore(name) \
    &os_semaphore_def_##name

osStatus osDelay(uint32_t millisec);

osThreadId osThreadCreate(const osThreadDef_t * thread_def, void * argument);
osStatus osThreadTerminate(osThreadId thread_id);
osThreadState osThreadGetState(osThreadId thread_id);

osSemaphoreId osSemaphoreCreate(const osSemaphoreDef_t * semaphore_def, int32_t count);
int32_t osSemaphoreWait(osSemaphoreId semaphore_id, uint32_t millisec);
osStatus osSemaphoreRelease(osSemaphoreId semaphore_id);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __CMSIS_OS_H__
