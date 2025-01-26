#include "Composite.h"
#include "../SceneVisitor/SceneVisitor.h"

void Composite::transform(const TransformMatrix &tm) {
    deleteExpired();
    calculateCenter();
    for (auto elem : objects) {
        auto shared = elem.lock();
        auto tmp = shared->getCenter();
        shared->setCenter(center);
        shared->transform(tm);
        tmp.move(tm);
        shared->setCenter(tmp);
    }
}

void Composite::accept(SceneVisitor &visitor) { visitor.visit(*this); }

bool Composite::add(std::shared_ptr<SceneObject> obj) {
    deleteExpired();
    std::weak_ptr<SceneObject> tmp = obj;
    auto answer = &(*obj) != this && obj != nullptr;
    if (answer) {
        for (auto it = objects.begin(); answer && it != objects.end(); ++it) {
            answer = it->lock() != obj;
        }
        if (answer) {
            objects.emplace_back(obj);
        }
    }
    calculateCenter();
    return answer;
}

bool Composite::remove(std::shared_ptr<SceneObject> obj) {
    deleteExpired();
    auto answer = false;
    for (auto i = 0; i < objects.size(); ++i) {
        if (answer) {
            objects[i - 1] = objects[i];
        } else {
            answer = objects[i].lock() == obj;
        }
    }
    if (answer) {
        objects.pop_back();
    }
    calculateCenter();
    return answer;
}

bool Composite::isComposite() const { return true; }

std::shared_ptr<SceneObject> Composite::clone() const {
    return std::shared_ptr<Composite>();
}

void Composite::deleteExpired() {
    std::vector<std::weak_ptr<SceneObject>> notExpired;
    for (auto elem : objects) {
        if (!(elem.expired())) {
            notExpired.push_back(elem);
        }
    }
    objects = notExpired;
}

void Composite::calculateCenter() {
    auto cnt = objects.size();
    if (cnt == 0) {
        return;
    }
    Dot tmp;
    for (auto elem : objects) {
        auto ptr = elem.lock();
        tmp += ptr->getCenter();
    }
    tmp.x /= cnt;
    tmp.y /= cnt;
    tmp.z /= cnt;
    center = tmp;
}
