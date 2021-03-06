#ifndef SHEETFONTSTEP_H
#define SHEETFONTSTEP_H
#include "UndoStep.h"
#include <QFont>

class SheetFontStep : public UndoStep
{
    QFont origFont, newFont;
public:
    SheetFontStep(MainWindow* w, QFont before, QFont after);

    void undo();
    void redo();
    bool isDifferent() {return origFont != newFont;}
};

#endif // SHEETFONTSTEP_H
