#include"../header/common.h"
#include"../header/processHandleExplorer.h"
int __cdecl main() { 
	simpleLogger("Starting...");
  HANDLE handleForProcess = returnProcessHandle(3576);
  return 0;
}