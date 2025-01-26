#ifndef __INVISIBLE_H__
#define __INVISIBLE_H__

#include "SceneObject.h"

class Invisible : public SceneObject {
public:
    bool isVisible() const override;
};

#endif // __INVISIBLE_H__
