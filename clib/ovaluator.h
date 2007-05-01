#ifndef VALUATOR_H
#define VALUATOR_H

#include "owidget.h"
#include <fltk/Valuator.h>
#include <fltk/ValueInput.h>
#include <fltk/ValueOutput.h>
#include <fltk/Slider.h>
#include <fltk/ValueSlider.h>
#include "oinput.h"

namespace Ofltk {

NEW_WIDGET(Valuator);
NEW_WIDGET(Slider);
NEW_WIDGET(ValueSlider);
NEW_WIDGET(ValueInput);
NEW_WIDGET(ValueOutput);

}


#endif

