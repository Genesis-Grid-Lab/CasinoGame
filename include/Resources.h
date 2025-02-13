#pragma once

#include "Scene.h"
#include "Object.h"
#include <memory>

template<class T>
class ResourcesManager {
public:
    ResourcesManager(const ResourcesManager& other) = delete;
    ResourcesManager(ResourcesManager&& other) = delete;
    ResourcesManager& operator=(const ResourcesManager& other) = delete;

    ~ResourcesManager() {}

    // Load a resource
    static std::shared_ptr<T> load(const std::string &filename){
        auto &resourcesManager = instance();
        std::shared_ptr<T> resource;

        //Check if the rouces is already loaded
        auto resIter = resourcesManager.resources.find(filename);
        if(resIter != resourcesManager.resources.end()){
            resource = resIter->second.lock();
        }

        if(!resource){
            //Load the resource from disk
            resource = std::make_shared<T>(filename);
            resourcesManager.resources[filename] = resource;
        }

        return resource;
    }

    // Load a resource
    static std::shared_ptr<T> loadTexture(const std::string &filename){
        auto &resourcesManager = instance();
        std::shared_ptr<T> resource;

        //Check if the rouces is already loaded
        auto resIter = resourcesManager.resources.find(filename);
        if(resIter != resourcesManager.resources.end()){
            resource = resIter->second.lock();
        }

        if(!resource){
            //Load the resource from disk
            resource = std::make_shared<T>(LoadTexture(filename.c_str()));
            resourcesManager.resources[filename] = resource;
        }

        return resource;
    }

  //load a scene
  static Ref<T> loadScene(const std::string &name){
    auto &resourcesManager = instance();
    Ref<T> resource;

    // Check if the resources already loaded
    auto resIter = resourcesManager.SceneResources.find(name);
    if(resIter != resourcesManager.SceneResources.end()){
      printf("Debug load scene\n"); 
      resource = std::static_pointer_cast<T>(resIter->second);
    }

    if(!resource){
      printf("Debug create scene\n");
      // make a scene
      resource = CreateRef<T>();
      resourcesManager.SceneResources[name] = std::static_pointer_cast<Scene>(resource);
    }
    return resource;
  }

    //Gets the global resources manager instance
    static auto& instance(){
        static ResourcesManager resourceManager;
        return resourceManager;
    }
private:

    ResourcesManager(){}
    std::list<Object *> Objects;
    std::list<Scene *> Scenes;

    //The map of resources that have been loaded
    std::unordered_map<std::string, std::weak_ptr<T>> resources;
  std::map<std::string, Ref<Scene>> SceneResources;
};

// Predefined resource managers.

// Manages loading of textures.
typedef ResourcesManager<Texture> TextureManager;

// Manages loading of sounds.
typedef ResourcesManager<Sound> SoundManager;

// Manages loading of music.
typedef ResourcesManager<Music> MusicManager;

// Manages loading of Scene
typedef ResourcesManager<Scene> SceneManager;
