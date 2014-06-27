
# tempdir.c

  An implementation of Python's [`tempfile.tempdir`](https://docs.python.org/2/library/tempfile.html#tempfile.tempdir) algorithm in C.

## Installation

```sh
$ clib install stephenmathieson/tempdir.c
```

## API

```c
#include "tempdir/tempdir.h"

char *tmp = gettempdir();
assert(tmp);
free(tmp);
```

## License

  MIT
