#ifndef OBUTTON_H
#define OBUTTON_H

#include "ocamlfltk.h"
#include "owidget.h"
#include <fltk/Button.h>
#include <fltk/CheckButton.h>
#include <fltk/LightButton.h>
#include <fltk/RadioButton.h>
#include <fltk/HighlightButton.h>
#include <fltk/RepeatButton.h>
#include <fltk/ReturnButton.h>
#include <fltk/ToggleButton.h>

namespace Ofltk {

NEW_WIDGET(Button)
NEW_WIDGET(CheckButton);
NEW_WIDGET(LightButton);
NEW_WIDGET(RadioButton);
NEW_WIDGET(HighlightButton);
NEW_WIDGET(RepeatButton);
NEW_WIDGET(ReturnButton);
NEW_WIDGET(ToggleButton);

}

#endif
