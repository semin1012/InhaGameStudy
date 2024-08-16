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
        cout << "���� = " << volume << endl;
        cout << "ä�� = " << channel << endl;
        cout << "��� = " << (mode == Antenna ? "������ ���" : "���̺� ���") << endl;
        cout << "�Է� = " << (input == TV ? "TV" : "DVD") << endl;
    }
}

void Tv::set_listen_mode(Remote& r)
{
    if (state == On) r.listenMode = (r.listenMode == Remote::NORMAL) ? Remote::CONVERSATION : Remote::NORMAL;
}

void Remote::print_listen_mode()
{
    std::cout << "��� = ";
    if (listenMode == NORMAL)
        std::cout << "�Ϲݸ��";
    else std::cout << "��ȭ���";
}
