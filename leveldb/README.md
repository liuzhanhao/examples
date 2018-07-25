# LevelDB Example

Environment: `Ubuntu 14.04`

## Prepare LevelDB

### Download the lastest release of LevelDB

```shell
wget https://github.com/google/leveldb/archive/v1.20.tar.gz
```

### Compile & Build LevelDB
```shell
tar xzvf v1.20.tar.gz
cd leveldb-1.20
make [-j]
```

The built libraries are under the folders `out-shared` and `out-static`.

```shell
# co leveldb header file to /usr/include/
sudo cp -r /include/leveldb/ /usr/include/

# copy LevelDB library to /usr/lib/
sudo cp /leveldb/out-shared/libleveldb.so.1.20 /usr/lib/

# create links
sudo ln -s /usr/lib/libleveldb.so.1.20 /usr/lib/libleveldb.so.1
sudo ln -s /usr/lib/libleveldb.so.1.20 /usr/lib/libleveldb.so

# update library cache
sudo ldconfig
```

## Build & run the sample

```
git clone https://github.com/liuzhanhao/leveldb_example.git

cd leveldb_example && make
./sample

# check the output database
ls data
```

