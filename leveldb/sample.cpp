#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <leveldb/db.h>
using namespace std;

int main(void)
{
    leveldb::DB *db;
    leveldb::Options options;
    // create the db if missing
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, "data", &db);
    assert(status.ok());
    
    // Add 10 records (key value pair) to the database
    leveldb::WriteOptions writeOptions;
    for (int i = 0; i < 10; ++i) {
        ostringstream keyStream;
        keyStream << "Key " << i;
        
        ostringstream valueStream;
        valueStream << "Value: " << i;
        
        db->Put(writeOptions, keyStream.str(), valueStream.str());
    }

    // Iterate over each item in the database and print them
    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    
    for (it->SeekToFirst(); it->Valid(); it->Next())
        cout << it->key().ToString() << " : " << it->value().ToString() << endl;
    
    assert(it->status().ok());
    delete it;
    
    // Close the database
    delete db;

    return 0;
}
