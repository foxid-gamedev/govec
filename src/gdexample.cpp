#include "gdexample.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void GDExample::_bind_methods() {
}


GDExample::GDExample() {
    time_passed = 0.0;
}

GDExample::~GDExample() {

}

void GDExample::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    time_passed += delta;

	Vector2 new_position = Vector2(
        10.0 + (10.0 * sin(time_passed * 2.0)), 
        10.0 + (10.0 * cos(time_passed * 1.5))
    );

	set_position(new_position);
}