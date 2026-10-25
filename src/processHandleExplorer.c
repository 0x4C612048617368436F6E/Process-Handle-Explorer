#include"../header/processHandleExplorer.h"
HANDLE returnProcessHandle(DWORD pID) { 
	HANDLE handleToProcess =
      OpenProcess(PROCESS_QUERY_INFORMATION | SYNCHRONIZE, FALSE, pID);
  char tempBuffer[1024];
  int charCopied = 0;
    if (!handleToProcess) {
          simpleLogger("That is not nice");
    exit(EXIT_FAILURE);

  }
  simpleLogger("That is nice");
  // lets see if we actually have the right process ID
  DWORD processID = GetProcessId(handleToProcess);
  if (processID == 0) {
    simpleLogger("Incorrect process");
    exit(EXIT_FAILURE);
  }
  if (processID == pID) {
    charCopied = snprintf(tempBuffer, sizeof(tempBuffer),
                          "Process ID %d is the same as %d", processID, pID);
    
    if (charCopied > 0 && charCopied < sizeof(tempBuffer)) {
      tempBuffer[charCopied] = '\0';
      simpleLogger((const char*)tempBuffer);
    } else {
      tempBuffer[(strlen(tempBuffer) + 1)] = '\0';
      simpleLogger(tempBuffer);
    }
  }
  return handleToProcess;
}