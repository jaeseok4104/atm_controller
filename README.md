# ATM Controller


 ## How to use

if you did't install cmake higher then 3.23 version and gtest, gflag and glog, you should install cmake, gtest, gflag and glog.
## Requirement Install script
```
you should login root account  

# Install cmake
cd /tmp && \
wget https://github.com/Kitware/CMake/releases/download/v3.23.0-rc1/cmake-3.23.0-rc1.tar.gz && \
tar -zxvf cmake-3.23.0-rc1.tar.gz  && \
cd cmake-3.23.0-rc1 && \
./bootstrap && \
make -j`(nproc)` && \
make install && \
export PATH=$PATH:/usr/local/bin && \
ldconfig

# Install gflags
cd /tmp/ && \
wget https://github.com/gflags/gflags/archive/v2.2.2.tar.gz && \
tar -zxvf v2.2.2.tar.gz && \
cd gflags-2.2.2/ && \
mkdir build && \
cd build/ && \
cmake -DBUILD_SHARED_LIBS=1 .. && \
make -j`(nproc)` && \
make install && \
ldconfig

# Install glog
cd /tmp && \
wget https://github.com/google/glog/archive/v0.4.0.tar.gz && \
tar -zxvf v0.4.0.tar.gz && \
cd glog-0.4.0/ && \
mkdir build && \
cd build/ && \
cmake -DBUILD_SHARED_LIBS=1 .. && \
make -j`(nproc)` && \
make install && \
ldconfig
```
### build test

```
cd your/git/repository

mkdir build
cd build
cmake -DTEST=1 ..
make -j
```

### Running Test
```
cd your/git/repository
cd build
./atm_controller_atm_interface_test
```
### Result
![image](https://user-images.githubusercontent.com/51950819/225965993-a0eba25b-0b91-4da2-824c-706a5db70c84.png)
