

template<typename ClassName>
class Singleton
{
public:
    static ClassName* GetInstance();
    static void FreeInstance();

    /// Checks if the instance exists
    static bool Exists(){return !!mInstance;}
protected:
    Singleton() {}
    ~Singleton() {}

protected:
    static ClassName* mInstance;

    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
};


#define SINGLETON_DECLARATION_CLASSE(Classe) \
private:                                     \
    Classe () {}                              \
    ~ Classe () {}                            \
    Classe ( const Classe& );                 \
    Classe & operator = ( const Classe& );    \
    friend class Singleton< Classe >;         \


#define SINGLETON_DECLARATION_CLASSE_NO_CONSTRUCTOR(Classe) \
private:                                                       \
    Classe( const Classe& );                                  \
    Classe& operator=( const Classe& );                     \
    friend class Singleton< Classe >;                           \


#define SINGLETON_DECLARATION_CPP(Classe)       \
    template<> Classe * Singleton< Classe >::mInstance = 0; \


template<typename ClassName>
void Singleton<ClassName>::FreeInstance()
{
    if(mInstance)
    {
        delete mInstance;
    }
    mInstance = nullptr;
}

template<typename ClassName>
ClassName* Singleton<ClassName>::GetInstance()
{
    if(!mInstance)
    {
        mInstance = new ClassName();
    }
    return mInstance;
}


