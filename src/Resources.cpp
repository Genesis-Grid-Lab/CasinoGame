#include "Resources.h"

std::map<uint64_t, Ref<Object>> ResourcesManager::ObjectResources;
std::map<std::string, Ref<Scene>> ResourcesManager::SceneResources;
std::map<std::string, Texture> ResourcesManager::TextureResources;