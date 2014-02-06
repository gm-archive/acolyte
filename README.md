Attention: Work is taking place on the wiki, the information here is mostly outdated. The build is no longer being maintained as it's undertaking a rewrite.

# Acolyte

Acolyte is an open source alternative runtime and compiler for projects written
in [GameMaker: Studio]. Games are compiled by first converting them into
compliant C++ code and then optionally piping them into a compiler of choice to
produce object files. These object files can then be linked directly with
swappable runtime components which provide systems like graphics, audio and
physics.

This is equivalent to the process undertaken by the proprietary [YoYo Compiler].

[GameMaker: Studio]: http://www.yoyogames.com/studio
[YoYo Compiler]: http://www.youtube.com/watch?v=i3ECuXBc7Ks

## Getting Started

### Build System

Acolyte uses [CMake] as its provider for build system tools. This requires some
initial setup, but offers many advantages over traditional GNU makefiles (such
as the ability to automatically generate IDE project files and compile outside
MinGW on Windows).

1. Download and install CMake from the [CMake downloads page] or from your
   systems package manager (`sudo apt-get install cmake` on Debian,
   `pacman -Sy cmake` on ArchLinux or even `brew install cmake` on OSX using
   [Homebrew]).
2. Open your system terminal and ensure that CMake is on path and that it is at
   least version 1.8. You can use `cmake --version` to test this.
3. Decide which build provider you would like to use for the next step. You can
   either leave this as default (Visual Studio on Windows, Makefiles on
   Linux/OSX) or pick one of `Unix Makefiles`, `Ninja`, `Xcode` or
   `CodeBlocks - Unix Makefiles`.
   See `cmake --help` for more information and additional generators.
4. Navigate to the top-level directory of this repository in your terminal. Run
   `cmake .` _or_ `cmake . -G"Unix Makefiles"`, optionally replacing
   `Unix Makefiles` with another generator picked above.

You can now use the build system of your choice to build Acolyte. If you chose
to generate makefiles this means that you can use `make` to build. If you used
Visual Studio (default on Windows) or Xcode, you can open the project file
generated in the top level directory and use the regular build system for that
particular IDE. Binaries can generally be found in the `build/` directory.

If you need to change which generator you would like to use, you should delete
`CMakeCache.txt` from the top-level directory and run one of the commands above
with your new desired generator. If you plan to swap generators frequently you
may decide to build outside the source tree using a command such as
`cmake ../path/to/source`.

[CMake]: http://cmake.org
[CMake downloads page]: http://cmake.org/cmake/resources/software.html
[Homebrew]: http://brew.sh
[as explained here]: http://www.cmake.org/Wiki/CMake_FAQ#CMake_does_not_generate_a_.22make_distclean.22_target._Why.3F

### Layout

Acolyte is split into seperate packages. These can be found in the `packages/`
directory of the source tree. Each package is compiled into a different static
library or binary. See `packages/README.md` for more information.

## Testing

[![Build Status](https://travis-ci.org/acolyte-sf/acolyte.png?branch=master)](https://travis-ci.org/acolytesf/acolyte)

### Unit Tests

This is under construction.

### Bug Reports

Use the [GitHub issue tracker] to file bug reports.

[GitHub issue tracker]: https://github.com/AcolyteSF/acolyte/issues

## Contributing

### IRC

Our IRC channel is `#acolyte` on `irc.freenode.net`.

### Style Guidelines

Style standards are adopted from the [Google C++ Style Guide]. Use common sense
when editing source files to make sure that formatting is consistent. Avoid
using pointers directly, don't use exceptions, allocate on the stack when
possible and be aware that templates or verbose code are preferred over using
preprocessor macros.

[Google C++ Style Guide]: http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml

### Pull Requests

Pull requests are accepted if they meet quality guidelines. To find out where
you can help out, you should first express interest on IRC.

## License

Acolyte is licensed under a BSD3-style license. A summary of the license is as
follows;

* Don't remove the license text from the source code.
* Include the license text when distributing binaries of Acolyte.
* Don't use Acolyte Strike Force or the names of any of it's members when
  advertising your products.

See `LICENSE` for more information.

Third party libraries and dependencies are licensed independently.

## Troubleshooting & Links

* [GM:S Reference](http://docs.yoyogames.com)
* [C/C++ Reference](http://en.cppreference.com/w/)
* [CMake Wiki](http://www.cmake.org/Wiki/CMake)
* [OpenGL Wiki](http://www.opengl.org/wiki/Main_Page)

You may also be interested in [ENIGMA].

[ENIGMA]: http://enigma-dev.org
