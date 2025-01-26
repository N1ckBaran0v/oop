#ifndef __SCENE_H__
#define __SCENE_H__

#include <string>
#include <map>

#include "../SceneObject/SceneObject.h"

class Scene {
public:
    bool add(const std::string &, std::shared_ptr<SceneObject>);
    std::shared_ptr<SceneObject> get(const std::string &);
    bool remove(const std::string &);
    std::map<std::string, std::shared_ptr<SceneObject>>::iterator begin();
    std::map<std::string, std::shared_ptr<SceneObject>>::iterator end();

private:
    std::map<std::string, std::shared_ptr<SceneObject>> objects;
};

#endif // __SCENE_H__
