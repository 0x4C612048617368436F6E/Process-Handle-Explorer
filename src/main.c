#include"../header/common.h"
#include"../header/processHandleExplorer.h"
#include"../header/workerThread.h"
int __cdecl main() { 
	simpleLogger("Starting...");
  HANDLE handleForProcess = returnProcessHandle(24140);
  //create Thread
  argumentProperties arguments = {._handleForProcess = handleForProcess};
  HANDLE threadHandle = createThreadWrapper((LPVOID)&arguments);

  WaitForSingleObject(threadHandle,INFINITE);
  //close all handles
  CloseHandle(handleForProcess);
  CloseHandle(threadHandle);
  return 0;
}