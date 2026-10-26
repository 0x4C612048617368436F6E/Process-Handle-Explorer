#include"../header/workerThread.h"
HANDLE createThreadWrapper(LPVOID inputForThread) {
  simpleLogger("Entering Thread creation");
  waitForProcessToSignal pointerToFunction =
      &waitForProcessToSignalImplementation;
  DWORD threadID = 0;

  HANDLE threadObject = CreateThread(NULL, 0x00, pointerToFunction,
                                     inputForThread, 0x00, &threadID);
  if (!threadObject) {
    simpleLogger("Unable to create thread object");
    exit(EXIT_FAILURE);
  }
  return threadObject;
}

void waitForProcessToSignalImplementation(LPVOID handleForProcess) {
  simpleLogger("Starting Worker thread");
  DWORD singledObject =
      WaitForSingleObject(((argumentProperties*)handleForProcess)->_handleForProcess, INFINITE);
  if (singledObject = WAIT_OBJECT_0) {
    simpleLogger("Process has signled");
  }
  simpleLogger("Ending Worker thread");

}