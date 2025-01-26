#ifndef __LOAD_SOLUTION_H__
#define __LOAD_SOLUTION_H__

#include <map>
#include <string>

#include "SceneObjectCreator.h"

class LoadSolution {
public:
    std::shared_ptr<SceneObjectCreator> createCreator(const std::string &);
    bool registration(const std::string &, std::shared_ptr<SceneObjectCreator>);

private:
    std::map<std::string, std::shared_ptr<SceneObjectCreator>> creators;
};

#endif // __LOAD_SOLUTION_H__
