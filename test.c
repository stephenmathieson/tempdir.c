
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "fs/fs.h"
#include "tempdir.h"

#define CLEAR_ENV_VARS                            \
  assert(0 == putenv("TMPDIR=/not/real"));        \
  assert(0 == putenv("TEMP=/not/real"));          \
  assert(0 == putenv("TMP=/not/real"));           \
  assert(0 == putenv("Wimp$ScrapDir=/not/real")); \

int
main(void) {
  // test TMPDIR
  {
    CLEAR_ENV_VARS;
    assert(0 == putenv("TMPDIR=./"));
    char *dir = gettempdir();
    assert(dir && 0 == strcmp("./", dir));
    assert(0 == fs_exists(dir));
    free(dir);
  }

  // test TEMP
  {
    CLEAR_ENV_VARS;
    assert(0 == putenv("TEMP=./"));
    char *dir = gettempdir();
    assert(dir && 0 == strcmp("./", dir));
    assert(0 == fs_exists(dir));
    free(dir);
  }

  // test TMP
  {
    CLEAR_ENV_VARS;
    assert(0 == putenv("TMP=./"));
    char *dir = gettempdir();
    assert(dir && 0 == strcmp("./", dir));
    assert(0 == fs_exists(dir));
    free(dir);
  }

  // test Wimp$ScrapDir (RiscOS)
  {
    CLEAR_ENV_VARS;
    assert(0 == putenv("Wimp$ScrapDir=./"));
    char *dir = gettempdir();
    assert(dir && 0 == strcmp("./", dir));
    assert(0 == fs_exists(dir));
    free(dir);
  }

  // test platform checks / cwd
  {
    CLEAR_ENV_VARS;
    char *dir = gettempdir();
    assert(dir);
    assert(0 == fs_exists(dir));
    free(dir);
  }

  return 0;
}
