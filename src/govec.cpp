#include "govec.h"

#include <godot_cpp/classes/input_event_mouse_button.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void Govec::_bind_methods() {

}

Govec::Govec() {
}

Govec::~Govec() {
}

void Govec::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    _polygon = memnew(Polygon2D);

    add_child(_polygon);
}

void Govec::_unhandled_input(const Ref<InputEvent> &event) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    InputEventMouseButton* mouseButton = Object::cast_to<InputEventMouseButton>(event.ptr());

    if (mouseButton && mouseButton->is_pressed() && mouseButton->get_button_index() == MOUSE_BUTTON_LEFT) {
        auto mousePos = get_global_mouse_position();
        add_point(mousePos);
    }
}

void Govec::add_point(Vector2 point) {
    UtilityFunctions::print("mouse: ", point);
}