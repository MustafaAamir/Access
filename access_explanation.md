# ACCESS is a sys call that determines whether a file can be accessed in 4 modes:
1. r (read)  => R_OK = 0b100
2. w (write) => W_OK = 0b010
3. x (exec)  => X_OK = 0b001
4. f (file)  => F_OK = 0b000

## Clarification: The permissions are actually stored in octal because it groups 3 binary numbers into 1 group.

if an occurence of any of these is found in the mode, mode |= ANY_OK. This value is then passed into the access function defined in the <unistd.h> library as access(file, mode). If the file can be accessed in the specified mode, the access syscall returns 0. Otherwise, it sets the errno variable to -1.
