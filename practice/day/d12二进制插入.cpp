class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        m = m<<j;
        return m|n;
    }
};

