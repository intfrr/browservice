#include "temp_dir.hpp"

#include <sys/stat.h>
#include <unistd.h>

TempDir::TempDir(CKey) {
    char path[] = "/tmp/browservicetmp_XXXXXX";
    CHECK(mkdtemp(path) != nullptr);
    path_ = path;
}

TempDir::~TempDir() {
    if(rmdir(path_.c_str())) {
        LOG(WARNING) << "Deleting temporary directory " << path_ << " failed";
    }
}

const string& TempDir::path() {
    return path_;
}
