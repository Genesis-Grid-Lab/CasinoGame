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
    template <typename T>
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
    static Texture loadTexture(const std::string &filename){
        Texture resource;

        //Check if the rouces is already loaded
        auto resIter = TextureTest.find(filename);
        if(resIter != TextureTest.end()){
            return resource = TextureTest[filename];
        }

        
            //Load the resource from disk
            resource = LoadTexture(filename.c_str());
            TextureTest[filename] = resource;
	    printf("%i texture\n", (int)TextureTest.size());
        
        return resource;
    }

  //load a scene
  template <typename T>
  static Ref<T> loadScene(const std::string &name){
    auto &resourcesManager = instance();
    Ref<T> resource;

    // Check if the resources already loaded
    auto resIter = SceneTest.find(name);
    if(resIter != SceneTest.end()){
      printf("Debug load scene\n"); 
      resource = std::static_pointer_cast<T>(SceneTest[name]);
    }

    if(!resource){
      printf("Debug create scene\n");
      // make a scene
      resource = CreateRef<T>();
      SceneTest[name] = std::static_pointer_cast<Scene>(resource);
      printf("%i scene\n", (int)SceneTest.size());
    }
    return resource;
  }

  template <typename T>
  static Ref<T> CreateObject(uint64_t id){
    auto &resourcesManager = instance();
    Ref<T> resource;

    // Chech if the resources already loaded
    auto resIter = ObjectTest.find(id);
    if(resIter != ObjectTest.end()){
      printf("Debug load object\n"); 
      resource = std::static_pointer_cast<T>(ObjectTest[id]);
    }

    if(!resource){
      printf("Debug create object\n");
      //
      resource = CreateRef<T>();
      ObjectTest[id] = std::static_pointer_cast<Object>(resource);
      printf("%i object\n", (int)ObjectTest.size());

    }

    return resource;
  }

  static std::map<uint64_t, Ref<Object>>& GetObjects(){
    return ObjectTest;
  }

    //Gets the global resources manager instance
    static auto& instance(){
        static ResourcesManager resourceManager;
        return resourceManager;
    }

public:
  static std::map<uint64_t, Ref<Object>> ObjectTest;
  static std::map<std::string, Ref<Scene>> SceneTest;
  static std::map<std::string, Texture> TextureTest;
private:

  ResourcesManager(){}
  std::list<Object *> Objects;
  std::list<Scene *> Scenes;

  //The map of resources that have been loaded
  // std::unordered_map<std::string, std::weak_ptr<T>> resources;
  std::unordered_map<std::string, Ref<Scene>> SceneResources;
  std::unordered_map<uint64_t, Ref<Object>> ObjectResources;
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
