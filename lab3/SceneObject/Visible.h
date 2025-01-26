#ifndef __VISIBLE_H__
#define __VISIBLE_H__

#include "SceneObject.h"

class Visible : public SceneObject {
public:
    bool isVisible() const override;
};

#endif // __VISIBLE_H__
