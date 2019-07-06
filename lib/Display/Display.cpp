#include <Arduino.h>
#include <U8glib.h>
#include <Display.h>

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE); // Just for 0.91”(128*32)

void Display::init()
{
    if (u8g.getMode() == U8G_MODE_R3G3B2)
    {
        u8g.setColorIndex(255); // white
    }
    else if (u8g.getMode() == U8G_MODE_GRAY2BIT)
    {
        u8g.setColorIndex(3); // max intensity
    }
    else if (u8g.getMode() == U8G_MODE_BW)
    {
        u8g.setColorIndex(1); // pixel on
    }
    else if (u8g.getMode() == U8G_MODE_HICOLOR)
    {
        u8g.setHiColorByRGB(255, 255, 255);
    }
}

void Display::writeDisplay(byte page)
{
    u8g.setFont(u8g_font_unifont);
    u8g.setPrintPos(0, 10);
    u8g.print(page);
}

void Display::refreshDisplay(byte page)
{
 u8g.firstPage();
    do
    {
        Display::writeDisplay(page);
    } 
    while (u8g.nextPage());
}