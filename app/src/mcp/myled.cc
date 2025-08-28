#include "rtthread.h"
#include "myled.h"
#include "drv_io.h"
#include "stdio.h"
#include "string.h"
#include "drivers/rt_drv_pwm.h"
#include "bf0_hal.h"


#define LED_PIN 32
bool LEDTool::IsLightOn() {
    // 如果正在循环变色，则认为灯是开启状态
    return is_open_;
}
bool LEDTool::is_open_ = false;

void LEDTool::RegisterLEDTool(McpServer* server) {
    //打开LED灯
        server->AddTool(
            "self.myled.turn_on_the_light",
            "打开灯",
            PropertyList(),
            [](const PropertyList&) -> ReturnValue {
            if (is_open_) return true;
            is_open_ = true;
            // 配置PA32为GPIO输出模式并输出低电平（点亮）
            rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
            rt_pin_write(LED_PIN, PIN_LOW);
            return true;
    }
    );

}
