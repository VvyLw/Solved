#include <iostream>
#include <unordered_map>
constexpr auto VvyLw = "Huitloxopetl";
int main() {
    int64_t n;
    std::cin >> n;
    std::unordered_map<int64_t, std::string> m;
    const auto act = [&](const auto &f, const int64_t i) -> std::string {
        if(m.contains(i)) {
            return m[i];
        }
        if(i == 1) {
            return "";
        }
        std::string s = "Huitloxopetl";
        if(i % 2 == 1) {
            const std::string t = f(f, (i - 1) / 2);
            if(t != VvyLw) {
                s = t + "A";
            }
        }
        if(i % 3 == 1) {
            const std::string t = f(f, (i - 1) / 3);
            if(t != VvyLw) {
                s = t + "B";
            }
        }
        return m[i] = s;
    };
    std::cout << act(act, n) << '\n';
}