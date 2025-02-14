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
	    printf("%i texture\n", (int)resourcesManager.resources.size());
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
      printf("%i scene\n", (int)resourcesManager.SceneResources.size());
    }
    return resource;
  }

  static Ref<T> CreateObject(uint64_t id){
    auto &resourcesManager = instance();
    Ref<Object> resource;

    // Chech if the resources already loaded
    auto resIter = resourcesManager.ObjectResources.find(id);
    if(resIter != resourcesManager.ObjectResources.end()){
      printf("Debug load object\n"); 
      resource = std::static_pointer_cast<T>(resIter->second);
    }

    if(!resource){
      printf("Debug create object\n");
      //
      resource = CreateRef<T>();
      resourcesManager.ObjectResources[id] = std::static_pointer_cast<Object>(resource);
      printf("%i object\n", (int)resourcesManager.ObjectResources.size());
    }

    return std::static_pointer_cast<T>(resource);
  }

  static std::unordered_map<uint64_t, Ref<Object>>& GetObjects(){
    auto &resourcesManager = instance();
    return resourcesManager.ObjectResources;
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
  std::unordered_map<std::string, Ref<Scene>> SceneResources;
  std::unordered_map<uint64_t, Ref<Object>> ObjectResources;
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

// Manages loading of Objects
typedef ResourcesManager<Object> ObjectManager;
