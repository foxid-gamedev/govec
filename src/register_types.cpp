#include "register_types.h"

#include "govec.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_govec_module(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	// ClassDB::register_class<GDExample>();
    ClassDB::register_class<Govec>();
}

void uninitialize_govec_module(ModuleInitializationLevel p_level)
{	
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

// Initialization
extern "C" {
    GDExtensionBool GDE_EXPORT govec_library_init(
        GDExtensionInterfaceGetProcAddress p_get_proc_address, 
        const GDExtensionClassLibraryPtr p_library, 
        GDExtensionInitialization *r_initialization) {

        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_govec_module);
        init_obj.register_terminator(uninitialize_govec_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}