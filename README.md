# semi3
Семинар 3

**Условие задачи**

<img width="661" alt="image" src="https://github.com/user-attachments/assets/4abb2c63-38d1-4710-bda1-fa9b6d6ec6b3" />

**Скриншоты с аккаунта**

<img width="1512" alt="Снимок экрана 2025-04-20 в 17 29 14" src="https://github.com/user-attachments/assets/f3039010-0f38-4aef-bbaf-e9ad65f5f58e" />

<img width="1512" alt="Снимок экрана 2025-04-20 в 17 29 29" src="https://github.com/user-attachments/assets/f6ab4f8b-a36a-4fc5-a75a-6d4f17db4e4d" />

<img width="1512" alt="Снимок экрана 2025-04-20 в 17 29 35" src="https://github.com/user-attachments/assets/acbfb8bd-23b3-4d56-bc1c-0b84294ffb89" />

**Реализация кода**

### Описание реализации алгоритма

**Структура данных**
Tree - структура для хранения дерева и информации о размерах поддеревьев.
Поле connections: вектор векторов целых чисел, представляющий список смежности дерева.
Поле sizes: вектор целых чисел для хранения размеров поддеревьев каждой вершины.

**Функции:**
1. countSizes(Tree& tree, int current, int parent)`ъ:
   Рекурсивно вычисляет размер поддерева для вершины current.
   Инициализирует размер текущей вершины как 1.
   Для каждого соседа вершины :
   Рекурсивно вызывает себя для соседа.
   Добавляет размер поддерева соседа к размеру текущей вершины.

2. main():
   Настраивает ускорение ввода/вывода.
   Считывает количество вершин n.
   Инициализирует структуру Tree, выделяя память под connections и sizes.
   Считывает рёбра дерева и заполняет список смежности.
   Запускает подсчёт размеров поддеревьев, начиная с вершины 1.
   Выводит результаты - размеры поддеревьев для всех вершин.

**Алгоритм:**
Основан на обходе дерева в глубину (DFS).
Для каждой вершины рекурсивно вычисляется размер её поддерева как сумма размеров поддеревьев всех её дочерних вершин + 1 (сама вершина).
Оптимален по времени (O(n)) и памяти (O(n)).

[md.md](https://github.com/user-attachments/files/19825981/md.md)
# Лабораторная работа 3: Подсчёт размеров поддеревьев

Этот репозиторий содержит решение задачи подсчёта размеров поддеревьев в дереве.

## Исходный код
Основной код программы находится в файле [информатика_ЛР3.cpp](./информатика_ЛР3.cpp).

### Содержание файла `информатика_ЛР3.cpp`:
```cpp
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
    tree.sizes[current] = 1;
    
    for (int neighbor : tree.connections[current]) {
        if (neighbor != parent) {
            countSizes(tree, neighbor, current);
            tree.sizes[current] += tree.sizes[neighbor];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    Tree tree;
    tree.connections.resize(n + 1);
    tree.sizes.resize(n + 1, 0);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree.connections[a].push_back(b);
        tree.connections[b].push_back(a);
    }
    
    countSizes(tree, 1, -1);
    
    for (int i = 1; i <= n; ++i) {
        cout << tree.sizes[i] << " ";
    }
    cout << endl;
    
    return 0;
}
