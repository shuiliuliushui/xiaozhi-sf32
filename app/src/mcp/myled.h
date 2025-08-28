#ifndef MYLED_H
#define MYLED_H

#include "mcp_server.h"
#include "rtthread.h"
#include "drv_io.h"
#include "stdio.h"
#include "string.h"
#include "drivers/rt_drv_pwm.h"
#include "register.h"
#include "bf0_hal_pinmux.h"

//定义灯的状态
#define LED_CLOSE    0
#define LED_OPEN     1



#endif // !MYLED_H

//LED控制类
class LEDController
{
public:
    LEDController(){
        Init();
    }

private:
    void Init(){
        HAL_PIN_Set(PAD_PA32, GPIO_A32, PIN_PULLDOWN, 1);
    }
};

class LEDTool {
public:
    static void RegisterLEDTool(McpServer* server);
    static bool is_open_;
    static bool IsLightOn();  //灯光状态
};
