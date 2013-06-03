#include "Singleton.h"
#include <map>
#include <string>

class CIniFileA;


class ResourceManager : public Singleton<ResourceManager>
{
    SINGLETON_DECLARATION_CLASSE_NO_CONSTRUCTOR(ResourceManager);
protected:
    ResourceManager(){}
    ~ResourceManager();

public:
#define GetMenuItemPath(section,key,...) ResourceManager::GetInstance()->GetKeyValue("MenuResources.ini",section,key,##__VA_ARGS__).c_str()

    
    std::string GetKeyValue(char* iniFile, char* section, char* key, const std::string& defaultValue = "");

private:
    std::map<std::string,CIniFileA*> mIniFiles;
};
