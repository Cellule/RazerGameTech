#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"
#include "ResourceManager.h"

USING_NS_CC;

// uncomment below line, open debug console
 #define USE_WIN32_CONSOLE

// When debugging in Visual studio
// make sure WorkingDirectory is set to : $(OutDir)
// in project property page, Debugging tab

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

#ifdef USE_WIN32_CONSOLE
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
#endif

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setFrameSize(480, 320);

    int ret = CCApplication::sharedApplication()->run();

    ResourceManager::FreeInstance();


#ifdef USE_WIN32_CONSOLE
    FreeConsole();
#endif

    return ret;
}
