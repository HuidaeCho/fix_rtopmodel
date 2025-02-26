# fix_rtopmodel

This small program fixes [r.topmodel](https://grass.osgeo.org/grass-stable/manuals/r.topmodel.html) input files to work around [a bug in r.topmodel](https://github.com/OSGeo/grass/pull/5218).

## How to compile on Linux

```bash
cc -o fix_rtopmodel fix_rtopmodel.c
```

## How to compile on Windows

1. Install [Visual Studio Community Edition](https://visualstudio.microsoft.com/vs/community/). Select these two components:
   * MSVC v143 - VS 2022 C++ x64/x86 build tools (Latest)
   * Windows 11 SDK (10.0.26100.0)
2. Start Developer Command Prompt for VS 2022
3. Compile
```cmd
cl /Fe:fix_rtopmodel.exe fix_rtopmodel.c
```
