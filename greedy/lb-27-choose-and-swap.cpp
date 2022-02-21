// Given a string of characters
//  atmost one swap can be made -> swap all occurances of char1 to all occurances of char2
// by swapping the char the string should be lexicographically sorted

string chooseandswap(string a) {
    // e.g accbd -> abbcd
    // maintain a set of previously occured items
    set<int> s;
    // insert all the elements in the array
    // as the set is sorted so it will contain the smallest element at the begining

    for (int i = 0; i < a.length(); i++) {
        s.insert(a[i]);
    }
    for (int i = 0; i < a.length(); i++) {
        // erase this element
        // this element has already occured and find the minium element after this element.
        s.erase(a[i]);  // adcba -> {a,b,c,d} -> remove a -> this min is be
        // so find any element in a[] more than b to replace with.
        // if there is no more elements in the set that means nothing less than
        // hence can not be swapped
        if (s.empty()) return a;
        // smaller than a[i] element found
        char A = *s.begin();
        char B = a[i];
        // only change if the element is greator that than next upcomming lower element
        if (A < B) {
            // swap elements as given in the question/
            for (int j = 0; j < a.length(); j++) {
                if (a[j] == A)
                    a[j] = B;
                else if (a[j] == B)
                    a[j] = A;
            }
            break;
        }
    }
    return a;
}