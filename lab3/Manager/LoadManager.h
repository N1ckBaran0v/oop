#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "../SceneObjectCreator/LoadSolution.h"
#include "BaseManager.h"

class LoadManager : public BaseManager {
public:
    LoadManager();

    void accept(ManagerVisitor &) override;
    std::shared_ptr<SceneObject> loadModel(const std::string &);

private:
    std::shared_ptr<LoadSolution> loader;
};

#endif // LOADMANAGER_H
