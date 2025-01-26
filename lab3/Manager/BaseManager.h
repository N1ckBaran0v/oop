#ifndef __BASE_MANAGER_H__
#define __BASE_MANAGER_H__

class ManagerVisitor;

class BaseManager {
public:
    virtual ~BaseManager() = default;

    virtual void accept(ManagerVisitor &) = 0;
};

#endif // __BASE_MANAGER_H__
