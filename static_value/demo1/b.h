

void bAdd();
int bV();

// 本文件可见，不能在main里调用
static void f1();

namespace b {
    static void f1();
    void test();
}
