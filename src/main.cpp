#include <bn_core.h>
#include <bn_color.h>
#include <bn_backdrop.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>
#include <bn_math.h>
#include <bn_fixed.h>


int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 31, 31));
    
    // the plan:
    // if L and UP pressed, turn background white (default)
    // if L and DOWN pressed, turn background orange
    // if L and RIGHT pressed, turn background blue
    // if L and LEFT pressed, turn background dark green    

    /* dots in the shape of a cross
    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(0, 0);
    bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(0, 10);
    bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(0, 20);
    bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(0, 30);
    bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(10, 0);
    bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(-10, 0);
    bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(0, -10);
    */

    /* brute force
    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(-40, 40);
    bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-30, 40);
    bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(-20, 40);
    bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-10, 40);
    bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(0, 40);
    bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(10, 40);
    bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(20, 40);
    bn::sprite_ptr myCircle8 = bn::sprite_items::dot.create_sprite(30, 40);
    bn::sprite_ptr myCircle9 = bn::sprite_items::dot.create_sprite(40, 40);
    */

    bn::vector<bn::sprite_ptr, 38> circles = {};

    // square (box)
    for (int x = -40; x <= 40; x += 10) {
        circles.push_back(bn::sprite_items::dot.create_sprite(x, 40));
    }

    for (int x = -40; x <= 40; x += 10) {
        circles.push_back(bn::sprite_items::dot.create_sprite(x, -40));
    }

    for (int y = -30; y <= 30; y += 10) {
        circles.push_back(bn::sprite_items::dot.create_sprite(-40, y));
    }

    for (int y = -30; y <= 30; y += 10) {
        circles.push_back(bn::sprite_items::dot.create_sprite(40, y));
    }

    // circle
    bn::vector<bn::sprite_ptr, 36> circles2 = {};
    int r = 70;
    for (int a = 0; a < 360; a += 10) {
        int x = (bn::fixed(r) * bn::degrees_cos(a)).integer();
        int y = (bn::fixed(r) * bn::degrees_sin(a)).integer();
        circles2.push_back(bn::sprite_items::dot.create_sprite(x, y));
    }

    while(true) {
        // L + UP = white
        if (bn::keypad::l_held() && bn::keypad::up_pressed()) {
            bn::backdrop::set_color(bn::color(31, 31, 31));
        }
        // L + DOWN = orange
        if (bn::keypad::l_held() && bn::keypad::down_pressed()) {
            bn::backdrop::set_color(bn::color(31, 15, 0));
        }
        // L + RIGHT = blue
        if (bn::keypad::l_held() && bn::keypad::right_pressed()) {
            bn::backdrop::set_color(bn::color(20, 20, 31));
        }
        // L + LEFT = dark green
        if (bn::keypad::l_held() && bn::keypad::left_pressed()) {
            bn::backdrop::set_color(bn::color(0, 10, 0));
        }

        bn::core::update();    
    }
}