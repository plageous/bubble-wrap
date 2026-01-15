//"KJ" Miclea
// Bubble Wrap
// Began on 1/14
#include <bn_core.h>
#include <bn_color.h>
#include <bn_backdrop.h>
// woah mama we're doing this for real now
#include <bn_keypad.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 31, 31));
    
    // the plan:
    // if L and UP pressed, turn background white (default)
    // if L and DOWN pressed, turn background orange
    // if L and RIGHT pressed, turn background blue
    // if L and LEFT pressed, turn background dark green    

    while(true) {
        // L + UP = white
        if (bn::keypad::l_pressed() && bn::keypad::up_pressed()) {
            bn::backdrop::set_color(bn::color(31, 31, 31));
        }
        // L + DOWN = orange
        if (bn::keypad::l_pressed() && bn::keypad::down_pressed()) {
            bn::backdrop::set_color(bn::color(31, 15, 0));
        }
        // L + RIGHT = blue
        if (bn::keypad::l_pressed() && bn::keypad::right_pressed()) {
            bn::backdrop::set_color(bn::color(20, 20, 31));
        }
        // L + LEFT = dark green
        if (bn::keypad::l_pressed() && bn::keypad::left_pressed()) {
            bn::backdrop::set_color(bn::color(0, 10, 0));
        }

        bn::core::update();    
    }
}