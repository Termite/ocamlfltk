#include "ooutput.h"

namespace Ofltk {
    char Output_id[] = "output-director";
    char MultiLineOutput_id[] = "multiline-director";
    char WordwrapOutput_id[] = "wordwrap-director";
}

using namespace Ofltk;

extern "C" {
    MAKE_NEW(output);
    MAKE_NEW(multiline);
    MAKE_NEW(wordwrap);

}

