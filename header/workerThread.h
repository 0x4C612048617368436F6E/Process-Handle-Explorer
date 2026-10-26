#include"common.h"
HANDLE createThreadWrapper(LPVOID);
typedef struct {
  HANDLE _handleForProcess;
} argumentProperties;
typedef void(WINAPI* waitForProcessToSignal)(LPVOID);
void waitForProcessToSignalImplementation(LPVOID);