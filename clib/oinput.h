#ifndef OINPUT_H
#define OINPUT_H

#include "ocamlfltk.h"
#include "owidget.h"
#include <fltk/Input.h>
#include <fltk/IntInput.h>
#include <fltk/NumericInput.h>

namespace Ofltk {

NEW_WIDGET(Input);
NEW_WIDGET(NumericInput);
NEW_WIDGET(FloatInput);
NEW_WIDGET(IntInput);

}
#endif

