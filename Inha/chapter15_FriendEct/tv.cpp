#include "tv.h"
#include <iostream>

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV = " << (state == Off ? "OFF" : "ON") << endl;
    if (state == On)
    {
        cout << "볼륨 = " << volume << endl;
        cout << "채널 = " << channel << endl;
        cout << "모드 = " << (mode == Antenna ? "지상파 방송" : "케이블 방송") << endl;
        cout << "입력 = " << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Tv::set_listen_mode(Remote& r)
{
    if (state == On) r.listenMode = (r.listenMode == Remote::NORMAL) ? Remote::CONVERSATION : Remote::NORMAL;
}

void Remote::print_listen_mode()
{
    std::cout << "모드 = ";
    if (listenMode == NORMAL)
        std::cout << "일반모드";
    else std::cout << "대화모드";
}
