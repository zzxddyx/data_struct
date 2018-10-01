#include "StrBlob.h"

StrBlob::StrBlob()
    :data(make_shared<vector<string>>())
{}

StrBlob::StrBlob(initialization_list<string> il)
    :data(make_shared<vector<string>>(il))
{}

