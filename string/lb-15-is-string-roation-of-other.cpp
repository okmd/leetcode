int reverse() {
    if (s1.size() != s2.size()) return false;
    s1 = s1 + s1;
    // highest possible value of type t=-1
    return (s1.find(s2) != string::npos);
}