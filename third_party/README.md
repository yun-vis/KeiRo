# ubuntu 18.04 LTS

## intstall libsbml

```
$ sudo apt-get update
$ sudo apt install libsbml5
```

## intstall libSBGN2

```
$ git clone https://github.com/fbergmann/libSBGN2.git
$ cd libSBGN2
$ mkdir build
$ cd build
$ cmake ../ -DLIBSBML_LIBRARY=/usr/lib/ -DLIBSBML_INCLUDE_DIR=/usr/include/ -DEXTRA_LIBS=/usr/lib/ -DCMAKE_INSTALL_PREFIX=../install/
$ make
$ make install
```

# macOS 10.12

## intstall libsbml

```
$ sudo port install libsbml +layout +render
```

## intstall libSBGN2 
# NEW
- in CMakeList.txt <br/>
  add "/opt/local/lib" to the library path <br/>
  add "/opt/local/include" to the include path

- temporarily remove libsbml-static-bk.a under /opt/local/lib to enforce sbgn package to link to the dynamic version of libsbml library

```
$ git clone https://github.com/fbergmann/libSBGN2.git
$ cd libSBGN2
$ mkdir build
$ cd build
$ cmake ../ -DEXTRA_LIBS=/opt/local/lib/ -DCMAKE_INSTALL_PREFIX=/opt/local/
$ make
$ make install
```

# OLD

```
$ git clone https://github.com/fbergmann/libSBGN2.git
$ cd libSBGN2
$ mkdir build
$ cd build
$ cmake ../ -DLIBSBML_LIBRARY=/opt/local/lib/ -DLIBSBML_INCLUDE_DIR=/opt/local/include/ -DEXTRA_LIBS=/opt/local/lib/ -DCMAKE_INSTALL_PREFIX=install/
$ make
$ make install
```
ERROR: dylib is not generated successfully on macOS

## cmake setting 
https://stackoverflow.com/questions/36659004/eigen-matrix-multiplication-speed

# windows
