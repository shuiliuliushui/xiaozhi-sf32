#include "rtthread.h"
#include "myled.h"
#include "drv_io.h"
#include "stdio.h"
#include "string.h"
#include "drivers/rt_drv_pwm.h"
#include "bf0_hal.h"


#define LED_PIN 32
bool LEDTool::IsLightOn() {
    // �������ѭ����ɫ������Ϊ���ǿ���״̬
    return is_open_;
}
bool LEDTool::is_open_ = false;

void LEDTool::RegisterLEDTool(McpServer* server) {
    //��LED��
        server->AddTool(
            "self.myled.turn_on_the_light",
            "�򿪵�",
            PropertyList(),
            [](const PropertyList&) -> ReturnValue {
            if (is_open_) return true;
            is_open_ = true;
            // ����PA32ΪGPIO���ģʽ������͵�ƽ��������
            rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
            rt_pin_write(LED_PIN, PIN_LOW);
            return true;
    }
    );

}
