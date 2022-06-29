

#include "delay-board.h"

void DelayMsMcu( uint32_t ms )
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}