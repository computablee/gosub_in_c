## This project will be deleted soon!

Due to GitHub's unfortunate new practice of using repositories to train Microsoft LLMs, I have made the difficult decision to migrate all of my projects to [Codeberg](https://codeberg.org/).

Because of this project's low visibility, I have decided that it is not important enough to keep on GitHub.
**Therefore, I have decided to delete this project at some point during the month of September.**
[This project's new home can be found here.](https://codeberg.org/computablee/gosub_in_c)

# GOSUB in C
GOSUB is a keyword in certain BASIC dialects which allows you to jump to a label, then return from it later on.
This is a convenient way to incorporate a call stack in a language which lacks functions.

I wrote it in C because someone asked if it was possible.

You probably shouldn't actually use this library, if you can even call it that.
Use functions, please.

## Compilation
This library is a header-only library, meaning the only thing you need to do is include it into your program.

## Usage
Here is an example use case of this library.
```c
#include <stdio.h>
#include "gosub.h"

int main()
{
    GOSUB(subroutine_1);
    GOSUB(subroutine_2);
    GOSUB(subroutine_2);

    printf("This should be called last.\n");
    return 0;

subroutine_1:
    printf("This should be called first.\n");
    RETURN;

subroutine_2:
    printf("This should be called twice.\n");
    RETURN;
}
```
This results in the following output:
```
This should be called first.
This should be called twice.
This should be called twice.
This should be called last.
```

## Limitations
To maintain portability across different platforms, no inline assembly is used.
The downside is that the `&&` operator is used from the GNU compiler extensions to get the address that a label references.
Therefore, this library must be used only with a GNU C compiler (or other compilers which support this use-case).

This library creates dummy labels in order to return to the callsite. 
To eliminate label reusage, labels are created based on the current line number.
Therefore, you can only have one `GOSUB` call per line in your source file.

Finally, the stack size is currently fixed at 256.
Compile with `-DGOSUB_STACK_SIZE` to change.
