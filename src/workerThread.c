#include"../header/workerThread.h"
HANDLE createThreadWrapper() {
  HANDLE threadObject = CreateThread(NULL,0x00,);
  if (!threadObject) {
    simpleLogger("Unable to create thread object");
    exit(EXIT_FAILURE);
  }
}


void waitForProcessToSignalImplementation(HANDLE handleForProcess) {
  DWORD singledObject = WaitForSingleObject(handleForProcess, INFINITE);
  if (singledObject = WAIT_OBJECT_0) {
    simpleLogger("Process has signled");
  }
}