#pragma once

#include "Scene.h"
#include "Object.h"
#include <memory>

class ResourcesManager {
public:
    ResourcesManager(const ResourcesManager& other) = delete;
    ResourcesManager(ResourcesManager&& other) = delete;
    ResourcesManager& operator=(const ResourcesManager& other) = delete;

    ~ResourcesManager() {}

    // Load a resource
    // template <typename T>
    // static std::shared_ptr<T> load(const std::string &filename){
    //     auto &resourcesManager = instance();
    //     std::shared_ptr<T> resource;

    //     //Check if the rouces is already loaded
    //     auto resIter = resourcesManager.resources.find(filename);
    //     if(resIter != resourcesManager.resources.end()){
    //         resource = resIter->second.lock();
    //     }

    //     if(!resource){
    //         //Load the resource from disk
    //         resource = std::make_shared<T>(filename);
    //         resourcesManager.resources[filename] = resource;
    //     }

    //     return resource;
    // }

    // Load a resource
    static Texture loadTexture(const std::string &filename){
        Texture resource;

        //Check if the rouces is already loaded
        auto resIter = TextureResources.find(filename);
        if(resIter != TextureResources.end()){
            return resource = TextureResources[filename];
        }

        
            //Load the resource from disk
            resource = LoadTexture(filename.c_str());
            TextureResources[filename] = resource;
	    printf("%i texture\n", (int)TextureResources.size());
        
        return resource;
    }

  //load a scene
  template <typename T>
  static Ref<T> loadScene(const std::string &name){
    auto &resourcesManager = instance();
    Ref<T> resource;

    // Check if the resources already loaded
    auto resIter = SceneResources.find(name);
    if(resIter != SceneResources.end()){
      printf("Debug load scene\n"); 
      resource = std::static_pointer_cast<T>(SceneResources[name]);
    }

    if(!resource){
      printf("Debug create scene\n");
      // make a scene
      resource = CreateRef<T>();
      SceneResources[name] = std::static_pointer_cast<Scene>(resource);
      printf("%i scene\n", (int)SceneResources.size());
    }
    return resource;
  }

  template <typename T>
  static Ref<T> CreateObject(uint64_t id){
    auto &resourcesManager = instance();
    Ref<T> resource;

    // Chech if the resources already loaded
    auto resIter = ObjectResources.find(id);
    if(resIter != ObjectResources.end()){
      printf("Debug load object\n"); 
      resource = std::static_pointer_cast<T>(ObjectResources[id]);
    }

    if(!resource){
      printf("Debug create object\n");
      //
      resource = CreateRef<T>();
      ObjectResources[id] = std::static_pointer_cast<Object>(resource);
      printf("%i object\n", (int)ObjectResources.size());

    }

    return resource;
  }

  static std::map<uint64_t, Ref<Object>>& GetObjects(){
    return ObjectResources;
  }

    //Gets the global resources manager instance
    static auto& instance(){
        static ResourcesManager resourceManager;
        return resourceManager;
    }

public:
  static std::map<uint64_t, Ref<Object>> ObjectResources;
  static std::map<std::string, Ref<Scene>> SceneResources;
  static std::map<std::string, Texture> TextureResources;
private:

  ResourcesManager(){}
  std::list<Object *> Objects;
  std::list<Scene *> Scenes;

  //The map of resources that have been loaded
  // std::unordered_map<std::string, std::weak_ptr<T>> resources;
  // std::unordered_map<std::string, Ref<Scene>> SceneResources;
  // std::unordered_map<uint64_t, Ref<Object>> ObjectResources;
};

//Instantiate static variables
// std::map<uint64_t, Ref<Object>> ResourcesManager<Object>::ObjectTest;

// Predefined resource managers.

// Manages loading of textures.
typedef ResourcesManager TextureManager;

// // Manages loading of sounds.
// typedef ResourcesManager<Sound> SoundManager;

// // Manages loading of music.
// typedef ResourcesManager<Music> MusicManager;

// // Manages loading of Scene
// typedef ResourcesManager<Scene> SceneManager;

// // Manages loading of Objects
// typedef ResourcesManager<Object> ObjectManager;
