#include <iostream>

void preOrder(const int *tree, int n, int root) {
    std::cout << root << " ";
    for (int i = 0; i < n; i++)
        if (tree[i] == root)
            preOrder(tree, n, i);
}


void postOrder(const int *tree, int n, int root) {
    for (int i = 0; i < n; i++)
        if (tree[i] == root)
            postOrder(tree, n, i);
    std::cout << root << " ";
}

void inOrder(const int *tree, int n, int root) {
    int id = 0;
    while ((tree[id] != root) && (id < n))
        ++id;
    if (id < n)
        inOrder(tree, n, id);
    std::cout << root << " ";
    if (id < n)
        for (int i = id + 1; i < n; i++)
            if (tree[i] == root)
                inOrder(tree, n, i);
    return;
}

int main() {
    int n;
    int* tree;
    std::cin >> n;
    tree = new int[n];
    for (std::size_t i = 0; i < n; ++i)
        std::cin >> tree[i];
    int root = 0;
    while (tree[root] != -1)
        ++root;
    preOrder(tree, n, root);
    std::cout << std::endl;
    postOrder(tree, n, root);
    std::cout << std::endl;
    inOrder(tree, n, root);
    std::cout << std::endl;
    if (tree)
        delete [] tree;
    return 0;
}