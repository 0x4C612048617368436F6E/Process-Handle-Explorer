#include"../header/locateHWNDviaTitle.h"
void locateHWNDViaTitle() {
  HWND windowHandle = FindWindowA("Notepad",NULL);
  if (!windowHandle) {
    simpleLogger("Can not find window");
    exit(EXIT_FAILURE);
  }
  //Hide Window
  BOOL ret = ShowWindow(windowHandle, SW_MINIMIZE);
  if (ret) {
      //non-Zero means window was previouly visible
    simpleLogger("Window was previously visible");
  } else {
      //zero meaning window was previously hidden
    simpleLogger("Window was previously hidden");
  }
}