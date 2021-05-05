#include <iostream>
#include <fstream>
#include <string>
#include "rpq.h"
#include "schrage.h"

using namespace std;

int main()
{
    string s;
    int cmax, pmtn;

    ifstream file("data.txt");
    for (int f = 0; f <= 8; f++)
    {
        while (s != "data.00" + to_string(f) + ":") file >> s;

        int n = 0;
        file >> n;

        QueueTask queue;
        Task* task = new Task[n];
        for (int i = 0; i < n; i++)
        {
            file >> task[i].r;
            file >> task[i].p;
            file >> task[i].q;
            task[i].order = i + 1;
            queue.push(task[i]);
        }

        cmax = schrage(queue, task);
        pmtn = schrage_pmtn(queue);

        cout << "Task " << f << endl;
        cout << endl;
        cout << "schrpmtn:\n" << pmtn << endl;
        cout << endl;
        cout << "schr:\n" << cmax << endl;
        permutationSchrage(task, n);
        cout << endl << endl;
    }
    return 0;
}