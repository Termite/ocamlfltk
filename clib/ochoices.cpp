#include "ochoices.h"

namespace Ofltk {
    char Choice_id[] = "Choice-director";
    char CycleButton_id[] = "Cyclebutton-director";
    char PopupMenu_id[] = "Popupmenu-director";
}

using namespace Ofltk;

extern "C" {

    MAKE_NEW(choice);
    MAKE_NEW(cyclebutton);
    MAKE_NEW(popupmenu);

}
