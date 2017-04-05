#include "Component.h"
#include "MomentaryPushButton.h"
#include "Pin.h"
#include "RgbLed.h"

OutputPin red(8);
PowerPin power(9);
OutputPin green(10);
OutputPin blue(11);

RgbLed<PowerPin> led(red, power, green, blue);

InputPin buttoninput(5);
PowerPin buttonpower(6);
GroundPin buttonground(7);

MomentaryPushButton button(buttoninput, buttonpower, buttonground);

void setup()
{
    led.setup();
    button.setup();
    Component::CheckSetup();
    Pin::ValidateSingleUsage();
}

void loop()
{
    if (button.high())
    {
        led.red();
    }
    else
    {
        led.green();
    }
}
