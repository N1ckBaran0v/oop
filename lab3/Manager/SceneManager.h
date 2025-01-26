#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "../Scene/Scene.h"
#include "BaseManager.h"

class SceneManager : public BaseManager {
public:
    void accept(ManagerVisitor &) override;
    void setScene(std::shared_ptr<Scene>);
    std::shared_ptr<Scene> getScene();

private:
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();
};

#endif // __SCENE_MANAGER_H__
