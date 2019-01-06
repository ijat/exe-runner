This project is created to run program from another directory suffix, just like shortcut. For example this folder structure:
```
+--+ exe_runner-bin
|  +-- exe_runner
|  +-- a.dll
|  +-- b.dll
|  +-- c.dll
|  +-- ...dll
|
+-- Help Files
|
+-- Documents
|
+-- exe_runner
```

The idea is that you don't have to navigate to `exe_runner-bin` folder and open `exe_runner`. Just click `exe_runner` in root folder it will run `exe_runner-bin\exe_runner` directly.

You can change the name of the binary to suit your application. Example if your software binary name is `haha.exe`, then just rename `exe_runner` to `haha.exe`, and make sure the folder structure is valid, means there is `haha.exe-bin` and `haha.exe-bin\haha.exe` binary.

## Compilation from source
```
cmake .
make
```


