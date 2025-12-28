// 0-base
/* center i: radius z[i * 2 + 1] / 2
   center i - 1, i: radius z[i * 2] / 2
   both aba, abba have radius 2 */
vector<int> Manacher(string &tmp) {
  string s = "%";
  int m = 0, r = 0;
  for (char c : tmp) s.push_back(c), s.push_back('%');
  vector<int> z(s.size());
  for (int i = 0; i < s.size(); ++i) {
    z[i] = r > i ? min(z[2 * m - i], r - i) : 1;
    while (i - z[i] >= 0 && i + z[i] < s.size() 
           && s[i + z[i]] == s[i - z[i]]) ++z[i];
    if (z[i] + i > r) r = z[i] + i, m = i;
  }
  return z;
}
