#include <bn_core.h>
#include <bn_color.h>
#include <bn_backdrop.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>


int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 31, 31));
    
    // the plan:
    // if L and UP pressed, turn background white (default)
    // if L and DOWN pressed, turn background orange
    // if L and RIGHT pressed, turn background blue
    // if L and LEFT pressed, turn background dark green    

    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(0, 0);
    bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(0, 10);
    bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(0, 20);
    bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(0, 30);
    bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(10, 0);
    bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(-10, 0);
    bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(0, -10);

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