#include "ResourceManager.h"
#include "Utilities.h"
#include "inifile.h"

SINGLETON_DECLARATION_CPP(ResourceManager);

const std::string ConfigFileLocation = "Config/";

ResourceManager::~ResourceManager()
{
    STL_ITERATE(mIniFiles,it)
    {
        auto file = it->second;
        if(file) delete file;
    }
}

std::string ResourceManager::GetKeyValue( char* iniFile, char* section, char* key, const std::string& defaultValue /*= ""*/ )
{
    std::string keyValue;
    auto it = mIniFiles.find(iniFile);
    CIniFileA* file = nullptr;

    // Check for cached files
    if(it != mIniFiles.end())
    {
        file = it->second;
    }
    else
    {
        file = new CIniFileA();
        if(!file->Load(ConfigFileLocation+iniFile))
        {
            delete file;
            file = nullptr;
        }
        mIniFiles[iniFile] = file;
    }

    // If file doesn't exists or the value can't be found assign default value
    if(!file || !file->GetKeyValue(section,key,keyValue))
    {
        keyValue = defaultValue;
    }

    return keyValue;
}
