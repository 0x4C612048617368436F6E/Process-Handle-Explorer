#include"common.h"
void createThreadWrapper();
typedef struct {
  HANDLE handleForProcess;
} waitForProcessToSignal;
typedef void(WINAPI* waitForProcessToSignal)(LPVoid);
void waitForProcessToSignalImplementation(LPVoid);