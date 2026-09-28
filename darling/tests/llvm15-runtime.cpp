#include <cassert>
#include <cstdio>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> values;
    for (int i=0; i<1024; ++i) values.push_back(std::to_string(i));
    assert(values.at(999)=="999");
    bool caught=false;
    try { throw std::runtime_error("merged runtime exception"); }
    catch (const std::exception& e) {
        caught=std::string(e.what())=="merged runtime exception";
    }
    assert(caught);
    caught=false;
    try { (void)values.at(4096); }
    catch (const std::out_of_range&) { caught=true; }
    assert(caught);
    const auto path=std::filesystem::path("/usr")/"lib";
    assert(std::filesystem::is_directory(path));
    size_t entries=0;
    for (const auto& entry: std::filesystem::directory_iterator(path)) {
        assert(!entry.path().empty());
        ++entries;
    }
    assert(entries>0);
    puts("PASS: merged libcxx allocation, exception RTTI and filesystem iteration");
}
