#include "BalanceAnimStep.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

BalanceAnimStep::BalanceAnimStep(MainWindow* win, int animIndex, int width, int height, BalancePos::Pos vert, BalancePos::Pos horiz) : UndoStep(win)
{
    animationIndex = animIndex;
    w = width;
    h = height;
    ve = vert;
    ho = horiz;

    Animation* anim = win->getSheet()->getAnimation(animIndex);
    QVector<Frame*> startFrames = anim->getFrames();
    foreach(Frame* f, startFrames)
    {
        frames.append(new QImage(f->getImage()->copy()));
        checked.append(f->isSelected());
    }
}

BalanceAnimStep::~BalanceAnimStep()
{
    foreach(QImage* i, frames)
        delete i;
}

void BalanceAnimStep::undo()
{
    Animation* a = mainWindow->getSheet()->getAnimation(animationIndex);
    QVector<QImage*> origFrames;
    foreach(QImage* img, frames)
        origFrames.append(new QImage(img->copy()));
    a->clear();
    a->insertImages(origFrames);
    for(int i = 0; i < checked.length(); i++)
    {
        Frame* f = a->getFrame(i);
        if(f && checked.at(i))
            f->selectToggle();
    }
    mainWindow->getSheet()->refresh();
    mainWindow->getSheet()->updateSceneBounds();
    mainWindow->drawAnimation();
    mainWindow->updateSelectedAnim();
}

void BalanceAnimStep::redo()
{
    Animation* a = mainWindow->getSheet()->getAnimation(animationIndex);
    a->balance(QPoint(w, h), ve, ho);
    mainWindow->getSheet()->refresh();
    mainWindow->getSheet()->updateSceneBounds();
    mainWindow->drawAnimation();
    mainWindow->updateSelectedAnim();
}
