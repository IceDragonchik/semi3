#include <iostream>
#include <vector>

using namespace std;

// Структура для хранения дерева
struct Tree {
    vector<vector<int>> connections; // Кто с кем связан 
    vector<int> sizes;              // Размер поддерева для каждой вершины
};

// Функция для подсчёта размеров поддеревьев
void countSizes(Tree& tree, int current, int parent) {
    // Начинаем с 1 
    tree.sizes[current] = 1;
    
    // Перебираем всех соседей
    for (int neighbor : tree.connections[current]) {
        // Не идём обратно к родителю
        if (neighbor != parent) {
            // Рекурсивно считаем для соседа
            countSizes(tree, neighbor, current);
            // Добавляем размер соседа к текущей вершине
            tree.sizes[current] += tree.sizes[neighbor];
        }
    }
}

int main() {
    // Ускорение ввода/вывода
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n; // Читаем количество вершин
    
    Tree tree;
    tree.connections.resize(n + 1); // Нумерация с 1 до n
    tree.sizes.resize(n + 1, 0);    // Изначально все размеры 0
    
    // Читаем рёбра
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        // Записываем связь в обе стороны
        tree.connections[a].push_back(b);
        tree.connections[b].push_back(a);
    }
    
    // Запускаем подсчёт с вершины 1 
    countSizes(tree, 1, -1);
    
    // Выводим результаты
    for (int i = 1; i <= n; ++i) {
        cout << tree.sizes[i] << " ";
    }
    cout << endl;
    
    return 0;
}