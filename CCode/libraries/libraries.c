//
//  libraries.c
//  CCode
//
//  Created by abedalkareem omreyh on 09/05/2022.
//

#include "libraries.h"
#include <dlfcn.h>
#include <stdlib.h>

// a library is a collection (group) of header files and implementation files, exposed for use by other programs.
// interface expressed in a header file.
// implementation expressed in a .c file.

// a library consists of one or more object files, which consist of object code.

// linking:
// when a c prgoram is compiled, the compiler generates object code (.o or .obj).
// after generating the object code, the compiler also invokes the linker.
// linking is the processes of collecting and combining multiple object files in order to create a single executable file.
// one of the main tasks for linker is to make the code of library functions (eg printf) available to your program.
// a linker can accomplish this task in two ways.
// by copying the code of library function to your object code.
// by making some arrangementsn so that the complete code of library function is not copied, but made available at run-time.
// static linking is the result of the linked making copy of all used library functions to the executable file.
// dynamic linking does not require the code to be comied, it is done by just placing the name of the library in the binary file.
// linking happens when the program is run, when both the binary file and the library are in memory.

// Static linking
// when you link your application to another library at compile time, the library code is part of your application.
// the primary advamtage of static linking is the speed:
// - there will be no symbol (a program entity) resoltion at runtime.
// - every piece of the library is part of the binary image (executable).
// once everything is bundled into your application, you don't have to worry that the client will have the right library (and version)
// available on their system.
// static linking creates larger binary files that utilize more disk space and main memory.
// once the library is linked and the program is created, you have no way of changing any of the library code without rebuilding the whole
// program.

// Dynamic linking
// dynamic linking defers much of the linking process until a program starts running
// perform the linking process "on the fly" as programs are executed in the system.
//
// libraries are loaded into memory by programs when they start.
//
// during compilation of the library, the machine code is stored on  your machine
// when you recompile a program that uses this library, only the new code in the program is compiled.
// does not recomile the library into the executablefile like in static linking.
//
// the main reason for using dynamic libraries is to free your software from the need to recompile with each new release of
// library.
//
// dynamic linking is the more modren approach, and has the advantage of much smaller executable size.
// dynamic linking trades off more efficient use of the disk and a quicker linking phase for a small runtime penalty.
// dynamic linking helps overall performance in two ways.
// it safes on disk and virtual memory.
// libraries are only mapped in to the process when needed.
// all executables dynnamiclly linked to a particular library share a single copy of the library at runtime.
// ensures that libraries mapped into memory are shared by all processes using them.
// provides better I/O and swap space utilization and is sparing of physical memory, improving overall system throughput.
//
// Library types
// there are two C library types which can be created.
// static libraries:
// - uses static linking (compile-time, becomes part of the application).
// - each process gets its own copy of the code and data.
// - known as an archive.
//
// shared object libraries:
// - dynamically linked at run time
//   - dshared objects are not included into the executable component but are tied to the execution.
// - code shared, data is specific to each process.
//
// there is also the concept of dynamically loaded/unloaded shared object library that is linked during execution using the dynamic
// linking loader system functions.

// Library conventions:
// dynamic libraries are called lib something .so
// have a filename of the form libname.so (version numbers may be appended to the name).
// - the library of thread routines is called libthread.so
//
// static libraries are called lib something.a
// - has a filename of the form libname.a
// - ".a" library is conceptually the same as the windows ".lib" libraries
//
// static libraries have the advantage of speed.
// all the code to execute the file is in one executable file, with little to virtually zero compatibility issues.
//
// static libraries are larger in size because the file has to br recompiled every time when adding new code to the executable.
//
// for shared objects, only one copy of the shared library is kept in memory
// making it much faster to comile programs and significntlyreducing the size of the executable program.
//
// shared objects have a slower execution time compared to static libraries.
//
// shared objects also may have comptibility issues if a library is changed without recompiling the library into memory.
//
//
// a static library is an archive
// a bunch of object files wrapped up into a single file.
// created and updated by the ar (for archive) untility.
// a program that takes files and stores them in a bigger file without regard to compression.
//
// standard convention is to name static libraries
// lib<something>.a
// name begin with lib and end with a .a extension.
// libc.a file contains the standard c library.
// libm.a containes mathematics functions.
//
// once you have an archive, you can store it in a library directory.
// /usr/local/lib (system directory)
// /my_lib (your own directory)
//
// Creating a Static library
// $ gcc -c main.c -o lib_mylib.o // create the .o file.
// $ ar rcs lib_mylib.a lib_mylib.o // or ar -cvq lib_mylib.a lib_mylib.o // we can name the library by using -l (-lsomething).
// $ ar -t lib_mylib.a // (-t test, will show the files inside the libraries)
// rcs: https://stackoverflow.com/questions/29714300/what-does-the-rcs-option-in-ar-do
//
// $ gcc -I ../temp/ -c main.c -o main.o
// $ gcc -o main main.o ../temp/lib_mylib.a // we can use -Lpathname for "../temp/lib_mylib.a"
// $ gcc ./main

// ar -cvq lib_mylib.a lib_mylib.o
//-c Whenever an archive is created, an informational message to that effect is written to standard error.
//If the -c option is specified, ar creates the archive silently.
//-v Provide verbose output.
//-q Quickly append the specified files to the archive. If the archive does not exist a new archive file is created.

// ar rcs lib_mylib.a lib_mylib.o
//Reading the manual for ar helps but I will explain it in more detail.
//ar -rcs is the most likely command you would use when using a Makefile to compile a library.
//r means that if the library already exists, replace the old files within the library with your new files.
//c means create the library if it did not exist.
//s can be seen to mean 'sort' (create a sorted index of) the library,
//so that it will be indexed and faster to access the functions in the library.
//Therefore, rcs can be seen to mean replace, create, sort.
//
//
//
// Creating a shared object (dynamic library)
// every program linked against this library shares the same one copy
// contrast to static linking, in which everyone is (wastefully) given their own copy of the
// contents of the library.
//
// a dynamically linked library (shared object) is created by the link editor
// the name of the link editor is the command id.
//
// standard convention is to name dynamic libraries
// lib<something>.so (shared object)
// names begin with lib and end with a .so extension.
// similar to windows extension .dll and mac extension .dylib
//
// you can use the ldd command on linux to list all of the shared objects for a given binary/executable.
// ldd name-of-executable.
//
// to create a shared object (on windows)
// gcc -g -fPIC main.c -shared -o lib_mylib.dll
// gcc -I ../myDynamicLibrary -c main.c -o main.o
// gcc -o main.exe main.o -L../myDynamicLibrary -l lib_mylib (linking)
// export PATH=/myDynamicLibraryPATH:$PATH.  // adding the library to the paths.
// ./main.exe
//
// on mac
// gcc -g -fPIC main.c -shared -o libmylib.so
// gcc -I ../myDynamicLibrary -c main.c -o main.o
// gcc -o main main.o -L../myDynamicLibrary -l mylib (linking)
// export LD_LIBRARY_PATH=/myDynamicLibraryPATH:$LD_LIBRARY_PATH.  // adding the library to the paths.
// ./main
//
//
//
// Dynamic loading:
// loading of a library is of two types:
// static loading.
// dynamic loading.
//
// whenever we run our executable, the loader willl try to resolve against all the symbols at program start up.
// loading will stoore every required library into memory, along with our executable itself.
//
// what if we didn't want to link libraries at compile time (via copy or  sharing) and load symbols at program start-up time.
// instead, load them ourselves as needed during runtime.
//
// instead of a predefined dependency on a library, we could makee its presence optional and adjust our program's functionality
// accordingly
// loading oof a library on demand (dynamic lloading), not at start up
// the programmer deterines when/if the library is loaded.
//
// dynamic loading is a mechanism by which a computer program can, at run time, load a library (or other binary) into memory
// can retrieve the addresses of functions and variables contained in the library
// can execute those function or access those variables
// can unload the library from memory
//
// it is one of the 3 mechanisms by which a computer program can use some other software
// the other two are static linking and dynamic linking (both load at program start up)
//
// unlike static linking and dynamic linking, dynamic loading allows a computer program to start up in the absence of these libraries.
// can discover available libraries and to potebtially gain additional functionality.
//
// the main difference of dynamic linking to a shared object is that the libraries are not automatically loaded at program start-up.
//
// they are particularly useful for implementing plugins or modules.
// they premit waiting to load the plugin until it is needed
// the pluggable authentication  modules (PAM) system uses DL libraries to permit administrators to configure and reconfigure authentication.
// (DL) libraries are also useful for implementing interpreters that wish to occasionally compile their code into machine code
// and use the compiled version for efficiency purposes all without stopping.
//  the apache webserver's *.dso "dynamic shard object" plugin files are libraries which are loaded at runtime with dynamic loading.
// also used in implementing computer programs where multiple diffferent libraries may supply the requisite functioality
// where the user has the option to select which library or libraries to provide.
//
// dynamic loading API (dlopen)
// there is an API for opening a library  looking up symbols, handling errors, and closing the library
// need to include the header file <dlfcn.h>
//
// the first function we will discuss is the dlopen() function
// opens a library and prepares it for use.
// if libraries depend on each other (e.g X depends on Y) then you need to load the dependees first (load Y first and then X).
//
// void *dlopen(const char *filename, int flag);
// if filename begins with "/" (i.e it's an absolute path), dlopen() will just try to use it otherwise it  will search for the library
// in the LD_LIBRARY_PATH environemnt variable and other directories.
// the value of flag must be either RTLD_LAZY or RTLD_NOW
// RTLD_LAZY means to resolve undefined symbols as code from the dynamic library is executed.
// RTLD_NOW means to resolve all undefined symbols before dlopen() returns and fail if cannot be done (used if debugging).
//
// the return value of dlopen() is a "handle" that should is used by the other DL library routines
// will return NULL if the attempt to load does not succeed
// if the same library is loaded more than once with dlopen(), the same file handle is  returned.
//
// dynamic loading API (dlerror and dlsym)
// errors can be reported by calling dlerror()
// returns a string describing the error from the last call to dlopen(), dlsym(). or dlclose()
//
// the main routine for using a DL library is the dlsym() function
// looks up the value of a symbol in a given (opend) library
// no point in loading a DL library if you cannot use it.
//
// void *dlsym(void *handle, char *symbol);
//
// the handle is the value returned from dlopen, and symbol is a NIL-terminated string.
// do not store the result of dlsym() into a void* pointer
// you will have to cast it each time you use it (and you'll give less information to other people trying to maintain the program).
//
//
// convention is to call dlerror() first
// to clear any error condition that may have existed
// then to call dlsym() to request a symbol
// then call dlerror() again to see if an error occurred
//  dlerror(); /* clear error code */
//  s = (actual_type) dlsym(handle, symbol_being_searched_for);
//  if ((err = dlerror()) != NULL) {
//      // handle error the symbol wasn't found
//  } else {
//      // symbol found, it's value is in s
//  }
//
//
// dynamic loading API (dlclose())
// the coonverse of dlopen() is dlclose()
// closes a DL library
//
// the dl library mmaintains link counts for dynamic file handles
// a dynamic library is not acutually deallocated until dlclose has been called on it.
// nedd to call as many times as dlopen has succeeded on it.
//
// it is not a problem for the same program to load the same library multiple times.

void trydl(void) {
    void *handle = NULL;
    double (*cosine)(double) = NULL;
    char *error = NULL;
    
    handle = dlopen("libm.so", RTLD_LAZY);
    
    if (!handle) {
        fputs(dlerror(), stderr);
        exit(1);
    }
    
    dlerror();
    
    cosine = dlsym(handle, "cos");
    
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    
    printf("%f\n", (*cosine)(2.0));
    
    dlclose(handle);
}
