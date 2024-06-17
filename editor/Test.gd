extends Node2D


func _input(event: InputEvent) -> void:
	if event is InputEventMouseButton and event.pressed and event.button_index == MOUSE_BUTTON_LEFT:
		var mouse_pos := get_global_mouse_position()
		set_point(mouse_pos)
		

func set_point(pos: Vector2) -> void:
	print("mouse: ", pos)
