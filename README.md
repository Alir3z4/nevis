## Nevis

Nevis is only a simple fast text editor, implemented in Qt/C++.


Currently under development.


### Build
Nevis is built on top of the Qt/C++ toolkit, compile and build the project is
simple like any other project out there, no godzilla will jump out on you ;)

#### Build Nevis on Gnu/Linux

To compile|build Nevis on gnu/linux the main dependency is [Qt][Qt],
Just Qt and nothing else!
To build Nevis, execute at the extracted source directory

##### Compile/Build

```
$ qmake -config release
$ make
```

##### Install

```
$ make install
```
That's it, now if you are a [KDE][kde]|* [DE][de] user you can find
Nevis in Utilities category or just type it out at [Konsole][konsole]|Command-Line ;)

```
$ nevis
```

##### Clean build

```
$ make clean
```

##### Debug mode

Add __-config debug__ to the qmake invocation
```
$ qmake -config debug
```



### License
Nevis is released under GPLv3. Free and OpenSource ;)


[Qt]: http://qt-project.org/
[qmake]: http://en.wikipedia.org/wiki/Qmake
[kde]: http://www.kde.org/
[de]: http://en.wikipedia.org/wiki/Desktop_environment
[konsole]: http://konsole.kde.org/
