#include "detect.h"

void test(std::string name,LightColor enemy_color,int light_height,int armor_width,int armor_height,int limit) {
    Armour a;
    a.m_width=armor_width;
    a.m_height=armor_height;
    Light l;
    l.m_height=light_height;
    l.enemy_color = enemy_color;

    Armor_detector ArmorDetector;
    ArmorDetector.show(name,a,l,limit);
}

int main() {
    /**
    *param: 路径 灯条高 装甲板宽 装甲板高 二值化阈值 
    */
    //test("1.avi",RED,6,13.5,10,80);
    //test("2.avi",RED,6,13.5,10,200);
    test("3.avi",BLUE,6,13.5,10,250);

    return 0;
}