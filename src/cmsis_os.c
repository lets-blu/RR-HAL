#include "cmsis_os.h"

osThread_t os_thread;
osSemaphore_t os_semaphore;

osStatus osDelay(uint32_t millisec)
{
    (void)millisec;
    return osOK;
}

osThreadId osThreadCreate(const osThreadDef_t * thread_def, void * argument)
{
    (void)thread_def;
    (void)argument;
    os_thread.state = osThreadReady;
    return &os_thread;
}

osStatus osThreadTerminate(osThreadId thread_id)
{
    thread_id->state = osThreadDeleted;
    return osOK;
}

osThreadState osThreadGetState(osThreadId thread_id)
{
    return thread_id->state;
}

osSemaphoreId osSemaphoreCreate(const osSemaphoreDef_t * semaphore_def, int32_t count)
{
    (void)semaphore_def;
    os_semaphore.count = count;
    return &os_semaphore;
}

int32_t osSemaphoreWait(osSemaphoreId semaphore_id, uint32_t millisec)
{
    (void)millisec;
    return --(semaphore_id->count);
}

osStatus osSemaphoreRelease(osSemaphoreId semaphore_id)
{
    semaphore_id->count++;
    return osOK;
}
