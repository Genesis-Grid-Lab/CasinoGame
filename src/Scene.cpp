#include "Scene.h"
#include "Object.h"

void Scene::Draw(){
    for(auto& object : Objects){
        object->Draw();
    }
}

Ref<Scene> Scene::Update(){
    for(auto& object : Objects){
        object->Update();
    }
    return nullptr;
}

void Scene::AddObject(Ref<Object> object){
    Objects.emplace_back(object);
}
