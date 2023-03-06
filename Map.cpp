#include"map.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

// print a pair
template <typename T1, typename T2>
void print_pair(pair<T1, T2>& p) {
    cout << p.first << ": " << p.second << endl;
}

// print the elements of the map
template<typename T>
void print_map(T& m) {
    if (m.empty()) return;
    for (auto x : m) print_pair(x);
    cout << endl;
}

// print a simple message
void msg(const char* m) { cout << m << endl; }
template <typename T>
void msg(const char* m, const T& v) { cout << m << ": " << v << endl; }

void Map::examples() {

    //Map examples 

    msg("map of strings from initializer list");
    map<string, string> mapstr = { { "George", "Father" }, { "Ellen", "Mother" },
        { "Ruth", "Daughter" }, { "Spike", "Neighbor's Son" } };

    msg("size", mapstr.size());
    msg("get some values");
    msg("George", mapstr["George"]);
    msg("Ellen", mapstr.at("Ellen"));
    msg("Spike", mapstr.find("Spike")->second);
    msg("print_map:");
    print_map(mapstr);

    msg("insert an element");
    mapstr.insert({ "Luke", "Neighbor" });
    msg("size", mapstr.size());
    print_map(mapstr);

    cout << "insert a duplicate:" << endl;
    auto rp = mapstr.insert({ "Luke", "Neighbor" });
    if (rp.second) {
        msg("insert succeeded");
        print_pair(*rp.first);
    }
    else {
        msg("insert failed");
    }
    msg("size", mapstr.size());
    print_map(mapstr);

    msg("find and erase Spike");
    auto it = mapstr.find("Spike");
    if (it != mapstr.end()) {
        msg("found");
        print_pair(*it);
        mapstr.erase(it);
        msg("erased");
    }
    else {
        msg("not found");
    }
    msg("size", mapstr.size());
    print_map(mapstr);

}

void Map::execute()
{
	std::map<int, int> limits = { {25, 53},{54, 73} };
	Context::execute(limits, "Map.cpp");
}