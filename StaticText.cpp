//
// Created by karar1 on 2026. 03. 25..
//

#include "StaticText.hpp"
#include "graphics.hpp"
using namespace genv;

StaticText::StaticText(int x, int y, int sx, int sy, std::string text) : Widget(x,y,sx,sy), _content(text){
    _cursor_pos = _content.length();
}

void StaticText::draw() {
  canvas can(_size_x, _size_y);
    can.load_font("C:\\Users\\karar1\\Downloads\\fontok\\LiberationSans-Regular.ttf", 20);
    can<<move_to(0,0)<<color(255,255,255)<<box(_size_x,_size_y)<<move_to(5,5)<<color(0,0,0)<<text(_content);

    std::string string_until_cursor = _content.substr(0, _cursor_pos);
    int text_x = 5;
    int text_y = _y + (_size_y+can.cascent()) /2;
    can<<move_to(text_x, text_y)<<color(0,0,0);
    int cursor_offset_x = gout.twidth(_content.substr(0, _cursor_pos));
    int cursor_x = text_x + cursor_offset_x;

    int cursor_pixel_pos = gout.twidth(_content.substr(0, _cursor_pos));
int vonal_eltolas = gout.twidth(string_until_cursor);

    can<<move_to(text_x+vonal_eltolas, _y+5)<<color(0,0,0)<<line(0,_size_y-10);



    gout<<stamp(can,_x,_y);

    /*
    gout<<move_to(_x,_y)<<color(255,255,255)<<box(_size_x,_size_y);
    gout<<move_to(_x+2,_y+2)<<color(0,0,0)<<box(_size_x-4,_size_y-4);

    gout<<color(255,255,255)<<move_to(_x+5,_y+_size_y/2+5)<<color(255,255,255)<<text(_content);
*/
}

void StaticText::handle(genv::event ev) {
    if (ev.type == ev_key) {
        if (ev.keycode == key_left && _cursor_pos > 0) {
            _cursor_pos--;
        }
        if (ev.keycode == key_right && _cursor_pos < _content.length()) {
            _cursor_pos++;
        }
        if (ev.keycode == key_backspace && _cursor_pos > 0) {
            _content.erase(_cursor_pos- 1,1);
            _cursor_pos--;
        }
        if (ev.keycode >= 32 && ev.keycode <= 255) {
            std::string temp = "";

            temp += (char)ev.keycode;
            _content.insert(_cursor_pos,temp);
            _cursor_pos++;
        }
    }
}



