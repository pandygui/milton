// Copyright (c) 2015 Sergio Gonzalez. All rights reserved.
// License: https://github.com/serge-rgb/milton#license

#pragma once


void init_localization();


// Re-ordering is OK.
enum Texts
{
    TXT_file,
    TXT_open_milton_canvas,
    TXT_export_to_image_DOTS,
    TXT_quit,
    TXT_canvas,
    TXT_help,
    TXT_brushes,
    TXT_opacity,
    TXT_brush_size,
    TXT_switch_to_brush,
    TXT_switch_to_eraser,
    TXT_set_background_color,
    TXT_choose_background_color,
    TXT_default_background_color,
    TXT_color,
    TXT_export_DOTS,
    TXT_MSG_click_and_drag_instruction,
    TXT_current_selection,
    TXT_scale_up,
    TXT_final_image_resolution,
    TXT_export_selection_to_image_DOTS,
    TXT_MSG_memerr_did_not_write,
    TXT_error,
    TXT_cancel,
    TXT_view,
    TXT_toggle_gui_visibility,
    TXT_layers,

    // ==== Translation to spanish completed until this point

    TXT_settings,
    TXT_switch_to_primitive,
    TXT_help_me,
    TXT_new_layer,
    TXT_rename,
    TXT_move,
    TXT_move_canvas,
    TXT_stop_moving_canvas,
    TXT_up,
    TXT_down,
    TXT_are_you_sure,
    TXT_cant_be_undone,
    TXT_yes,
    TXT_no,
    TXT_ok,
    TXT_delete,
    TXT_edit,
    TXT_undo,
    TXT_redo,
    TXT_tools,
    TXT_brush,
    TXT_eraser,
    TXT_zoom_in,
    TXT_zoom_out,
    TXT_brush_options,
    TXT_set_opacity_to,
    TXT_save_milton_canvas_as_DOTS,
    TXT_new_milton_canvas,
    TXT_decrease_brush_size,
    TXT_increase_brush_size,
    TXT_eye_dropper,
    TXT_milton_version,
    TXT_website,
    TXT_disable_stroke_smoothing,
    TXT_enable_stroke_smoothing,
    TXT_transparent_background,
    TXT_set_current_background_color_as_default,
    TXT_background_color,
    TXT_OPENBRACKET_default_canvas_CLOSE_BRACKET,
    TXT_background_COLON,
    TXT_could_not_delete_default_canvas,

    TXT_Count,
};

char* loc(Texts id);
