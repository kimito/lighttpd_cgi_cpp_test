# C++ cgi test on lighttpd

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
/usr/sbin/lighttpd -D -f ./lighttpd.conf
```