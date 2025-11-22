vector<int> val;
// build
sort(all(val)), val.resize(unique(all(val)) - val.begin());
// index of x
upper_bound(all(val), x) - val.begin();
// max idx <= x
upper_bound(all(val), x) - val.begin();
// max idx < x
lower_bound(all(val), x) - val.begin();
