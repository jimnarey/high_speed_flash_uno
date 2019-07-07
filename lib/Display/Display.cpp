#include <Arduino.h>
#include <U8g2lib.h>
#include <Display.h>

U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R0);


void Display::init()
{
    u8g2.begin();
    // u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.setFont(u8g2_font_7x14_tf);
}

// void Display::writeDisplay(byte page)
// {
//     u8g2.setCursor(0, 20);
//     u8g2.print(page);
// }

void Display::refreshDisplay(byte page)
{
 u8g2.firstPage();
    do
    {
        u8g2.setCursor(0, 20);
        u8g2.print(page);
    } 
    while (u8g2.nextPage());
}