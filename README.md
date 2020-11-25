# SpicyPP
[QT Setup](documentation/qtSetup.md)

# install Gtests
```
git clone https://github.com/google/googletest.git -b release-1.10.0
cd googletest        # Main directory of the cloned repository.
mkdir build          # Create a directory to hold the build output.
cd build
cmake .              # Generate native build scripts for GoogleTest.
make
sudo make install    # Install in /usr/local/ by default
```
