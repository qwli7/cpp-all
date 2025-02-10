#ifndef TABTENNO_H_
#define TABTENNO_H_
#include <string>

using std::string;

class TableTennisPlayer{
private:
    string firstname;
    string lastname;
    bool hasTable;

public:
    TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
    void Name() const;

    //内联函数
    bool HasTable() const {
        return hasTable;
    }
    void ResetTable(bool v) {
        hasTable = v;
    }
        
};

#endif