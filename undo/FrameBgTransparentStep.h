#ifndef FRAMEBGTRANSPARENTSTEP_H
#define FRAMEBGTRANSPARENTSTEP_H
#include "UndoStep.h"

class FrameBgTransparentStep : public UndoStep
{
    bool previousTransparent;
    bool newTransparent;
public:
    FrameBgTransparentStep(MainWindow* w, bool prev, bool next);

    void undo();
    void redo();
    bool isDifferent() {return previousTransparent != newTransparent;}
};

#endif // FRAMEBGTRANSPARENTSTEP_H
