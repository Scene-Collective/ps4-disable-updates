//#define DEBUG_SOCKET
#define DEBUG_IP "192.168.2.2"
#define DEBUG_PORT 9023

#include "ps4.h"

int _main(struct thread *td) {
  UNUSED(td);

  initKernel();
  initLibc();

#ifdef DEBUG_SOCKET
  initNetwork();
  DEBUG_SOCK = SckConnect(DEBUG_IP, DEBUG_PORT);
#endif

  jailbreak();

  initSysUtil();

  unlink("/update/PS4UPDATE.PUP.net.temp");
  rmdir("/update/PS4UPDATE.PUP.net.temp");
  mkdir("/update/PS4UPDATE.PUP.net.temp", 777);

  unlink("/update/PS4UPDATE.PUP");
  rmdir("/update/PS4UPDATE.PUP");
  mkdir("/update/PS4UPDATE.PUP", 777);

  printf_notification("Disabled updates!");

#ifdef DEBUG_SOCKET
  printf_socket("\nClosing socket...\n\n");
  SckClose(DEBUG_SOCK);
#endif

  return 0;
}
