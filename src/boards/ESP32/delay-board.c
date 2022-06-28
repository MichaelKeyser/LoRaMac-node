
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "delay-board.h"

void DelayMsMcu( uint32_t ms )
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}