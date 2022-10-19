# generate_points_on_circle

Generate evenly spaced points on the perimeter of a given circle

## Requirements
gcc 9.4.0 

More info on [compiler](#compiler)

## How to compile
```console
root@docker-desktop:/# cd /path/to/generate_points_on_circle
root@docker-desktop:/generate_points_on_circle# bash clean_build.sh
```

## How to run
```console
root@docker-desktop:/# cd /path/to/generate_points_on_circle
root@docker-desktop:/generate_points_on_circle# ./build/generate_points_on_circle
```

## clean_build.sh
A trivial shell script that checks and deletes if `build` folder exists.
Calls the cmake and make to build and compile the source code

## CMakeLists.txt
A basic cmake file to specify C++ standard, build type and compile options

## generate_points_on_circle.cpp
The origin of a circle is represented with `std::pair<double, double>`, the `radius` is represented with a `double`, and the number of points is represented with an int. A vector of center points, radii and number of points has been created manually for test purposes.

For cartesian product of elements of created vectors, `generate_points_on_the_circle` function has been called. This function returns a vector of `std::pair<double, double>` that represent the generated points

```cpp
auto const generate_points_on_the_circle{[](auto const &origin, auto const radius, auto const number_of_points) noexcept
```
First generates angles incremented by [std::iota](https://en.cppreference.com/w/cpp/algorithm/iota). So the result is `0.0, 1.0, 2.0 ...`. The values are stored in a vector called `angles`.

Then calculates the angle between adjacent points. Since the points are 'evenly spaced', the step size is the same for all points thus it has been calculated once in the capture clause of lambda. Every angle is multiplied with the step size to get real angle value in radians. 

$$angle\\_step = \dfrac{2\pi}{number\\_of\\_points}$$

$$\forall \\; angle \in angles: \quad angle = angle * angle\\_step$$

After that all of the calculated angles are transformed into corresponding cartesian coordinates by first finding the `sin` and `cos` values and multiplying with the radius of the circle. Finding the `sin` and `cos` values puts these points on the perimeter of the unit circle. Multiplying with the radius moves them on to the perimeter of given circle. Lastly, the final values are calculated by moving this points by the center of the given circle.

$$\forall \\; angle \in angles: \quad x_i = o_x + \cos(angle) * radius$$

$$\quad \quad \quad \quad \quad \quad \quad \quad \quad y_i = o_y + \sin(angle) * radius$$

## Compiler
```console
root@docker-desktop:/generate_points_on_circle$ g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/9/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:hsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-9-Av3uEd/gcc-9-9.4.0/debian/tmp-nvptx/usr,hsa --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```

```console
root@docker-desktop:/generate_points_on_circle$ gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/9/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:hsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-9-Av3uEd/gcc-9-9.4.0/debian/tmp-nvptx/usr,hsa --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```
