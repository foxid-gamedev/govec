#ifndef GOVEC_H
#define GOVEC_H

#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/polygon2d.hpp>

namespace godot {
    class Govec : public Node2D {
        GDCLASS(Govec, Node2D)
    
    private:
       Polygon2D* _polygon;

    protected:
        static void _bind_methods();
    public:
	    Govec();
	    ~Govec();

        void _ready() override;
        void _unhandled_input(const Ref<InputEvent> &event) override;
        
        void add_point(Vector2 point);
    };
}

#endif