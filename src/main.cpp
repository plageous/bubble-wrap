//"KJ" Miclea
// Bubble Wrap
// Began on 1/14
#include <bn_core.h>
#include <bn_color.h>
#include <bn_backdrop.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 15, 0));
    
    while(true) {
        bn::core::update();    
    }
}