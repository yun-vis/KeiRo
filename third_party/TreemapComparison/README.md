# ubuntu 18.04 LTS

## command line

```
$ sudo apt update
$ sudo apt install default-jre
$ sudo apt install default-jdk
$ sudo apt install libjama-java*
```

# macOS 10.14

## compile

```
$ cd third_party/TreemapComparison/
$ rm */*/.DS_Store
$ sh compile.sh
```

## command line

```
$ rm */*/.DS_Store
$ cd third_party/TreemapComparison/code/StableTreemap/
$ java -classpath "libraries/opencsv-3.7.jar:libraries/Jama-1.0.3.jar:src" UserControl/Simulator -technique ssv2 -inputfolder tmp/tmpdata/expo/ -baseline true -outputfolder tmp/ -width 1000 -height 1000
```

## user interface

```
$ rm */*/.DS_Store
$ cd third_party/TreemapComparison/code/StableTreemap/
$ java -classpath "libraries/opencsv-3.7.jar:libraries/Jama-1.0.3.jar:src" UserControl/Visualiser/Visualiser -technique ssv2 -inputfolder tmp/tmpdata/expo/ -baseline true -outputfolder tmp/ -width 1000 -height 1000
```

# windows

