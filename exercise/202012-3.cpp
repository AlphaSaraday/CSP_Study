#include <bits/stdc++.h>
using namespace std;
using gg = unsigned long long;
constexpr gg INF = 2e18;  //表示无穷大
struct File {
    gg size;  //是文件，表示文件大小；否则为0
    gg ld, lr;  //是目录，表示该目录的子文件总大小、后代文件总大小；否则均为0
    gg ldsize, lrsize;  //是目录，表示目录配额和后代配额；否则均为0
    bool isFile;  //是否是文件
    unordered_map<string, File*> child;  //子文件或子目录
    File(gg sz, bool file) : size(sz), isFile(file), ld(INF), lr(INF), ldsize(0), lrsize(0) {}
};
//分割字符串
vector<string> split(const string& s, string c = " ") {
    vector<string> ans;
    for (gg i = 0, j = 0; i < s.size(); i = j + 1) {
        j = s.find(c, i);
        if (j == string::npos) {
            j = s.size();
        }
        ans.push_back(s.substr(i, j - i));
    }
    return ans;
}
//如果path表示文件，返回文件大小；否则返回0
gg fileSize(File* root, const vector<string>& path) {
    for (gg i = 1; i < path.size() and root; i++) {
        root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
    }
    return root and root->isFile ? root->size : 0;
}
//检测path路径是否能创建一个新的文件
bool canCreateFile(File* root, const vector<string>& path, gg sz) {
    for (gg i = 1; i < path.size() and root; i++) {
        if (root->isFile or root->lrsize + sz > root->lr or (i == path.size() - 1 and root->ldsize + sz > root->ld)) {
            return false;
        }
        root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
    }
    return not root or root->isFile;
}
//如果不能成功创建文件，返回false；sz表示此次创建文件的大小
bool createFile(File* root, const vector<string>& path, gg sz) {
    gg curSize = fileSize(root, path);
    sz -= curSize;
    if (not canCreateFile(root, path, sz)) {  // path路径下不能创建文件，返回false
        return false;
    }
    for (gg i = 1; i < path.size() - 1; i++) {
        root->lrsize += sz;
        if (not root->child.count(path[i])) {
            root->child[path[i]] = new File(0, false);
        }
        root = root->child[path[i]];
    }
    root->lrsize += sz, root->ldsize += sz;
    if (not root->child.count(path.back())) {
        root->child[path.back()] = new File(0, true);
    }
    root->child[path.back()]->size += sz;
    return true;
}
//删除文件
void removeFile(File* root, const vector<string>& path) {
    auto r = root;
    for (gg i = 1; i < path.size() and r; i++) {
        r = r->child.count(path[i]) ? r->child[path[i]] : nullptr;
    }
    if (not r) {  //要删除的路径不存在
        return;
    }
    gg sz = r->isFile ? r->size : r->lrsize;
    for (gg i = 1; i < path.size() - 1 and root; i++) {
        root->lrsize -= sz;
        root = root->child[path[i]];
    }
    root->lrsize -= sz;
    if (r->isFile) {
        root->ldsize -= sz;
    }
    root->child.erase(path[path.size() - 1]);
}
//修改配额
bool QFile(File* root, const vector<string>& path, gg ld, gg lr) {
    for (gg i = 1; i < path.size() and root; i++) {
        root = root->child.count(path[i]) ? root->child[path[i]] : nullptr;
    }
    if (not root or root->isFile or root->lrsize > lr or root->ldsize > ld) {
        return false;
    }
    root->lr = lr;
    root->ld = ld;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ld, lr, sz;
    cin >> ni;
    string c, path;
    File* root = new File(0, false);  //表示根目录的结点
    while (ni--) {
        cin >> c >> path;
        auto pathSplit = split(path, "/");
        if (c == "C") {
            cin >> sz;
            cout << (createFile(root, pathSplit, sz) ? "Y" : "N") << "\n";
        }
        else if (c == "R") {
            removeFile(root, pathSplit);
            cout << "Y\n";
        }
        else {
            cin >> ld >> lr;
            ld = ld == 0 ? INF : ld;
            lr = lr == 0 ? INF : lr;
            cout << (QFile(root, pathSplit, ld, lr) ? "Y" : "N") << "\n";
        }
    }
    return 0;
}

//本题因为用不到负数，而string.size()/length()返回值为无符号数，所以定义 gg = unsigned long long 便于比较