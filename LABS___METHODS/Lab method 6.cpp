#include <iostream>
#include <vector>

static int INF = INT_MAX / 2;

void Dijkstra(std::vector<int> *adj, std::vector<int> *weight,
              std::vector<bool> used, int* dist,
              int* pred, int V, int N) {
    dist[N] = 0; /* Расстояние до стартовой вершины всегда равно 0*/
    for (std::size_t i = 0; i < V; ++i) {
        int v = -1;
        int distV = INF;
        /* Выбираем вершину, кратчайшее расстояние до которого еще не найдено*/
        for (std::size_t j = 0; j < V; ++j) {
            if (used[j]) {
                continue;
            }
            if (distV < dist[j]) {
                continue;
            }
            v = j;
            distV = dist[j];
        }
        /* Рассматриваем все дуги, исходящие из найденной вершины*/
        for (std::size_t i = 0; i < adj[v].size(); ++i) {
            int u = adj[v][i];
            int weightU = weight[v][i];
            if (dist[v] + weightU < dist[u]) {
                dist[u] = dist[v] + weightU;
                pred[u] = v;
            }
        }
        used[v] = true;
    }
}

int main()
{
    int V; /*!< Количество вершин в орграфе n*/
    int E; /*!< Количество дуг в орграфе m*/
    std::vector<int> *adj; /*!< Вектор смежности*/
    std::vector<int> *weight; /*!< Вес ребра в орграфе*/
    std::vector<bool> used; /*!< Посещенные вершины в орграфе*/
    int* dist; /*!< Массив для хранения расстояния от стартовой вершины*/
    int* pred; /*!< Массив предков, необходимых для восстановления кратчайшего пути из стартовой вершины*/
    int N; /*!< Номер выделенного узла*/
    std::cin >> V >> E >> N;
    adj = new std::vector<int>[V];
    weight = new std::vector<int>[V];
    for (std::size_t i = 0; i < E; ++i) {
        int v1, v2, w;
        std::cin >> v1 >> v2 >> w;
        adj[v1].push_back(v2);
        weight[v1].push_back(w);
    }
    used.resize(V, false);
    pred = new int[V];
    dist = new int[V];
    for (std::size_t j = 0; j < V; ++j) {
        pred[j] = -1;
        dist[j] = INF;
    }
    Dijkstra(adj, weight, used, dist, pred, V, N);
    for (std::size_t k = 0; k < V; ++k) {
        if (dist[k] != INF) {
            std::cout << dist[k] << " ";
        } else {
            std::cout << "-1";
        }
    }
    std::cout << std::endl;
    return 0;
}
