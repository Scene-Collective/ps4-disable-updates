#include "ps4.h"

int _main(struct thread *td) {
  UNUSED(td);

  initKernel();
  initLibc();
  jailbreak();
  initSysUtil();

  unlink("/update/PS4UPDATE.PUP.net.temp");
  rmdir("/update/PS4UPDATE.PUP.net.temp");
  mkdir("/update/PS4UPDATE.PUP.net.temp", 777);

  unlink("/update/PS4UPDATE.PUP");
  rmdir("/update/PS4UPDATE.PUP");
  mkdir("/update/PS4UPDATE.PUP", 777);

  printf_notification("Disabled updates!");

  return 0;
}
