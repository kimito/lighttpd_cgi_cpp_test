# C++ cgi test on lighttpd

## install deps
```sh
sudo install cmake build-essential lighttpd libcgicc-dev libopencv-dev
```

## build the app
```sh
mkdir build && cd build
cmake ..
make
```

## deploy the app
```sh
cp ./api_app ../html/
```

## run the lighttpd for test
```sh
cd html/
/usr/sbin/lighttpd -D -f ../lighttpd.conf
```