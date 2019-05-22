#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#define MAX_THREADS 3
#define BUF_SIZE 255

typedef struct MyData {
 int val1;
 int val2;
} MYDATA, *PMYDATA;

DWORD WINAPI worker(LPVOID lpParam) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE) {
        return 1;
    }

 PMYDATA pDataArray = (PMYDATA) lpParam;

 TCHAR msgBuf[BUF_SIZE];
 size_t cchStringSize;
 DWORD dwChars;
 StringCchPrintf(msgBuf, BUF_SIZE, TEXT("Parameters = %d, %dn"),
 pDataArray->val1, pDataArray->val2);
 StringCchLength(msgBuf, BUF_SIZE, &cchStringSize);
 WriteConsole(hStdout, msgBuf, (DWORD) cchStringSize, &dwChars, NULL);

 return 0;
}

void errorHandler(LPTSTR lpszFunction) {
 LPVOID lpMsgBuf;
 LPVOID lpDisplayBuf;
 DWORD dw = GetLastError();

 FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER |
    FORMAT_MESSAGE_FROM_SYSTEM |
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    dw,
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPTSTR) &lpMsgBuf,
    0, NULL);

    lpDisplayBuf = (LPVOID) LocalAlloc(LMEM_ZEROINIT,
    (lstrlen((LPCTSTR) lpMsgBuf) + lstrlen((LPCTSTR) lpszFunction) +
40) * sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf,
    LocalSize(lpDisplayBuf) / sizeof(TCHAR),
    TEXT("%s failed with error %d: %s"),
    lpszFunction, dw, lpMsgBuf);
    MessageBox(NULL, (LPCTSTR) lpDisplayBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

int _tmain() {
         PMYDATA pDataArray[MAX_THREADS];
         DWORD dwThreadIdArray[MAX_THREADS];
         HANDLE hThreadArray[MAX_THREADS];
         for (int i = 0; i < MAX_THREADS; ++i) {
               pDataArray[i] = (PMYDATA) HeapAlloc(GetProcessHeap(),
                           HEAP_ZERO_MEMORY, sizeof(MYDATA));
if (pDataArray[i] == 0) {
                           ExitProcess(2);
             }
             pDataArray[i]->val1 = i;
             pDataArray[i]->val2 = i+100;
             hThreadArray[i] = CreateThread(
                  NULL, // default security attributes
                  0, // use default stack size
                  worker, // thread function name
                  pDataArray[i], // argument to thread function
                  0, // use default creation flags
                  &dwThreadIdArray[i]);// returns the thread identifier
             if (hThreadArray[i] == 0) {
                         errorHandler(TEXT("CreateThread"));
                         ExitProcess(3);
             }
 }
         WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);
         for (int i = 0; i < MAX_THREADS; ++i) {
               CloseHandle(hThreadArray[i]);
               if (pDataArray[i] != 0) {
                           HeapFree(GetProcessHeap(), 0, pDataArray[i]);
               }
          }
          return 0;
}
